#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPen>
#include <QPainter>
#include <QDebug>
#include <iostream>
class CustomTabStyle : public QProxyStyle
{
public:
    QSize sizeFromContents(ContentsType type, const QStyleOption *option,
        const QSize &size, const QWidget *widget) const
    {
        QSize s = QProxyStyle::sizeFromContents(type, option, size, widget);
        if (type == QStyle::CT_TabBarTab) {
            s.transpose();
            s.rwidth() = 90; // 设置每个tabBar中item的大小
            s.rheight() = 44;
        }
        return s;
    }

    void drawControl(ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
    {
        if (element == CE_TabBarTabLabel) {
            if (const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(option)) {
                QRect allRect = tab->rect;

                if (tab->state & QStyle::State_Selected) {
                    painter->save();
                    painter->setPen(0x89cfff);
                    painter->setBrush(QBrush(0x89cfff));
                    painter->drawRect(allRect.adjusted(6, 6, -6, -6));
                    painter->restore();
                }
                QTextOption option;
                option.setAlignment(Qt::AlignCenter);
                if (tab->state & QStyle::State_Selected) {
                    painter->setPen(0xf8fcff);
                }
                else {
                    painter->setPen(0x5d5d5d);
                }

                painter->drawText(allRect, tab->text, option);
                return;
            }
        }

        if (element == CE_TabBarTab) {
            QProxyStyle::drawControl(element, option, painter, widget);
        }
    }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabWidget->tabBar()->setStyle(new CustomTabStyle);
    //setWindowState(Qt::WindowMaximized);//max

    /*camera*/
    timer = new QTimer(this);
    timer->stop();
    connect(timer, SIGNAL(timeout()), this, SLOT(readFrame()));  // 时间到，读取当前摄像头信息
    recording = false;
    videocapture = new VideoCapture(0);
    videocapture->set(CAP_PROP_FRAME_WIDTH,1920);
    videocapture->set(CAP_PROP_FRAME_HEIGHT,1080);
    std::cout<<"width"<<videocapture->get(CAP_PROP_FRAME_WIDTH)<<std::endl;
    std::cout<<"height"<<videocapture->get(CAP_PROP_FRAME_HEIGHT)<<std::endl;

    timer->start(33);

    /*Databse*/
    db = new Database();
    getDB();
    /*const QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    for (const QCameraInfo &cameraInfo : cameras) {
        if (cameraInfo.deviceName() == "mycamera")
            camera = new QCamera(cameraInfo);
    }*/

    //opencv test
//    Mat src = imread("C:/Users/leoqi/OneDrive/Pictures/a.png");
//    Mat img;
//    cvtColor(src, img, COLOR_BGR2RGB);
//    ui->label->setPixmap(QPixmap::fromImage(QImage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888)));



//    camera = new QCamera(this); //系统摄像设备（摄像头）
//    viewfinder = new QCameraViewfinder(this);//摄像取景器部件
//    imageCapture = new QCameraImageCapture(camera); //截图部件  指定父对象camera 依赖摄像头截图

//    camera->setViewfinder(viewfinder);//申请好的取景部件给摄像头
//    camera->start();//运行摄像头

//    注意：
//    ImageView是 horizontalLayout 类的对象
//    ImageCapture是Lable 类的对象
//    ui->ImageView ->addWidget(viewfinder);//摄像头取到的景放入ImageView
//    ui->ImageCapture->setScaledContents(true); //让图片适应ImageCapture的大小

//   horizontalLayout 类有捕捉图像的功能
//    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(displayImage(int,QImage)));
//    connect(ui->captureButton, SIGNAL(clicked()), this, SLOT(captureImage()));
//    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveImage()));
    write.open("test.avi", VideoWriter::fourcc('M', 'P', '4', '2'), 30.0, Size(1920, 1080), true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage MainWindow::cvMat2QImage(const Mat& mat)    // Mat 改成 QImage
{
    if (mat.type() == CV_8UC1)                  // 单通道
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        image.setColorCount(256);               // 灰度级数256
        for (int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        uchar *pSrc = mat.data;                 // 复制mat数据
        for (int row = 0; row < mat.rows; row++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }

    else if (mat.type() == CV_8UC3)             // 3通道
    {
        const uchar *pSrc = (const uchar*)mat.data;         // 复制像素
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);    // R, G, B 对应 0,1,2
        return image.rgbSwapped();              // rgbSwapped是为了显示效果色彩好一些。
    }
    else if (mat.type() == CV_8UC4)
    {
        const uchar *pSrc = (const uchar*)mat.data;         // 复制像素
                                                            // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);        // B,G,R,A 对应 0,1,2,3
        return image.copy();
    }
    else
    {
        return QImage();
    }
}

Mat MainWindow::QImage2cvMat(QImage image)           // QImage改成Mat
{
    Mat mat;
    switch (image.format())
    {
    case QImage::Format_ARGB32:
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32_Premultiplied:
        mat = Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
        break;
    case QImage::Format_RGB888:
        mat = Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
        cv::cvtColor(mat, mat, COLOR_BGR2RGB);
        break;
    case QImage::Format_Indexed8:
        mat = Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
        break;
    }
    return mat;
}



void MainWindow::on_captureButton_clicked()
{
//    if(recording)timer->start(33);
//        else timer->stop();
        recording = !recording;

}

void MainWindow::readFrame()
{
    videocapture->read(matFrame);
    if(recording){
        write.write(matFrame);
        ui->recordingLabel->setVisible(true);
        ui->recordingLabel->setStyleSheet("QLabel { background-color : red; color : blue; }");
    }else{
        ui->recordingLabel->setVisible(false);
    }
    QImage imgg = cvMat2QImage(matFrame);//.scaled(ui->ImageCapture->size(),Qt::KeepAspectRatio);
    QPixmap qpixmap = QPixmap::fromImage(imgg);
    int width = ui->ImageCapture->width();
    int height = ui->ImageCapture->height();
    QPixmap fitpixmap = qpixmap.scaled(width, height, Qt::KeepAspectRatio, Qt::SmoothTransformation); //按比例缩放
    // 将图片显示到label上
    //ui->ImageCapture->setScaledContents(true);
    ui->ImageCapture->setPixmap(fitpixmap);

}

void MainWindow::buttonClose()
{
    timer->stop();         // 停止读取数据。
    videocapture->release();
    //exit
    QApplication* app;
    app->exit(0);
}
//void MainWindow::on_saveButton_clicked()
//{
//    QString fileName=QFileDialog::getSaveFileName(this, tr("save file"), "../", tr("Images (*.png *.xpm *.jpg)"));
//            //返回的是文件路径字符串  ， 第四个参数是设置可以保存的类型
//    if(fileName.isEmpty()) {
//            return;
//    }
//    const QPixmap* pixmap=ui->ImageCapture->pixmap();//使用一种画布指向图片
//    if(pixmap) {
//            pixmap->save(fileName); //保存画布
//    }

//}

//void MainWindow::displayImage(int , QImage image)
//{
//        ui->ImageCapture->setPixmap(QPixmap::fromImage(image));
//}

void MainWindow::getDB(){
    sqldb = QSqlDatabase::database("MyConnect");
    //qDebug()<<sqldb.open();
    //QSqlQuery query(sqldb);

}

//void MainWindow::setTreeWidget(QTreeWidget rec){
//    record->rec;
//}

//QTreeWidget MainWindow::getTreeWidget(){
//    return record;
//}


void MainWindow::setUsername(QString un){
    Username = un;

    QSqlQuery query(sqldb);

    if(sqldb.open()){
    QString queryscript = "SELECT * FROM Doctors WHERE username =";
    queryscript += "'"+Username+"'";
    //query.exec(queryscript);

    if(!query.exec(queryscript)){
        //qDebug()<<query.lastError().text();
        QMessageBox::information(this,"Failed","query.exec not running");
    }else{
        if(query.next()){
            //qDebug() << "Doctor Name: " <<query.value(4).toString();
            ui->UI_DocName->setText(query.value(3).toString());
            setdID(query.value(0).toString());
            retreivePatients();
            //setTreeWidget();

        }else{
            printf("Doctor Name not found");
            }
    }
    }else{
        printf("open sqldb failed");
    }

}

void MainWindow::retreivePatients(){
        QSqlQuery query(sqldb);

        ui->treeWidget->setColumnCount(3);
        QStringList labels;
        labels << "First Name" << "Last Name" << "Date of Birth";
        ui->treeWidget->setHeaderLabels(labels);

        if(sqldb.open()){
        QString queryscript = "SELECT * FROM Patients WHERE docID =";
        queryscript += dID;
        //query.exec(queryscript);

        if(!query.exec(queryscript)){
            //qDebug()<<query.lastError().text();
            QMessageBox::information(this,"Failed","query.exec not running");
        }else{
            while(query.next()){
                //qDebug() << "Patient Name: " <<query.value(1).toString();

                QTreeWidgetItem *root1 = new QTreeWidgetItem(ui->treeWidget);
                root1->setText(0,query.value(1).toString());
                root1->setText(1,query.value(2).toString());
                root1->setText(2,query.value(3).toString());
                ui->treeWidget->addTopLevelItem(root1);

                retreiveRecords(query.value(0).toString(), root1);

            }
        }
        }else{
            printf("open sqldb failed");
        }
        //setTreeWidget(ui->treeWidget);
}

void MainWindow::retreiveRecords(QString id, QTreeWidgetItem *root){
    QSqlQuery query(sqldb);

    if(sqldb.open()){
        QString queryscript1 = "SELECT * FROM Records WHERE pID =";
        queryscript1 += id;
        if(!query.exec(queryscript1)){
            //qDebug()<<query.lastError().text();
            QMessageBox::information(this,"Failed","retreive record query not running");
        }else{
            while(query.next()){
                QTreeWidgetItem *child1 = new QTreeWidgetItem();
                child1->setText(0,"Record#"+query.value(0).toString());
                child1->setText(1,"Test Location: "+query.value(1).toString());
                child1->setText(2,"Test Date: "+query.value(2).toString());
                root->addChild(child1);
            }
        }
    }
}

void MainWindow::setdID(QString id){
    dID = id;
}

void MainWindow::on_searchBtn_clicked()
{   QTreeWidgetItem *item;
    //item = ui->treeWidget->topLevelItem(0);
    QString firstName = ui->hfirstName->text();
    QString lastName = ui->hlastName->text();
    QString dob = ui->hDOB->text();
    //qDebug()<<ui->treeWidget->topLevelItemCount();
    if(firstName == NULL && lastName == NULL && dob == NULL){
        delete item;
        retreivePatients();
    }else{
        if(firstName!=NULL){
        for (int i=0;i<ui->treeWidget->topLevelItemCount();i++){
            item = ui->treeWidget->topLevelItem(i);
            qDebug()<<item->text(0);
            if(item->text(0)!=firstName){
                int count = item->childCount();
                if(count == 0){
                delete item;
                --i;
                }else{
                    for(int j =0;j<count;j++){
                        QTreeWidgetItem *childItem = item->child(j);
                        delete childItem; //->parent()-?takeChild(ui->treeWidget->currentIndex().row());
                    }
                    delete item;
                    --i;
                }
            }
        }
        }
        if(lastName!=NULL){
            for (int i=0;i<ui->treeWidget->topLevelItemCount();i++){
                item = ui->treeWidget->topLevelItem(i);
                qDebug()<<item->text(1);
                if(item->text(1)!=lastName){
                    int count = item->childCount();
                    if(count == 0){
                    delete item;
                    --i;
                    }else{
                        for(int j =0;j<count;j++){
                            QTreeWidgetItem *childItem = item->child(j);
                            delete childItem; //->parent()-?takeChild(ui->treeWidget->currentIndex().row());
                        }
                        delete item;
                        --i;
                    }
                }
            }
        }
        if(dob!=NULL){
            for (int i=0;i<ui->treeWidget->topLevelItemCount();i++){
                item = ui->treeWidget->topLevelItem(i);
                qDebug()<<item->text(2);
                if(item->text(2)!=dob){
                    int count = item->childCount();
                    if(count == 0){
                    delete item;
                    --i;
                    }else{
                        for(int j =0;j<count;j++){
                            QTreeWidgetItem *childItem = item->child(j);
                            delete childItem; //->parent()-?takeChild(ui->treeWidget->currentIndex().row());
                        }
                        delete item;
                        --i;
                    }
                }
            }
        }

}

}



void MainWindow::on_resetBtn_clicked()
{
    ui->hfirstName->setText("");;
    ui->hlastName->setText("");;
    QTreeWidgetItem *item;
    for (int i=0;i<ui->treeWidget->topLevelItemCount();i++){
        item = ui->treeWidget->topLevelItem(i);
        int count = item->childCount();
        if(count == 0){
            delete item;
            --i;
         }else{
             for(int j =0;j<count;j++){
                 QTreeWidgetItem *childItem = item->child(j);
                 delete childItem; //->parent()-?takeChild(ui->treeWidget->currentIndex().row());
              }
              delete item;
              --i;
           }
        }

    retreivePatients();

}

void MainWindow::on_addBtn_clicked()
{

}

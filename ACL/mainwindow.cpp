#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPen>
#include <QPainter>
#include <QDebug>

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
    timer->start(33);

    /*Databse*/
    db = new Database();
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
    write.open("test.avi", VideoWriter::fourcc('M', 'P', '4', '2'), 30.0, Size(640, 480), true);

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

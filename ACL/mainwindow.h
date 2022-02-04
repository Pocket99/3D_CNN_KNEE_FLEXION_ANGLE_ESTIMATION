#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QTabBar>
#include <QProxyStyle>
#include <QPainter>
#include <QStyleOption>
#include <QCamera>
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QFileDialog>
#include <QTimer>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QString>
#include <userinfo.h>
#include "opencv2/opencv.hpp"
#include "database.h"
#include <QTreeWidgetItem>
#include <QMessageBox>
#include <ActiveQt>
using namespace cv;
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setUsername(QString);
    void getDB();
    void retreivePatients();
    void retreiveRecords(QString,QTreeWidgetItem*);
    void setdID(QString);
    void setTreeWidget(QTreeWidget);
    void initPatientList();
    QTreeWidget getTreeWidget();
    void clearTreeWidget();
    inline bool exists_file (const std::string& name);

private slots:
//    void displayImage(int , QImage image);

    void on_captureButton_clicked();

//    void on_saveButton_clicked();

    void readFrame();
    void buttonClose();
    void on_searchBtn_clicked();


    void on_addBtn_clicked();

    void on_resetBtn_clicked();

    void on_patientList_activated(int index);

    void on_addRecord_clicked();

    void on_refreshBtn_clicked();

    void on_deleteBtn_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_playOutput_clicked();

    void outputFrame();
private:
    Ui::MainWindow *ui;
    QImage cvMat2QImage(const Mat & mat);
    Mat QImage2cvMat(QImage image);
    QTimer *timer;
    QTimer* playTimer;
    bool recording;
    VideoCapture *videocapture;
    VideoWriter write;
    Mat matFrame;
    QTreeWidget record;
    QString Username;
    QString dID;
    QSqlDatabase sqldb;
    QAxScriptManager* scrpt_mgr;
    QAxScript* main_scrpt;
    VideoCapture outputVideo;
    Mat sourceFrame;

//    QCamera *camera;
//    QCameraViewfinder *viewfinder;
//    QCameraImageCapture *imageCapture;
};
#endif // MAINWINDOW_H

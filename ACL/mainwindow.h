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
#include <QSqlDatabase>
#include <QDebug>
#include <QString>
#include <userinfo.h>
#include "opencv2/opencv.hpp"
#include "database.h"

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

private slots:
//    void displayImage(int , QImage image);

    void on_captureButton_clicked();

//    void on_saveButton_clicked();

    void readFrame();
    void buttonClose();
private:
    Ui::MainWindow *ui;
    QImage cvMat2QImage(const Mat & mat);
    Mat QImage2cvMat(QImage image);

    QTimer *timer;
    bool recording;
    VideoCapture *videocapture;
    VideoWriter write;
    Mat matFrame;
    Database *db;
//    QCamera *camera;
//    QCameraViewfinder *viewfinder;
//    QCameraImageCapture *imageCapture;
};
#endif // MAINWINDOW_H

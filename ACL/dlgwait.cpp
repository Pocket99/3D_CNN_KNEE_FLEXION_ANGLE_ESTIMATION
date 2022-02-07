#include "dlgwait.h"
#include "ui_dlgwait.h"
#include <QMovie>
#include <QDesktopWidget>

DlgWait::DlgWait(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgWait)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);//无边框

      setAttribute(Qt::WA_TranslucentBackground);//背景透明

      //屏幕居中显示

      int frmX = width();

      int frmY = height();

      QDesktopWidget w;

      int deskWidth = w.width();

      int deskHeight = w.height();

      QPoint movePoint(deskWidth / 2 - frmX / 2, deskHeight / 2 - frmY / 2);

      move(movePoint);

      //加载gif图片

      QMovie *movie = new QMovie("loading1.gif");

      ui->lbl_gif->setMovie(movie);

      movie->start();
}

DlgWait::~DlgWait()
{
    delete ui;
}

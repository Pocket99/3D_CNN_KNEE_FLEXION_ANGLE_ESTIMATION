#include "outputvideo.h"
#include "ui_outputvideo.h"

OutputVideo::OutputVideo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OutputVideo)
{
    ui->setupUi(this);
}

OutputVideo::~OutputVideo()
{
    delete ui;
}

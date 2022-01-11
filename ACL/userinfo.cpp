#include "userinfo.h"
#include "ui_userinfo.h"
#include "mainwindow.h"
UserInfo::UserInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserInfo)
{
    ui->setupUi(this);
}

UserInfo::~UserInfo()
{
    delete ui;
}

void UserInfo::on_NameEdit_copyAvailable(bool b)
{

}


void UserInfo::on_pushButton_clicked()
{

}


void UserInfo::on_backButton_clicked()
{
    MainWindow * father = new MainWindow();
    this->close();
    father->show();
}


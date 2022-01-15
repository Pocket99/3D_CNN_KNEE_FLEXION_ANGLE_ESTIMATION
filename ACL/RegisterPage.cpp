#include "registerpage.h"
#include "ui_RegisterPage.h"

RegisterPage::RegisterPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterPage)
{
    ui->setupUi(this);



}

RegisterPage::~RegisterPage()
{
    delete ui;
}

void RegisterPage::on_loginBtn_clicked()
{

}


void RegisterPage::on_registerBtn_clicked()
{

}


void RegisterPage::on_label_4_linkActivated(const QString &link)
{

}


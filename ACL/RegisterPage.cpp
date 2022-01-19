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
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","MyConnect");
    db.setHostName("sh-cynosdbmysql-grp-7530641o.sql.tencentcdb.com");//IP address
    db.setPort(29339);
    db.setDatabaseName("COEN490");
    db.setUserName("root");
    db.setPassword("Coen_490");

    QString username = ui->loginUsername->text();
    QString password = ui->loginPassword->text();

    if(username==NULL || password==NULL){
        QMessageBox::information(this,"Failed","Login Failed. Please Enter Username and Password.");
    }
    else{
    if(db.open()){

        QSqlQuery query(QSqlDatabase::database("MyConnect"));

        query.prepare(QString("SELECT * FROM Doctors WHERE username = :username AND password =:password"));

        query.bindValue(":username",username);
        query.bindValue(":password",password);

        if(!query.exec()){
            QMessageBox::information(this,"Failed","Login Query Failed To Execute");
        }
        else {
            if(query.next()){
//                QString usernameFromDB = query.value(1).toString();
//                QString passwordFromDB = query.value(2).toString();
//                if(usernameFromDB == username && passwordFromDB == password){
                    QMessageBox::information(this,"Success","Login Success");
                    ui->loginUsername->setText("");
                    ui->loginPassword->setText("");
                    hide();
                    mw = new MainWindow(this);
                    mw -> show();
                }
                else {
                    QMessageBox::information(this,"Failed","Login Failed. Invalide Username or Password");
                }

        }

    }else {
        QMessageBox::information(this,"Not Connected","Database Connected fail");
    }
}


}


void RegisterPage::on_registerBtn_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("sh-cynosdbmysql-grp-7530641o.sql.tencentcdb.com");//IP address
    db.setPort(29339);
    db.setDatabaseName("COEN490");
    db.setUserName("root");
    db.setPassword("Coen_490");
    QString username = ui->username->text();
    QString password = ui->password->text();
    QString firstname = ui->firstName->text();
    QString lastname = ui->lastName->text();

    if(username==NULL || password==NULL || firstname==NULL || lastname==NULL){
        QMessageBox::information(this,"Not Inserted","Please Provide Required Infomation");
    }
    else{
    if(db.open()){


        QSqlQuery qry;
        qry.prepare("INSERT INTO Doctors (username,password,dFirstName,dLastName) VALUES (:username,:password,:firstname,:lastname)");
        qry.bindValue(":username",username);
        qry.bindValue(":password",password);
        qry.bindValue(":firstname",firstname);
        qry.bindValue(":lastname",lastname);

        if(qry.exec()){
            QMessageBox::information(this,"Inserted","Register Success");
            ui->username->setText("");
            ui->username->setPlaceholderText("Username");
            ui->password->setText("");
            ui->password->setPlaceholderText("Password");
            ui->firstName->setText("");
            ui->firstName->setPlaceholderText("First Name");
            ui->lastName->setText("");
            ui->lastName->setPlaceholderText("Last Name");

        }else {
            QMessageBox::information(this,"Not Inserted","Data Inserted failed");
        }
    }
    else{
        QMessageBox::information(this,"Not Connected","Database Connected fail");
    }
    }
}


void RegisterPage::on_label_4_linkActivated(const QString &link)
{

}





#include "registerpage.h"
#include "ui_RegisterPage.h"

RegisterPage::RegisterPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterPage)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QMYSQL","MyConnect");
    db.setHostName("sh-cynosdbmysql-grp-7530641o.sql.tencentcdb.com");//IP address
    db.setPort(29339);
    db.setDatabaseName("COEN490");
    db.setUserName("root");
    db.setPassword("Coen_490");
}

RegisterPage::~RegisterPage()
{
    delete ui;
}

void RegisterPage::on_loginBtn_clicked()
{

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

//                    ui->loginUsername->setText("");
//                    ui->loginPassword->setText("");
                    mw.getDB();
                    mw.setUsername(username);
                    mw.initPatientList();
                    //QMessageBox::information(this,"Success","Login Success");
                    hide();
                    mw.show();


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

    QString username = ui->username->text();
    QString password = ui->password->text();
    QString firstname = ui->firstName->text();
    QString lastname = ui->lastName->text();
    QString gender = "";
    QCheckBox *maleCheckBox = ui->maleCheckBox;
    QCheckBox *femaleCheckBox = ui->femaleCheckBox;
    QString email = ui->rEmail->text();
    QString DOB = ui->rDOB->text();
    QString phone = ui->rPhoneNum->text();
    QString address = ui->rAddress->text();

    if(maleCheckBox->isChecked() && femaleCheckBox->isChecked()){
        maleCheckBox->setChecked(false);
        femaleCheckBox->setChecked(false);
        QMessageBox::information(this,"Register Failed","Please Select Only One Gender.");
    }
    else{
        if(maleCheckBox->isChecked()){
            gender = "Male";
        }
        else{
            gender = "Female";
        }

        if(username==NULL || password==NULL || firstname==NULL || lastname==NULL){
            QMessageBox::information(this,"Register Failed","Please Provide Required Infomation");
        }
        else{
            if(db.open()){
                QSqlQuery check(QSqlDatabase::database("MyConnect"));
                QSqlQuery qry(QSqlDatabase::database("MyConnect"));
                check.prepare(QString("SELECT * FROM Doctors WHERE username = :username"));
                check.bindValue(":username",username);
                if(!check.exec()){
                    QMessageBox::information(this,"Failed","Register check Query Failed To Execute");
                }
                else {
                    if(check.next()){
                        QMessageBox::information(this,"Register Failed","Username already in used");
                        cleanRegUI();
                    }
                    else{

                    qry.prepare("INSERT INTO Doctors (username,password,dFirstName,dLastName,dGender,dEmail,dDOB,dPhone,dAddress) VALUES (:username,:password,:firstname,:lastname,:gender,:email,:DOB,:phone,:address)");
                    qry.bindValue(":username",username);
                    qry.bindValue(":password",password);
                    qry.bindValue(":firstname",firstname);
                    qry.bindValue(":lastname",lastname);
                    qry.bindValue(":gender",gender);
                    qry.bindValue(":email",email);
                    qry.bindValue(":DOB",DOB);
                    qry.bindValue(":phone",phone);
                    qry.bindValue(":address",address);


                        if(qry.exec()){
                            QMessageBox::information(this,"Inserted","Register Success");
                            cleanRegUI();

                        }else {
                            QMessageBox::information(this,"Not Inserted","Data Inserted failed");
                        }
                    }
                }
            }
            else{
                QMessageBox::information(this,"Not Connected","Database Connected fail");
            }
        }
    }

}


void RegisterPage::on_label_4_linkActivated(const QString &link)
{

}

void RegisterPage::cleanRegUI()
{
    ui->username->setText("");
    ui->username->setPlaceholderText("Username");
    ui->password->setText("");
    ui->password->setPlaceholderText("Password");
    ui->firstName->setText("");
    ui->firstName->setPlaceholderText("First Name");
    ui->lastName->setText("");
    ui->lastName->setPlaceholderText("Last Name");
    QCheckBox *maleCheckBox = ui->maleCheckBox;
    QCheckBox *femaleCheckBox = ui->femaleCheckBox;
    maleCheckBox->setChecked(false);
    femaleCheckBox->setChecked(false);
    ui->rEmail->setText("");
    ui->rEmail->setPlaceholderText("Email Address");
    ui->rDOB->setText("");
    ui->rDOB->setPlaceholderText("Date of Birth (YYYY-MM-DD)");
    ui->rPhoneNum->setText("");
    ui->rPhoneNum->setPlaceholderText("Phone Number");
    ui->rAddress->setText("");
    ui->rAddress->setPlaceholderText("Address");

}



#include "database.h"

Database::Database()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("mydatabase");//IP address
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("root");

    if(db.open()){
        QString str("Database connect success");
        qDebug()<<str;
    }else{
        QString str("Database connect success");
        qDebug()<<str;
    }
}

void Database::insertDoctor( QString doctor_name, QString password)
{
    QString sql = QString("insert into doctor value (%1,'%2');").arg(doctor_name).arg(password);
    if(query.exec(sql)){
        QString str("insert successs");
        qDebug()<<str;
    }else{
        QString str("insert failed");
        qDebug()<<str;
    }
}

void Database::insertPatient(QString patient_name, QString birth)
{
    QString sql = QString("insert into doctor value (%1,'%2');").arg(patient_name).arg(birth);
    if(query.exec(sql)){
        QString str("insert successs");
        qDebug()<<str;
    }else{
        QString str("insert failed");
        qDebug()<<str;
    }
}

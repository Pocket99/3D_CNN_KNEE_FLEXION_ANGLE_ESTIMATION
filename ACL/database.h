#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QDebug>
#include <QString>
#include <QSqlQuery>

class Database
{
public:
    Database();
    ~Database();
    void insertDoctor(QString, QString);
    void insertPatient(QString, QString);

private:
    QSqlDatabase db;
    QSqlQuery query;
};

#endif // DATABASE_H

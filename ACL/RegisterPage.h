#ifndef REGISTERPAGE_H
#define REGISTERPAGE_H

#include <QSqlDatabase>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDialog>
#include <QtSql>
#include <dlgwait.h>

#include <mainwindow.h>

namespace Ui {
class RegisterPage;
}

class RegisterPage : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterPage(QWidget *parent = nullptr);
    ~RegisterPage();
    void cleanRegUI();
private slots:
    void on_loginBtn_clicked();

    void on_registerBtn_clicked();

    void on_label_4_linkActivated(const QString &link);


    void on_maleCheckBox_stateChanged(int arg1);

    void on_femaleCheckBox_stateChanged(int arg1);

private:
    Ui::RegisterPage *ui;
    MainWindow mw;
    QSqlDatabase db;
    DlgWait dw;
};

#endif // REGISTERPAGE_H

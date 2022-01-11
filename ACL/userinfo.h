#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>

namespace Ui {
class UserInfo;
}

class UserInfo : public QWidget
{
    Q_OBJECT

public:
    explicit UserInfo(QWidget *parent = nullptr);
    ~UserInfo();

private slots:
    void on_NameEdit_copyAvailable(bool b);

    void on_pushButton_clicked();

    void on_backButton_clicked();

private:
    Ui::UserInfo *ui;
};

#endif // USERINFO_H

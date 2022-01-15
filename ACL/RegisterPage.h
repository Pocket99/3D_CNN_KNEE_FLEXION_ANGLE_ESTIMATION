#ifndef REGISTERPAGE_H
#define REGISTERPAGE_H

#include <QDialog>

namespace Ui {
class RegisterPage;
}

class RegisterPage : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterPage(QWidget *parent = nullptr);
    ~RegisterPage();

private slots:
    void on_loginBtn_clicked();

    void on_registerBtn_clicked();

    void on_label_4_linkActivated(const QString &link);

private:
    Ui::RegisterPage *ui;
};

#endif // REGISTERPAGE_H

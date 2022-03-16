/********************************************************************************
** Form generated from reading UI file 'RegisterPage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERPAGE_H
#define UI_REGISTERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterPage
{
public:
    QLabel *welcomeLabel;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *loginForm;
    QPushButton *loginBtn;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *loginUsername;
    QLineEdit *loginPassword;
    QLabel *label_6;
    QWidget *tab_2;
    QGroupBox *registerForm;
    QLineEdit *username;
    QLineEdit *password;
    QLineEdit *firstName;
    QLineEdit *lastName;
    QCheckBox *maleCheckBox;
    QLabel *label_5;
    QCheckBox *femaleCheckBox;
    QLineEdit *rDOB;
    QLineEdit *rPhoneNum;
    QLineEdit *rAddress;
    QPushButton *registerBtn;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *rEmail;

    void setupUi(QDialog *RegisterPage)
    {
        if (RegisterPage->objectName().isEmpty())
            RegisterPage->setObjectName(QString::fromUtf8("RegisterPage"));
        RegisterPage->resize(773, 586);
        RegisterPage->setStyleSheet(QString::fromUtf8("RegisterPage{\n"
"background:white\n"
"}"));
        welcomeLabel = new QLabel(RegisterPage);
        welcomeLabel->setObjectName(QString::fromUtf8("welcomeLabel"));
        welcomeLabel->setGeometry(QRect(20, 10, 531, 41));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        welcomeLabel->setFont(font);
        welcomeLabel->setStyleSheet(QString::fromUtf8("#welcomeLabel{\n"
"color:rgb(0, 0, 255);\n"
"}"));
        tabWidget = new QTabWidget(RegisterPage);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(100, 70, 571, 491));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        tabWidget->setFont(font1);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QString::fromUtf8("#tabWidget{\n"
"border-radius:4px;\n"
"}\n"
"#tab{\n"
"background:rgb(99, 167, 255);\n"
"}\n"
"#tab_2{\n"
"background:rgb(99, 167, 255);\n"
"}\n"
""));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setIconSize(QSize(16, 16));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        loginForm = new QGroupBox(tab);
        loginForm->setObjectName(QString::fromUtf8("loginForm"));
        loginForm->setGeometry(QRect(50, 40, 471, 371));
        loginForm->setFont(font1);
        loginForm->setStyleSheet(QString::fromUtf8("#loginForm{\n"
"color:rgb(0, 170, 255);\n"
"background:rgb(255, 255, 255);\n"
"border-radius:10px;\n"
"}"));
        loginBtn = new QPushButton(loginForm);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
        loginBtn->setGeometry(QRect(170, 290, 111, 41));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        loginBtn->setFont(font2);
        loginBtn->setStyleSheet(QString::fromUtf8("#loginBtn{\n"
"color:white;\n"
"background-color:rgb(255, 170, 0);\n"
"border-radius:4px;\n"
"}\n"
"#loginBtn:hover{\n"
"background-color:rgb(255, 170, 127)\n"
"}\n"
"#loginBtn:pressed{\n"
"background-color:white\n"
"}\n"
""));
        label_4 = new QLabel(loginForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 250, 221, 20));
        QFont font3;
        font3.setPointSize(8);
        font3.setBold(false);
        font3.setUnderline(true);
        label_4->setFont(font3);
        label_4->setOpenExternalLinks(true);
        label_2 = new QLabel(loginForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 55, 341, 49));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        label_2->setFont(font4);
        loginUsername = new QLineEdit(loginForm);
        loginUsername->setObjectName(QString::fromUtf8("loginUsername"));
        loginUsername->setGeometry(QRect(60, 110, 341, 26));
        loginPassword = new QLineEdit(loginForm);
        loginPassword->setObjectName(QString::fromUtf8("loginPassword"));
        loginPassword->setGeometry(QRect(60, 205, 341, 26));
        loginPassword->setEchoMode(QLineEdit::Password);
        label_6 = new QLabel(loginForm);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(60, 150, 341, 49));
        label_6->setFont(font4);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        registerForm = new QGroupBox(tab_2);
        registerForm->setObjectName(QString::fromUtf8("registerForm"));
        registerForm->setGeometry(QRect(50, 20, 471, 421));
        registerForm->setFont(font1);
        registerForm->setStyleSheet(QString::fromUtf8("#registerForm{\n"
"color:rgb(0, 170, 255);\n"
"background:rgb(255, 255, 255);\n"
"border-radius:10px;\n"
"}"));
        username = new QLineEdit(registerForm);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(60, 60, 351, 31));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(false);
        username->setFont(font5);
        password = new QLineEdit(registerForm);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(60, 100, 351, 31));
        password->setFont(font5);
        password->setEchoMode(QLineEdit::Password);
        firstName = new QLineEdit(registerForm);
        firstName->setObjectName(QString::fromUtf8("firstName"));
        firstName->setGeometry(QRect(60, 140, 171, 31));
        firstName->setFont(font5);
        lastName = new QLineEdit(registerForm);
        lastName->setObjectName(QString::fromUtf8("lastName"));
        lastName->setGeometry(QRect(250, 140, 161, 31));
        lastName->setFont(font5);
        maleCheckBox = new QCheckBox(registerForm);
        maleCheckBox->setObjectName(QString::fromUtf8("maleCheckBox"));
        maleCheckBox->setGeometry(QRect(180, 180, 91, 24));
        maleCheckBox->setFont(font5);
        label_5 = new QLabel(registerForm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(60, 180, 71, 20));
        label_5->setFont(font5);
        femaleCheckBox = new QCheckBox(registerForm);
        femaleCheckBox->setObjectName(QString::fromUtf8("femaleCheckBox"));
        femaleCheckBox->setGeometry(QRect(310, 180, 91, 24));
        femaleCheckBox->setFont(font5);
        rDOB = new QLineEdit(registerForm);
        rDOB->setObjectName(QString::fromUtf8("rDOB"));
        rDOB->setGeometry(QRect(60, 250, 351, 31));
        rDOB->setFont(font5);
        rPhoneNum = new QLineEdit(registerForm);
        rPhoneNum->setObjectName(QString::fromUtf8("rPhoneNum"));
        rPhoneNum->setGeometry(QRect(60, 290, 351, 31));
        rPhoneNum->setFont(font5);
        rAddress = new QLineEdit(registerForm);
        rAddress->setObjectName(QString::fromUtf8("rAddress"));
        rAddress->setGeometry(QRect(60, 330, 351, 31));
        rAddress->setFont(font5);
        registerBtn = new QPushButton(registerForm);
        registerBtn->setObjectName(QString::fromUtf8("registerBtn"));
        registerBtn->setGeometry(QRect(170, 370, 111, 41));
        registerBtn->setFont(font2);
        registerBtn->setStyleSheet(QString::fromUtf8("#registerBtn{\n"
"color:white;\n"
"background-color:rgb(255, 170, 0);\n"
"border-radius:4px;\n"
"}\n"
"#registerBtn:hover{\n"
"background-color:rgb(255, 170, 127)\n"
"}\n"
"#registerBtn:pressed{\n"
"background-color:white\n"
"}"));
        label = new QLabel(registerForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 70, 16, 16));
        label_3 = new QLabel(registerForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 110, 16, 16));
        label_7 = new QLabel(registerForm);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(50, 150, 16, 16));
        label_8 = new QLabel(registerForm);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(240, 150, 16, 16));
        label_9 = new QLabel(registerForm);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(60, 30, 281, 31));
        rEmail = new QLineEdit(registerForm);
        rEmail->setObjectName(QString::fromUtf8("rEmail"));
        rEmail->setGeometry(QRect(60, 210, 351, 31));
        rEmail->setFont(font5);
        tabWidget->addTab(tab_2, QString());

        retranslateUi(RegisterPage);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RegisterPage);
    } // setupUi

    void retranslateUi(QDialog *RegisterPage)
    {
        RegisterPage->setWindowTitle(QCoreApplication::translate("RegisterPage", "Register Page", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("RegisterPage", "Welcome to ALP Application ! ", nullptr));
        loginForm->setTitle(QCoreApplication::translate("RegisterPage", "Please Login Here", nullptr));
        loginBtn->setText(QCoreApplication::translate("RegisterPage", "Login", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterPage", "Forget your password? Click here.", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterPage", "Username", nullptr));
        label_6->setText(QCoreApplication::translate("RegisterPage", "Password", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("RegisterPage", "             Login             ", nullptr));
        registerForm->setTitle(QCoreApplication::translate("RegisterPage", "Please Register Here", nullptr));
#if QT_CONFIG(tooltip)
        username->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        username->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        username->setText(QString());
        username->setPlaceholderText(QCoreApplication::translate("RegisterPage", "Username", nullptr));
        password->setText(QString());
        password->setPlaceholderText(QCoreApplication::translate("RegisterPage", "Password", nullptr));
        firstName->setText(QString());
        firstName->setPlaceholderText(QCoreApplication::translate("RegisterPage", "First Name", nullptr));
        lastName->setText(QString());
        lastName->setPlaceholderText(QCoreApplication::translate("RegisterPage", "Last Name", nullptr));
        maleCheckBox->setText(QCoreApplication::translate("RegisterPage", "Male", nullptr));
        label_5->setText(QCoreApplication::translate("RegisterPage", "Gender", nullptr));
        femaleCheckBox->setText(QCoreApplication::translate("RegisterPage", "Female", nullptr));
        rDOB->setText(QString());
        rDOB->setPlaceholderText(QCoreApplication::translate("RegisterPage", "Date of Birth (YYYY-MM-DD)", nullptr));
        rPhoneNum->setText(QString());
        rPhoneNum->setPlaceholderText(QCoreApplication::translate("RegisterPage", "Phone Number", nullptr));
        rAddress->setText(QString());
        rAddress->setPlaceholderText(QCoreApplication::translate("RegisterPage", "Address", nullptr));
        registerBtn->setText(QCoreApplication::translate("RegisterPage", "Register", nullptr));
        label->setText(QCoreApplication::translate("RegisterPage", "*", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterPage", "*", nullptr));
        label_7->setText(QCoreApplication::translate("RegisterPage", "*", nullptr));
        label_8->setText(QCoreApplication::translate("RegisterPage", "*", nullptr));
        label_9->setText(QCoreApplication::translate("RegisterPage", "Please Enter All Required Info with (*)", nullptr));
        rEmail->setText(QString());
        rEmail->setPlaceholderText(QCoreApplication::translate("RegisterPage", "Email Address", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("RegisterPage", "           Register            ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterPage: public Ui_RegisterPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERPAGE_H

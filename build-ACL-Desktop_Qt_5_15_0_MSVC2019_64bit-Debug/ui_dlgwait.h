/********************************************************************************
** Form generated from reading UI file 'dlgwait.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGWAIT_H
#define UI_DLGWAIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_DlgWait
{
public:
    QLabel *lbl_gif;
    QLabel *lbl_text;

    void setupUi(QDialog *DlgWait)
    {
        if (DlgWait->objectName().isEmpty())
            DlgWait->setObjectName(QString::fromUtf8("DlgWait"));
        DlgWait->resize(321, 279);
        lbl_gif = new QLabel(DlgWait);
        lbl_gif->setObjectName(QString::fromUtf8("lbl_gif"));
        lbl_gif->setGeometry(QRect(110, 60, 100, 100));
        lbl_text = new QLabel(DlgWait);
        lbl_text->setObjectName(QString::fromUtf8("lbl_text"));
        lbl_text->setGeometry(QRect(100, 170, 141, 21));

        retranslateUi(DlgWait);

        QMetaObject::connectSlotsByName(DlgWait);
    } // setupUi

    void retranslateUi(QDialog *DlgWait)
    {
        DlgWait->setWindowTitle(QCoreApplication::translate("DlgWait", "Dialog", nullptr));
        lbl_gif->setText(QString());
        lbl_text->setText(QCoreApplication::translate("DlgWait", "Generating Result...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DlgWait: public Ui_DlgWait {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGWAIT_H

/********************************************************************************
** Form generated from reading UI file 'outputvideo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTPUTVIDEO_H
#define UI_OUTPUTVIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_OutputVideo
{
public:
    QLabel *label;

    void setupUi(QDialog *OutputVideo)
    {
        if (OutputVideo->objectName().isEmpty())
            OutputVideo->setObjectName(QString::fromUtf8("OutputVideo"));
        OutputVideo->resize(845, 379);
        label = new QLabel(OutputVideo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 341, 231));

        retranslateUi(OutputVideo);

        QMetaObject::connectSlotsByName(OutputVideo);
    } // setupUi

    void retranslateUi(QDialog *OutputVideo)
    {
        OutputVideo->setWindowTitle(QCoreApplication::translate("OutputVideo", "Dialog", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class OutputVideo: public Ui_OutputVideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUTVIDEO_H

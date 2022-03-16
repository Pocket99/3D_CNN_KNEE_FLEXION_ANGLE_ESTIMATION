/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QLabel *label_5;
    QLabel *UI_DocName;
    QWidget *tab_2;
    QGroupBox *groupBox_4;
    QPushButton *addRecord;
    QLineEdit *dateEdit;
    QLabel *label_7;
    QLabel *label_10;
    QComboBox *patientList;
    QLabel *label_8;
    QLineEdit *locationEdit;
    QLabel *label_9;
    QGroupBox *groupBox_5;
    QLabel *ImageCapture;
    QPushButton *captureButton;
    QLabel *recordingLabel;
    QPushButton *analyzeBtn;
    QPushButton *cameraOnBtn;
    QLabel *lbl_gif;
    QLabel *lbl_txt;
    QGroupBox *groupBox_6;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *lMin;
    QLabel *aclRisk;
    QLabel *lMax;
    QLabel *lResults_3;
    QLabel *lResults_4;
    QLabel *rMin;
    QLabel *rMax;
    QLabel *aclRisk_2;
    QGroupBox *groupBox_7;
    QLabel *outputPlay;
    QPushButton *playOutput;
    QPushButton *outputDeleteBtn;
    QWidget *tab_3;
    QGroupBox *groupBox;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *searchBtn;
    QLineEdit *hfirstName;
    QLineEdit *hlastName;
    QPushButton *resetBtn;
    QLabel *label_4;
    QLineEdit *hDOB;
    QLabel *label_6;
    QGroupBox *groupBox_2;
    QTreeWidget *treeWidget;
    QGroupBox *groupBox_3;
    QPushButton *refreshBtn;
    QPushButton *deleteBtn;
    QPushButton *addBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1437, 990);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1421, 980));
        tabWidget->setMinimumSize(QSize(1200, 0));
        QFont font;
        font.setPointSize(10);
        tabWidget->setFont(font);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 240, 1131, 131));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(90, 80, 191, 131));
        UI_DocName = new QLabel(tab);
        UI_DocName->setObjectName(QString::fromUtf8("UI_DocName"));
        UI_DocName->setGeometry(QRect(290, 120, 211, 61));
        QFont font1;
        font1.setPointSize(28);
        UI_DocName->setFont(font1);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(890, 180, 371, 281));
        addRecord = new QPushButton(groupBox_4);
        addRecord->setObjectName(QString::fromUtf8("addRecord"));
        addRecord->setGeometry(QRect(110, 210, 131, 51));
        dateEdit = new QLineEdit(groupBox_4);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(120, 150, 191, 31));
        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 40, 53, 16));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(120, 180, 121, 20));
        patientList = new QComboBox(groupBox_4);
        patientList->setObjectName(QString::fromUtf8("patientList"));
        patientList->setGeometry(QRect(120, 30, 191, 31));
        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 90, 61, 16));
        locationEdit = new QLineEdit(groupBox_4);
        locationEdit->setObjectName(QString::fromUtf8("locationEdit"));
        locationEdit->setGeometry(QRect(120, 90, 191, 31));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(30, 150, 53, 16));
        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(20, 10, 851, 451));
        ImageCapture = new QLabel(groupBox_5);
        ImageCapture->setObjectName(QString::fromUtf8("ImageCapture"));
        ImageCapture->setEnabled(true);
        ImageCapture->setGeometry(QRect(50, 20, 561, 421));
        captureButton = new QPushButton(groupBox_5);
        captureButton->setObjectName(QString::fromUtf8("captureButton"));
        captureButton->setGeometry(QRect(670, 160, 141, 51));
        recordingLabel = new QLabel(groupBox_5);
        recordingLabel->setObjectName(QString::fromUtf8("recordingLabel"));
        recordingLabel->setGeometry(QRect(690, 210, 101, 41));
        analyzeBtn = new QPushButton(groupBox_5);
        analyzeBtn->setObjectName(QString::fromUtf8("analyzeBtn"));
        analyzeBtn->setGeometry(QRect(670, 280, 141, 51));
        cameraOnBtn = new QPushButton(groupBox_5);
        cameraOnBtn->setObjectName(QString::fromUtf8("cameraOnBtn"));
        cameraOnBtn->setGeometry(QRect(670, 50, 141, 51));
        lbl_gif = new QLabel(groupBox_5);
        lbl_gif->setObjectName(QString::fromUtf8("lbl_gif"));
        lbl_gif->setGeometry(QRect(710, 350, 60, 60));
        lbl_txt = new QLabel(groupBox_5);
        lbl_txt->setObjectName(QString::fromUtf8("lbl_txt"));
        lbl_txt->setGeometry(QRect(670, 330, 191, 21));
        groupBox_6 = new QGroupBox(tab_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(890, 10, 371, 161));
        label_12 = new QLabel(groupBox_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(30, 30, 131, 31));
        label_13 = new QLabel(groupBox_6);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(30, 110, 131, 31));
        label_14 = new QLabel(groupBox_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(30, 70, 131, 31));
        lMin = new QLabel(groupBox_6);
        lMin->setObjectName(QString::fromUtf8("lMin"));
        lMin->setGeometry(QRect(180, 30, 41, 31));
        aclRisk = new QLabel(groupBox_6);
        aclRisk->setObjectName(QString::fromUtf8("aclRisk"));
        aclRisk->setGeometry(QRect(190, 110, 31, 31));
        lMax = new QLabel(groupBox_6);
        lMax->setObjectName(QString::fromUtf8("lMax"));
        lMax->setGeometry(QRect(270, 30, 41, 31));
        lResults_3 = new QLabel(groupBox_6);
        lResults_3->setObjectName(QString::fromUtf8("lResults_3"));
        lResults_3->setGeometry(QRect(240, 30, 16, 31));
        lResults_4 = new QLabel(groupBox_6);
        lResults_4->setObjectName(QString::fromUtf8("lResults_4"));
        lResults_4->setGeometry(QRect(240, 70, 16, 31));
        rMin = new QLabel(groupBox_6);
        rMin->setObjectName(QString::fromUtf8("rMin"));
        rMin->setGeometry(QRect(180, 70, 41, 31));
        rMax = new QLabel(groupBox_6);
        rMax->setObjectName(QString::fromUtf8("rMax"));
        rMax->setGeometry(QRect(270, 70, 41, 31));
        aclRisk_2 = new QLabel(groupBox_6);
        aclRisk_2->setObjectName(QString::fromUtf8("aclRisk_2"));
        aclRisk_2->setGeometry(QRect(230, 110, 31, 31));
        groupBox_7 = new QGroupBox(tab_2);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(20, 470, 1241, 490));
        outputPlay = new QLabel(groupBox_7);
        outputPlay->setObjectName(QString::fromUtf8("outputPlay"));
        outputPlay->setGeometry(QRect(40, 20, 1191, 461));
        playOutput = new QPushButton(groupBox_7);
        playOutput->setObjectName(QString::fromUtf8("playOutput"));
        playOutput->setGeometry(QRect(10, 80, 41, 151));
        outputDeleteBtn = new QPushButton(groupBox_7);
        outputDeleteBtn->setObjectName(QString::fromUtf8("outputDeleteBtn"));
        outputDeleteBtn->setGeometry(QRect(10, 260, 41, 151));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        groupBox = new QGroupBox(tab_3);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(60, 60, 1181, 171));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 50, 101, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(300, 50, 101, 20));
        searchBtn = new QPushButton(groupBox);
        searchBtn->setObjectName(QString::fromUtf8("searchBtn"));
        searchBtn->setGeometry(QRect(820, 70, 111, 61));
        hfirstName = new QLineEdit(groupBox);
        hfirstName->setObjectName(QString::fromUtf8("hfirstName"));
        hfirstName->setGeometry(QRect(40, 80, 181, 41));
        hlastName = new QLineEdit(groupBox);
        hlastName->setObjectName(QString::fromUtf8("hlastName"));
        hlastName->setGeometry(QRect(300, 80, 181, 41));
        resetBtn = new QPushButton(groupBox);
        resetBtn->setObjectName(QString::fromUtf8("resetBtn"));
        resetBtn->setGeometry(QRect(1010, 70, 111, 61));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(560, 50, 101, 20));
        hDOB = new QLineEdit(groupBox);
        hDOB->setObjectName(QString::fromUtf8("hDOB"));
        hDOB->setGeometry(QRect(560, 80, 181, 41));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(560, 120, 121, 20));
        groupBox_2 = new QGroupBox(tab_3);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(300, 260, 941, 591));
        treeWidget = new QTreeWidget(groupBox_2);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(60, 50, 821, 501));
        treeWidget->setColumnCount(0);
        treeWidget->header()->setDefaultSectionSize(280);
        groupBox_3 = new QGroupBox(tab_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(60, 260, 211, 591));
        groupBox_3->setAcceptDrops(true);
#if QT_CONFIG(tooltip)
        groupBox_3->setToolTip(QString::fromUtf8(""));
#endif // QT_CONFIG(tooltip)
        refreshBtn = new QPushButton(groupBox_3);
        refreshBtn->setObjectName(QString::fromUtf8("refreshBtn"));
        refreshBtn->setGeometry(QRect(60, 410, 93, 81));
        refreshBtn->setFont(font);
        deleteBtn = new QPushButton(groupBox_3);
        deleteBtn->setObjectName(QString::fromUtf8("deleteBtn"));
        deleteBtn->setGeometry(QRect(60, 240, 93, 81));
        deleteBtn->setFont(font);
        addBtn = new QPushButton(groupBox_3);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        addBtn->setGeometry(QRect(60, 70, 93, 81));
        addBtn->setFont(font);
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1437, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Athlete Ligament Protector", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:28pt;\">Welcome to Athlete Ligament Protector Application!</span></p><p><span style=\" font-size:28pt;\"><br/></span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:36pt;\">Hello, </span></p></body></html>", nullptr));
        UI_DocName->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:28pt;\">User</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "USER INFO", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Add Record", nullptr));
        addRecord->setText(QCoreApplication::translate("MainWindow", "Add To Record", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Patient:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "( yyyy-mm-dd )", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Location:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Date:", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Camera", nullptr));
        ImageCapture->setText(QString());
        captureButton->setText(QCoreApplication::translate("MainWindow", "Start/Finish", nullptr));
        recordingLabel->setText(QCoreApplication::translate("MainWindow", "RECORDING", nullptr));
        analyzeBtn->setText(QCoreApplication::translate("MainWindow", "Analyze", nullptr));
        cameraOnBtn->setText(QCoreApplication::translate("MainWindow", "On / Off", nullptr));
        lbl_gif->setText(QString());
        lbl_txt->setText(QCoreApplication::translate("MainWindow", "Generating Result...", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "ALP Analysis Result", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Left  (Min/Max):", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "ACL Risk          :", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Right(Min/Max):", nullptr));
        lMin->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        aclRisk->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lMax->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        lResults_3->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        lResults_4->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        rMin->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        rMax->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        aclRisk_2->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "ALP Video Result", nullptr));
        outputPlay->setText(QString());
        playOutput->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
        outputDeleteBtn->setText(QCoreApplication::translate("MainWindow", "Del", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "JUMP TEST", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Patient Information", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "First Name", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Last Name", nullptr));
        searchBtn->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        resetBtn->setText(QCoreApplication::translate("MainWindow", "Reset Search", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Date of Birth", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "( yyyy-mm-dd )", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Details", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Record Information", nullptr));
        refreshBtn->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        deleteBtn->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        addBtn->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "RECORD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

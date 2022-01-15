#include "mainwindow.h"
#include "RegisterPage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    RegisterPage rp;
    rp.show();
    return a.exec();

}

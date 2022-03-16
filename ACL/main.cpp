#include "mainwindow.h"
#include "RegisterPage.h"
#include <QApplication>
#include <QProcess>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QTextCodec *code = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(code);
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    RegisterPage rp;
    rp.show();

//    Py_Initialize();
//        if ( !Py_IsInitialized() )
//        {
//        return -1;
//        }
//        PyObject* pModule = PyImport_ImportModule("test");  // 这里的test_py就是创建的python文件
//        if (!pModule) {
//                cout<< "Cant open python file!\n" << endl;
//                return -1;
//            }
//       PyObject* pFunRun= PyObject_GetAttrString(pModule,"run");  // 这里的hellow就是python文件定义的函数
//    //    PyObject* pDict = PyModule_GetDict(pModule);
//    //       if (!pDict) {
//    //           printf("Cant find dictionary.\n");
//    //           return -1;
//    //       }
//    //    PyObject* pFunhello = PyDict_GetItemString(pDict, "hello");

//        if(!pFunRun){
//            cout<<"Get function run failed"<<endl;
//            return -1;
//        }
//        PyObject_CallFunction(pFunRun,NULL);
//        Py_Finalize();

    return a.exec();

}

/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../ACL/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[359];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 24), // "on_captureButton_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 9), // "readFrame"
QT_MOC_LITERAL(4, 47, 11), // "buttonClose"
QT_MOC_LITERAL(5, 59, 20), // "on_searchBtn_clicked"
QT_MOC_LITERAL(6, 80, 17), // "on_addBtn_clicked"
QT_MOC_LITERAL(7, 98, 19), // "on_resetBtn_clicked"
QT_MOC_LITERAL(8, 118, 24), // "on_patientList_activated"
QT_MOC_LITERAL(9, 143, 5), // "index"
QT_MOC_LITERAL(10, 149, 20), // "on_addRecord_clicked"
QT_MOC_LITERAL(11, 170, 21), // "on_refreshBtn_clicked"
QT_MOC_LITERAL(12, 192, 20), // "on_deleteBtn_clicked"
QT_MOC_LITERAL(13, 213, 26), // "on_outputDeleteBtn_clicked"
QT_MOC_LITERAL(14, 240, 21), // "on_analyzeBtn_clicked"
QT_MOC_LITERAL(15, 262, 21), // "on_playOutput_clicked"
QT_MOC_LITERAL(16, 284, 11), // "outputFrame"
QT_MOC_LITERAL(17, 296, 22), // "on_cameraOnBtn_clicked"
QT_MOC_LITERAL(18, 319, 25), // "on_downloadButton_clicked"
QT_MOC_LITERAL(19, 345, 13) // "set_invisible"

    },
    "MainWindow\0on_captureButton_clicked\0"
    "\0readFrame\0buttonClose\0on_searchBtn_clicked\0"
    "on_addBtn_clicked\0on_resetBtn_clicked\0"
    "on_patientList_activated\0index\0"
    "on_addRecord_clicked\0on_refreshBtn_clicked\0"
    "on_deleteBtn_clicked\0on_outputDeleteBtn_clicked\0"
    "on_analyzeBtn_clicked\0on_playOutput_clicked\0"
    "outputFrame\0on_cameraOnBtn_clicked\0"
    "on_downloadButton_clicked\0set_invisible"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x08 /* Private */,
       3,    0,  100,    2, 0x08 /* Private */,
       4,    0,  101,    2, 0x08 /* Private */,
       5,    0,  102,    2, 0x08 /* Private */,
       6,    0,  103,    2, 0x08 /* Private */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    1,  105,    2, 0x08 /* Private */,
      10,    0,  108,    2, 0x08 /* Private */,
      11,    0,  109,    2, 0x08 /* Private */,
      12,    0,  110,    2, 0x08 /* Private */,
      13,    0,  111,    2, 0x08 /* Private */,
      14,    0,  112,    2, 0x08 /* Private */,
      15,    0,  113,    2, 0x08 /* Private */,
      16,    0,  114,    2, 0x08 /* Private */,
      17,    0,  115,    2, 0x08 /* Private */,
      18,    0,  116,    2, 0x08 /* Private */,
      19,    0,  117,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_captureButton_clicked(); break;
        case 1: _t->readFrame(); break;
        case 2: _t->buttonClose(); break;
        case 3: _t->on_searchBtn_clicked(); break;
        case 4: _t->on_addBtn_clicked(); break;
        case 5: _t->on_resetBtn_clicked(); break;
        case 6: _t->on_patientList_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_addRecord_clicked(); break;
        case 8: _t->on_refreshBtn_clicked(); break;
        case 9: _t->on_deleteBtn_clicked(); break;
        case 10: _t->on_outputDeleteBtn_clicked(); break;
        case 11: _t->on_analyzeBtn_clicked(); break;
        case 12: _t->on_playOutput_clicked(); break;
        case 13: _t->outputFrame(); break;
        case 14: _t->on_cameraOnBtn_clicked(); break;
        case 15: _t->on_downloadButton_clicked(); break;
        case 16: _t->set_invisible(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

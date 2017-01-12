/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[26];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 5), // "about"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 16), // "applyPortOptions"
QT_MOC_LITERAL(4, 35, 11), // "btsendClick"
QT_MOC_LITERAL(5, 47, 15), // "btstopsendClick"
QT_MOC_LITERAL(6, 63, 9), // "closePort"
QT_MOC_LITERAL(7, 73, 13), // "enabledPortBt"
QT_MOC_LITERAL(8, 87, 8), // "openPort"
QT_MOC_LITERAL(9, 96, 10), // "receiveMsg"
QT_MOC_LITERAL(10, 107, 6), // "timesl"
QT_MOC_LITERAL(11, 114, 20), // "const unsigned char*"
QT_MOC_LITERAL(12, 135, 4), // "data"
QT_MOC_LITERAL(13, 140, 4), // "size"
QT_MOC_LITERAL(14, 145, 17), // "SetCurComboBState"
QT_MOC_LITERAL(15, 163, 15), // "setTimeoutTimer"
QT_MOC_LITERAL(16, 179, 5), // "state"
QT_MOC_LITERAL(17, 185, 8), // "Crc16Bit"
QT_MOC_LITERAL(18, 194, 18), // "unsigned short int"
QT_MOC_LITERAL(19, 213, 11), // "const char*"
QT_MOC_LITERAL(20, 225, 3), // "ptr"
QT_MOC_LITERAL(21, 229, 3), // "len"
QT_MOC_LITERAL(22, 233, 11), // "transmitMsg"
QT_MOC_LITERAL(23, 245, 14), // "intervalChange"
QT_MOC_LITERAL(24, 260, 5), // "value"
QT_MOC_LITERAL(25, 266, 15) // "on_File_clicked"

    },
    "MainWindow\0about\0\0applyPortOptions\0"
    "btsendClick\0btstopsendClick\0closePort\0"
    "enabledPortBt\0openPort\0receiveMsg\0"
    "timesl\0const unsigned char*\0data\0size\0"
    "SetCurComboBState\0setTimeoutTimer\0"
    "state\0Crc16Bit\0unsigned short int\0"
    "const char*\0ptr\0len\0transmitMsg\0"
    "intervalChange\0value\0on_File_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    3,   91,    2, 0x08 /* Private */,
      14,    0,   98,    2, 0x08 /* Private */,
      15,    1,   99,    2, 0x08 /* Private */,
      17,    2,  102,    2, 0x08 /* Private */,
      22,    0,  107,    2, 0x08 /* Private */,
      23,    1,  108,    2, 0x08 /* Private */,
      25,    0,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QTime, 0x80000000 | 11, QMetaType::Int,   10,   12,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,
    0x80000000 | 18, 0x80000000 | 19, 0x80000000 | 18,   20,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->about(); break;
        case 1: _t->applyPortOptions(); break;
        case 2: _t->btsendClick(); break;
        case 3: _t->btstopsendClick(); break;
        case 4: _t->closePort(); break;
        case 5: _t->enabledPortBt(); break;
        case 6: _t->openPort(); break;
        case 7: _t->receiveMsg((*reinterpret_cast< const QTime(*)>(_a[1])),(*reinterpret_cast< const unsigned char*(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 8: _t->SetCurComboBState(); break;
        case 9: _t->setTimeoutTimer((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: { unsigned short int _r = _t->Crc16Bit((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< unsigned short int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< unsigned short int*>(_a[0]) = _r; }  break;
        case 11: _t->transmitMsg(); break;
        case 12: _t->intervalChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_File_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

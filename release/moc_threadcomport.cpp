/****************************************************************************
** Meta object code from reading C++ file 'threadcomport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../threadcomport/threadcomport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'threadcomport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QMainComThread_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QMainComThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QMainComThread_t qt_meta_stringdata_QMainComThread = {
    {
QT_MOC_LITERAL(0, 0, 14) // "QMainComThread"

    },
    "QMainComThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QMainComThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void QMainComThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject QMainComThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_QMainComThread.data,
      qt_meta_data_QMainComThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QMainComThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QMainComThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QMainComThread.stringdata0))
        return static_cast<void*>(const_cast< QMainComThread*>(this));
    return QThread::qt_metacast(_clname);
}

int QMainComThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
struct qt_meta_stringdata_Qthreadcomport_t {
    QByteArrayData data[9];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Qthreadcomport_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Qthreadcomport_t qt_meta_stringdata_Qthreadcomport = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Qthreadcomport"
QT_MOC_LITERAL(1, 15, 19), // "newDataInPortSignal"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 6), // "timesl"
QT_MOC_LITERAL(4, 43, 20), // "const unsigned char*"
QT_MOC_LITERAL(5, 64, 4), // "data"
QT_MOC_LITERAL(6, 69, 4), // "size"
QT_MOC_LITERAL(7, 74, 17), // "newDataInPortSlot"
QT_MOC_LITERAL(8, 92, 5) // "count"

    },
    "Qthreadcomport\0newDataInPortSignal\0\0"
    "timesl\0const unsigned char*\0data\0size\0"
    "newDataInPortSlot\0count"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Qthreadcomport[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   31,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QTime, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void Qthreadcomport::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Qthreadcomport *_t = static_cast<Qthreadcomport *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newDataInPortSignal((*reinterpret_cast< const QTime(*)>(_a[1])),(*reinterpret_cast< const unsigned char*(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 1: _t->newDataInPortSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Qthreadcomport::*_t)(const QTime , const unsigned char * , const int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Qthreadcomport::newDataInPortSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Qthreadcomport::staticMetaObject = {
    { &QextSerialPort::staticMetaObject, qt_meta_stringdata_Qthreadcomport.data,
      qt_meta_data_Qthreadcomport,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Qthreadcomport::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Qthreadcomport::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Qthreadcomport.stringdata0))
        return static_cast<void*>(const_cast< Qthreadcomport*>(this));
    return QextSerialPort::qt_metacast(_clname);
}

int Qthreadcomport::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QextSerialPort::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Qthreadcomport::newDataInPortSignal(const QTime _t1, const unsigned char * _t2, const int _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_ReceiveThread_t {
    QByteArrayData data[4];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReceiveThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReceiveThread_t qt_meta_stringdata_ReceiveThread = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ReceiveThread"
QT_MOC_LITERAL(1, 14, 19), // "newDataInPortThread"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 5) // "count"

    },
    "ReceiveThread\0newDataInPortThread\0\0"
    "count"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReceiveThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void ReceiveThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ReceiveThread *_t = static_cast<ReceiveThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->newDataInPortThread((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ReceiveThread::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ReceiveThread::newDataInPortThread)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject ReceiveThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ReceiveThread.data,
      qt_meta_data_ReceiveThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ReceiveThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReceiveThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ReceiveThread.stringdata0))
        return static_cast<void*>(const_cast< ReceiveThread*>(this));
    return QThread::qt_metacast(_clname);
}

int ReceiveThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ReceiveThread::newDataInPortThread(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE

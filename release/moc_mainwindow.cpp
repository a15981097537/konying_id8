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
    QByteArrayData data[72];
    char stringdata0[1163];
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
QT_MOC_LITERAL(15, 163, 8), // "Crc16Bit"
QT_MOC_LITERAL(16, 172, 18), // "unsigned short int"
QT_MOC_LITERAL(17, 191, 11), // "const char*"
QT_MOC_LITERAL(18, 203, 3), // "ptr"
QT_MOC_LITERAL(19, 207, 3), // "len"
QT_MOC_LITERAL(20, 211, 11), // "transmitMsg"
QT_MOC_LITERAL(21, 223, 14), // "intervalChange"
QT_MOC_LITERAL(22, 238, 5), // "value"
QT_MOC_LITERAL(23, 244, 15), // "on_File_clicked"
QT_MOC_LITERAL(24, 260, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(25, 282, 22), // "on_bt_openFile_clicked"
QT_MOC_LITERAL(26, 305, 41), // "on_comboBox_updateWay_current..."
QT_MOC_LITERAL(27, 347, 4), // "arg1"
QT_MOC_LITERAL(28, 352, 9), // "user_init"
QT_MOC_LITERAL(29, 362, 13), // "pressUartData"
QT_MOC_LITERAL(30, 376, 13), // "u_sendMessage"
QT_MOC_LITERAL(31, 390, 3), // "cmd"
QT_MOC_LITERAL(32, 394, 11), // "QByteArray*"
QT_MOC_LITERAL(33, 406, 13), // "r_sendMessage"
QT_MOC_LITERAL(34, 420, 8), // "usartAck"
QT_MOC_LITERAL(35, 429, 4), // "head"
QT_MOC_LITERAL(36, 434, 12), // "pressCmdData"
QT_MOC_LITERAL(37, 447, 6), // "uchar*"
QT_MOC_LITERAL(38, 454, 15), // "DisplayWithTime"
QT_MOC_LITERAL(39, 470, 4), // "text"
QT_MOC_LITERAL(40, 475, 17), // "DisplayWithNoTime"
QT_MOC_LITERAL(41, 493, 10), // "uint8ToHex"
QT_MOC_LITERAL(42, 504, 11), // "uint16ToHex"
QT_MOC_LITERAL(43, 516, 11), // "uint32ToHex"
QT_MOC_LITERAL(44, 528, 8), // "strToHex"
QT_MOC_LITERAL(45, 537, 16), // "ucmdGetDeviceInf"
QT_MOC_LITERAL(46, 554, 14), // "ucmdSendFirInf"
QT_MOC_LITERAL(47, 569, 18), // "ucmdSendsendPacket"
QT_MOC_LITERAL(48, 588, 6), // "packet"
QT_MOC_LITERAL(49, 595, 14), // "ucmdAutoUpdate"
QT_MOC_LITERAL(50, 610, 4), // "step"
QT_MOC_LITERAL(51, 615, 18), // "rcmdSendsendPacket"
QT_MOC_LITERAL(52, 634, 14), // "rcmdSendFirInf"
QT_MOC_LITERAL(53, 649, 16), // "rcmdGetDeviceInf"
QT_MOC_LITERAL(54, 666, 26), // "on_bt_getDeviceInf_clicked"
QT_MOC_LITERAL(55, 693, 24), // "on_bt_sendFirInf_clicked"
QT_MOC_LITERAL(56, 718, 24), // "on_bt_sendPacket_clicked"
QT_MOC_LITERAL(57, 743, 24), // "on_bt_autoUpdate_clicked"
QT_MOC_LITERAL(58, 768, 28), // "on_bt_stopAutoUpdate_clicked"
QT_MOC_LITERAL(59, 797, 22), // "on_bt_readBoot_clicked"
QT_MOC_LITERAL(60, 820, 26), // "on_bt_readFirmware_clicked"
QT_MOC_LITERAL(61, 847, 22), // "on_bt_stopRead_clicked"
QT_MOC_LITERAL(62, 870, 23), // "on_bt_storeFile_clicked"
QT_MOC_LITERAL(63, 894, 41), // "on_comboBox_updateMode_curren..."
QT_MOC_LITERAL(64, 936, 33), // "on_shortAddr_itemSelectionCha..."
QT_MOC_LITERAL(65, 970, 39), // "on_frimwareVersion_3_currentT..."
QT_MOC_LITERAL(66, 1010, 35), // "on_cb_deviceType_currentTextC..."
QT_MOC_LITERAL(67, 1046, 36), // "on_cb_deviceType_currentIndex..."
QT_MOC_LITERAL(68, 1083, 5), // "index"
QT_MOC_LITERAL(69, 1089, 26), // "on_shortAddr_doubleClicked"
QT_MOC_LITERAL(70, 1116, 21), // "on_pb_addAddr_clicked"
QT_MOC_LITERAL(71, 1138, 24) // "on_pb_deleteAddr_clicked"

    },
    "MainWindow\0about\0\0applyPortOptions\0"
    "btsendClick\0btstopsendClick\0closePort\0"
    "enabledPortBt\0openPort\0receiveMsg\0"
    "timesl\0const unsigned char*\0data\0size\0"
    "SetCurComboBState\0Crc16Bit\0"
    "unsigned short int\0const char*\0ptr\0"
    "len\0transmitMsg\0intervalChange\0value\0"
    "on_File_clicked\0on_pushButton_clicked\0"
    "on_bt_openFile_clicked\0"
    "on_comboBox_updateWay_currentIndexChanged\0"
    "arg1\0user_init\0pressUartData\0u_sendMessage\0"
    "cmd\0QByteArray*\0r_sendMessage\0usartAck\0"
    "head\0pressCmdData\0uchar*\0DisplayWithTime\0"
    "text\0DisplayWithNoTime\0uint8ToHex\0"
    "uint16ToHex\0uint32ToHex\0strToHex\0"
    "ucmdGetDeviceInf\0ucmdSendFirInf\0"
    "ucmdSendsendPacket\0packet\0ucmdAutoUpdate\0"
    "step\0rcmdSendsendPacket\0rcmdSendFirInf\0"
    "rcmdGetDeviceInf\0on_bt_getDeviceInf_clicked\0"
    "on_bt_sendFirInf_clicked\0"
    "on_bt_sendPacket_clicked\0"
    "on_bt_autoUpdate_clicked\0"
    "on_bt_stopAutoUpdate_clicked\0"
    "on_bt_readBoot_clicked\0"
    "on_bt_readFirmware_clicked\0"
    "on_bt_stopRead_clicked\0on_bt_storeFile_clicked\0"
    "on_comboBox_updateMode_currentTextChanged\0"
    "on_shortAddr_itemSelectionChanged\0"
    "on_frimwareVersion_3_currentTextChanged\0"
    "on_cb_deviceType_currentTextChanged\0"
    "on_cb_deviceType_currentIndexChanged\0"
    "index\0on_shortAddr_doubleClicked\0"
    "on_pb_addAddr_clicked\0on_pb_deleteAddr_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      52,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  274,    2, 0x08 /* Private */,
       3,    0,  275,    2, 0x08 /* Private */,
       4,    0,  276,    2, 0x08 /* Private */,
       5,    0,  277,    2, 0x08 /* Private */,
       6,    0,  278,    2, 0x08 /* Private */,
       7,    0,  279,    2, 0x08 /* Private */,
       8,    0,  280,    2, 0x08 /* Private */,
       9,    3,  281,    2, 0x08 /* Private */,
      14,    0,  288,    2, 0x08 /* Private */,
      15,    2,  289,    2, 0x08 /* Private */,
      20,    0,  294,    2, 0x08 /* Private */,
      21,    1,  295,    2, 0x08 /* Private */,
      23,    0,  298,    2, 0x08 /* Private */,
      24,    0,  299,    2, 0x08 /* Private */,
      25,    0,  300,    2, 0x08 /* Private */,
      26,    1,  301,    2, 0x08 /* Private */,
      28,    0,  304,    2, 0x08 /* Private */,
      29,    0,  305,    2, 0x08 /* Private */,
      30,    2,  306,    2, 0x08 /* Private */,
      33,    2,  311,    2, 0x08 /* Private */,
      34,    1,  316,    2, 0x08 /* Private */,
      36,    2,  319,    2, 0x08 /* Private */,
      38,    1,  324,    2, 0x08 /* Private */,
      40,    1,  327,    2, 0x08 /* Private */,
      41,    1,  330,    2, 0x08 /* Private */,
      42,    1,  333,    2, 0x08 /* Private */,
      43,    1,  336,    2, 0x08 /* Private */,
      44,    2,  339,    2, 0x08 /* Private */,
      45,    0,  344,    2, 0x08 /* Private */,
      46,    0,  345,    2, 0x08 /* Private */,
      47,    1,  346,    2, 0x08 /* Private */,
      49,    1,  349,    2, 0x08 /* Private */,
      51,    1,  352,    2, 0x08 /* Private */,
      52,    0,  355,    2, 0x08 /* Private */,
      53,    0,  356,    2, 0x08 /* Private */,
      54,    0,  357,    2, 0x08 /* Private */,
      55,    0,  358,    2, 0x08 /* Private */,
      56,    0,  359,    2, 0x08 /* Private */,
      57,    0,  360,    2, 0x08 /* Private */,
      58,    0,  361,    2, 0x08 /* Private */,
      59,    0,  362,    2, 0x08 /* Private */,
      60,    0,  363,    2, 0x08 /* Private */,
      61,    0,  364,    2, 0x08 /* Private */,
      62,    0,  365,    2, 0x08 /* Private */,
      63,    1,  366,    2, 0x08 /* Private */,
      64,    0,  369,    2, 0x08 /* Private */,
      65,    1,  370,    2, 0x08 /* Private */,
      66,    1,  373,    2, 0x08 /* Private */,
      67,    1,  376,    2, 0x08 /* Private */,
      69,    1,  379,    2, 0x08 /* Private */,
      70,    0,  382,    2, 0x08 /* Private */,
      71,    0,  383,    2, 0x08 /* Private */,

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
    0x80000000 | 16, 0x80000000 | 17, 0x80000000 | 16,   18,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Char, QMetaType::UChar, 0x80000000 | 32,   31,   12,
    QMetaType::Char, QMetaType::UChar, 0x80000000 | 32,   31,   12,
    QMetaType::Void, QMetaType::UChar,   35,
    QMetaType::Void, 0x80000000 | 37, QMetaType::UShort,   12,   13,
    QMetaType::Void, QMetaType::QString,   39,
    QMetaType::Void, QMetaType::QString,   39,
    QMetaType::QString, QMetaType::UChar,   12,
    QMetaType::QString, QMetaType::UShort,   12,
    QMetaType::QString, QMetaType::UInt,   12,
    QMetaType::QString, 0x80000000 | 37, QMetaType::UShort,   12,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UShort,   48,
    QMetaType::Void, QMetaType::UChar,   50,
    QMetaType::Void, QMetaType::UShort,   48,
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
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void, QMetaType::QString,   27,
    QMetaType::Void, QMetaType::Int,   68,
    QMetaType::Void, QMetaType::QModelIndex,   68,
    QMetaType::Void,
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
        case 9: { unsigned short int _r = _t->Crc16Bit((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< unsigned short int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< unsigned short int*>(_a[0]) = _r; }  break;
        case 10: _t->transmitMsg(); break;
        case 11: _t->intervalChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_File_clicked(); break;
        case 13: _t->on_pushButton_clicked(); break;
        case 14: _t->on_bt_openFile_clicked(); break;
        case 15: _t->on_comboBox_updateWay_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->user_init(); break;
        case 17: _t->pressUartData(); break;
        case 18: { char _r = _t->u_sendMessage((*reinterpret_cast< unsigned char(*)>(_a[1])),(*reinterpret_cast< QByteArray*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< char*>(_a[0]) = _r; }  break;
        case 19: { char _r = _t->r_sendMessage((*reinterpret_cast< unsigned char(*)>(_a[1])),(*reinterpret_cast< QByteArray*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< char*>(_a[0]) = _r; }  break;
        case 20: _t->usartAck((*reinterpret_cast< uchar(*)>(_a[1]))); break;
        case 21: _t->pressCmdData((*reinterpret_cast< uchar*(*)>(_a[1])),(*reinterpret_cast< ushort(*)>(_a[2]))); break;
        case 22: _t->DisplayWithTime((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 23: _t->DisplayWithNoTime((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 24: { QString _r = _t->uint8ToHex((*reinterpret_cast< uchar(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 25: { QString _r = _t->uint16ToHex((*reinterpret_cast< ushort(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 26: { QString _r = _t->uint32ToHex((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 27: { QString _r = _t->strToHex((*reinterpret_cast< uchar*(*)>(_a[1])),(*reinterpret_cast< ushort(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 28: _t->ucmdGetDeviceInf(); break;
        case 29: _t->ucmdSendFirInf(); break;
        case 30: _t->ucmdSendsendPacket((*reinterpret_cast< ushort(*)>(_a[1]))); break;
        case 31: _t->ucmdAutoUpdate((*reinterpret_cast< uchar(*)>(_a[1]))); break;
        case 32: _t->rcmdSendsendPacket((*reinterpret_cast< ushort(*)>(_a[1]))); break;
        case 33: _t->rcmdSendFirInf(); break;
        case 34: _t->rcmdGetDeviceInf(); break;
        case 35: _t->on_bt_getDeviceInf_clicked(); break;
        case 36: _t->on_bt_sendFirInf_clicked(); break;
        case 37: _t->on_bt_sendPacket_clicked(); break;
        case 38: _t->on_bt_autoUpdate_clicked(); break;
        case 39: _t->on_bt_stopAutoUpdate_clicked(); break;
        case 40: _t->on_bt_readBoot_clicked(); break;
        case 41: _t->on_bt_readFirmware_clicked(); break;
        case 42: _t->on_bt_stopRead_clicked(); break;
        case 43: _t->on_bt_storeFile_clicked(); break;
        case 44: _t->on_comboBox_updateMode_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 45: _t->on_shortAddr_itemSelectionChanged(); break;
        case 46: _t->on_frimwareVersion_3_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 47: _t->on_cb_deviceType_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 48: _t->on_cb_deviceType_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 49: _t->on_shortAddr_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 50: _t->on_pb_addAddr_clicked(); break;
        case 51: _t->on_pb_deleteAddr_clicked(); break;
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
        if (_id < 52)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 52;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 52)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 52;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

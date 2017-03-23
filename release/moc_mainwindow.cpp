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
    QByteArrayData data[73];
    char stringdata0[1520];
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
QT_MOC_LITERAL(20, 211, 8), // "checkSum"
QT_MOC_LITERAL(21, 220, 8), // "puchData"
QT_MOC_LITERAL(22, 229, 11), // "transmitMsg"
QT_MOC_LITERAL(23, 241, 14), // "intervalChange"
QT_MOC_LITERAL(24, 256, 5), // "value"
QT_MOC_LITERAL(25, 262, 15), // "on_File_clicked"
QT_MOC_LITERAL(26, 278, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(27, 300, 22), // "on_bt_openFile_clicked"
QT_MOC_LITERAL(28, 323, 41), // "on_comboBox_updateWay_current..."
QT_MOC_LITERAL(29, 365, 4), // "arg1"
QT_MOC_LITERAL(30, 370, 26), // "on_bt_getDeviceInf_clicked"
QT_MOC_LITERAL(31, 397, 24), // "on_bt_sendFirInf_clicked"
QT_MOC_LITERAL(32, 422, 24), // "on_bt_sendPacket_clicked"
QT_MOC_LITERAL(33, 447, 24), // "on_bt_autoUpdate_clicked"
QT_MOC_LITERAL(34, 472, 28), // "on_bt_stopAutoUpdate_clicked"
QT_MOC_LITERAL(35, 501, 22), // "on_bt_readBoot_clicked"
QT_MOC_LITERAL(36, 524, 26), // "on_bt_readFirmware_clicked"
QT_MOC_LITERAL(37, 551, 22), // "on_bt_stopRead_clicked"
QT_MOC_LITERAL(38, 574, 23), // "on_bt_storeFile_clicked"
QT_MOC_LITERAL(39, 598, 41), // "on_comboBox_updateMode_curren..."
QT_MOC_LITERAL(40, 640, 33), // "on_shortAddr_itemSelectionCha..."
QT_MOC_LITERAL(41, 674, 39), // "on_frimwareVersion_3_currentT..."
QT_MOC_LITERAL(42, 714, 35), // "on_cb_deviceType_currentTextC..."
QT_MOC_LITERAL(43, 750, 36), // "on_cb_deviceType_currentIndex..."
QT_MOC_LITERAL(44, 787, 5), // "index"
QT_MOC_LITERAL(45, 793, 26), // "on_shortAddr_doubleClicked"
QT_MOC_LITERAL(46, 820, 21), // "on_pb_addAddr_clicked"
QT_MOC_LITERAL(47, 842, 24), // "on_pb_deleteAddr_clicked"
QT_MOC_LITERAL(48, 867, 13), // "pressUartData"
QT_MOC_LITERAL(49, 881, 13), // "NET_newListen"
QT_MOC_LITERAL(50, 895, 20), // "NET_acceptConnection"
QT_MOC_LITERAL(51, 916, 16), // "NET_displayError"
QT_MOC_LITERAL(52, 933, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(53, 962, 11), // "NET_revData"
QT_MOC_LITERAL(54, 974, 21), // "on_bt_netSend_clicked"
QT_MOC_LITERAL(55, 996, 20), // "on_bt_listen_clicked"
QT_MOC_LITERAL(56, 1017, 24), // "on_bt_stopListen_clicked"
QT_MOC_LITERAL(57, 1042, 22), // "on_bt_searchId_clicked"
QT_MOC_LITERAL(58, 1065, 24), // "on_export_idList_clicked"
QT_MOC_LITERAL(59, 1090, 19), // "on_bt_clear_clicked"
QT_MOC_LITERAL(60, 1110, 43), // "on_comunication_protocal_curr..."
QT_MOC_LITERAL(61, 1154, 24), // "on_bt_search_net_clicked"
QT_MOC_LITERAL(62, 1179, 45), // "on_localtionIdSelection_windo..."
QT_MOC_LITERAL(63, 1225, 8), // "iconText"
QT_MOC_LITERAL(64, 1234, 47), // "on_localtionIdSelection_4_win..."
QT_MOC_LITERAL(65, 1282, 40), // "on_localtionFiltId_windowIcon..."
QT_MOC_LITERAL(66, 1323, 41), // "on_localtionFiltStr_windowIco..."
QT_MOC_LITERAL(67, 1365, 30), // "on_localtionFiltId_textChanged"
QT_MOC_LITERAL(68, 1396, 31), // "on_localtionFiltStr_textChanged"
QT_MOC_LITERAL(69, 1428, 30), // "on_locationStopDisplay_clicked"
QT_MOC_LITERAL(70, 1459, 7), // "checked"
QT_MOC_LITERAL(71, 1467, 25), // "on_coolFiltId_textChanged"
QT_MOC_LITERAL(72, 1493, 26) // "on_coolFiltStr_textChanged"

    },
    "MainWindow\0about\0\0applyPortOptions\0"
    "btsendClick\0btstopsendClick\0closePort\0"
    "enabledPortBt\0openPort\0receiveMsg\0"
    "timesl\0const unsigned char*\0data\0size\0"
    "SetCurComboBState\0Crc16Bit\0"
    "unsigned short int\0const char*\0ptr\0"
    "len\0checkSum\0puchData\0transmitMsg\0"
    "intervalChange\0value\0on_File_clicked\0"
    "on_pushButton_clicked\0on_bt_openFile_clicked\0"
    "on_comboBox_updateWay_currentIndexChanged\0"
    "arg1\0on_bt_getDeviceInf_clicked\0"
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
    "on_pb_addAddr_clicked\0on_pb_deleteAddr_clicked\0"
    "pressUartData\0NET_newListen\0"
    "NET_acceptConnection\0NET_displayError\0"
    "QAbstractSocket::SocketError\0NET_revData\0"
    "on_bt_netSend_clicked\0on_bt_listen_clicked\0"
    "on_bt_stopListen_clicked\0"
    "on_bt_searchId_clicked\0on_export_idList_clicked\0"
    "on_bt_clear_clicked\0"
    "on_comunication_protocal_currentTextChanged\0"
    "on_bt_search_net_clicked\0"
    "on_localtionIdSelection_windowIconTextChanged\0"
    "iconText\0on_localtionIdSelection_4_windowIconTextChanged\0"
    "on_localtionFiltId_windowIconTextChanged\0"
    "on_localtionFiltStr_windowIconTextChanged\0"
    "on_localtionFiltId_textChanged\0"
    "on_localtionFiltStr_textChanged\0"
    "on_locationStopDisplay_clicked\0checked\0"
    "on_coolFiltId_textChanged\0"
    "on_coolFiltStr_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      56,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  294,    2, 0x08 /* Private */,
       3,    0,  295,    2, 0x08 /* Private */,
       4,    0,  296,    2, 0x08 /* Private */,
       5,    0,  297,    2, 0x08 /* Private */,
       6,    0,  298,    2, 0x08 /* Private */,
       7,    0,  299,    2, 0x08 /* Private */,
       8,    0,  300,    2, 0x08 /* Private */,
       9,    3,  301,    2, 0x08 /* Private */,
      14,    0,  308,    2, 0x08 /* Private */,
      15,    2,  309,    2, 0x08 /* Private */,
      20,    2,  314,    2, 0x08 /* Private */,
      22,    0,  319,    2, 0x08 /* Private */,
      23,    1,  320,    2, 0x08 /* Private */,
      25,    0,  323,    2, 0x08 /* Private */,
      26,    0,  324,    2, 0x08 /* Private */,
      27,    0,  325,    2, 0x08 /* Private */,
      28,    1,  326,    2, 0x08 /* Private */,
      30,    0,  329,    2, 0x08 /* Private */,
      31,    0,  330,    2, 0x08 /* Private */,
      32,    0,  331,    2, 0x08 /* Private */,
      33,    0,  332,    2, 0x08 /* Private */,
      34,    0,  333,    2, 0x08 /* Private */,
      35,    0,  334,    2, 0x08 /* Private */,
      36,    0,  335,    2, 0x08 /* Private */,
      37,    0,  336,    2, 0x08 /* Private */,
      38,    0,  337,    2, 0x08 /* Private */,
      39,    1,  338,    2, 0x08 /* Private */,
      40,    0,  341,    2, 0x08 /* Private */,
      41,    1,  342,    2, 0x08 /* Private */,
      42,    1,  345,    2, 0x08 /* Private */,
      43,    1,  348,    2, 0x08 /* Private */,
      45,    1,  351,    2, 0x08 /* Private */,
      46,    0,  354,    2, 0x08 /* Private */,
      47,    0,  355,    2, 0x08 /* Private */,
      48,    0,  356,    2, 0x08 /* Private */,
      49,    0,  357,    2, 0x08 /* Private */,
      50,    0,  358,    2, 0x08 /* Private */,
      51,    1,  359,    2, 0x08 /* Private */,
      53,    0,  362,    2, 0x08 /* Private */,
      54,    0,  363,    2, 0x08 /* Private */,
      55,    0,  364,    2, 0x08 /* Private */,
      56,    0,  365,    2, 0x08 /* Private */,
      57,    0,  366,    2, 0x08 /* Private */,
      58,    0,  367,    2, 0x08 /* Private */,
      59,    0,  368,    2, 0x08 /* Private */,
      60,    1,  369,    2, 0x08 /* Private */,
      61,    0,  372,    2, 0x08 /* Private */,
      62,    1,  373,    2, 0x08 /* Private */,
      64,    1,  376,    2, 0x08 /* Private */,
      65,    1,  379,    2, 0x08 /* Private */,
      66,    1,  382,    2, 0x08 /* Private */,
      67,    0,  385,    2, 0x08 /* Private */,
      68,    0,  386,    2, 0x08 /* Private */,
      69,    1,  387,    2, 0x08 /* Private */,
      71,    0,  390,    2, 0x08 /* Private */,
      72,    0,  391,    2, 0x08 /* Private */,

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
    QMetaType::UChar, 0x80000000 | 17, QMetaType::UShort,   21,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::Int,   44,
    QMetaType::Void, QMetaType::QModelIndex,   44,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 52,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   63,
    QMetaType::Void, QMetaType::QString,   63,
    QMetaType::Void, QMetaType::QString,   63,
    QMetaType::Void, QMetaType::QString,   63,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   70,
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
        case 10: { uchar _r = _t->checkSum((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< ushort(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< uchar*>(_a[0]) = _r; }  break;
        case 11: _t->transmitMsg(); break;
        case 12: _t->intervalChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_File_clicked(); break;
        case 14: _t->on_pushButton_clicked(); break;
        case 15: _t->on_bt_openFile_clicked(); break;
        case 16: _t->on_comboBox_updateWay_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->on_bt_getDeviceInf_clicked(); break;
        case 18: _t->on_bt_sendFirInf_clicked(); break;
        case 19: _t->on_bt_sendPacket_clicked(); break;
        case 20: _t->on_bt_autoUpdate_clicked(); break;
        case 21: _t->on_bt_stopAutoUpdate_clicked(); break;
        case 22: _t->on_bt_readBoot_clicked(); break;
        case 23: _t->on_bt_readFirmware_clicked(); break;
        case 24: _t->on_bt_stopRead_clicked(); break;
        case 25: _t->on_bt_storeFile_clicked(); break;
        case 26: _t->on_comboBox_updateMode_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 27: _t->on_shortAddr_itemSelectionChanged(); break;
        case 28: _t->on_frimwareVersion_3_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 29: _t->on_cb_deviceType_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 30: _t->on_cb_deviceType_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->on_shortAddr_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 32: _t->on_pb_addAddr_clicked(); break;
        case 33: _t->on_pb_deleteAddr_clicked(); break;
        case 34: _t->pressUartData(); break;
        case 35: _t->NET_newListen(); break;
        case 36: _t->NET_acceptConnection(); break;
        case 37: _t->NET_displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 38: _t->NET_revData(); break;
        case 39: _t->on_bt_netSend_clicked(); break;
        case 40: _t->on_bt_listen_clicked(); break;
        case 41: _t->on_bt_stopListen_clicked(); break;
        case 42: _t->on_bt_searchId_clicked(); break;
        case 43: _t->on_export_idList_clicked(); break;
        case 44: _t->on_bt_clear_clicked(); break;
        case 45: _t->on_comunication_protocal_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 46: _t->on_bt_search_net_clicked(); break;
        case 47: _t->on_localtionIdSelection_windowIconTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 48: _t->on_localtionIdSelection_4_windowIconTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 49: _t->on_localtionFiltId_windowIconTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 50: _t->on_localtionFiltStr_windowIconTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 51: _t->on_localtionFiltId_textChanged(); break;
        case 52: _t->on_localtionFiltStr_textChanged(); break;
        case 53: _t->on_locationStopDisplay_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 54: _t->on_coolFiltId_textChanged(); break;
        case 55: _t->on_coolFiltStr_textChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 37:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
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
        if (_id < 56)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 56;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 56)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 56;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

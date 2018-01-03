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
    QByteArrayData data[141];
    char stringdata0[3463];
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
QT_MOC_LITERAL(54, 974, 15), // "storeHistoryLog"
QT_MOC_LITERAL(55, 990, 21), // "on_bt_netSend_clicked"
QT_MOC_LITERAL(56, 1012, 20), // "on_bt_listen_clicked"
QT_MOC_LITERAL(57, 1033, 24), // "on_bt_stopListen_clicked"
QT_MOC_LITERAL(58, 1058, 22), // "on_bt_searchId_clicked"
QT_MOC_LITERAL(59, 1081, 24), // "on_export_idList_clicked"
QT_MOC_LITERAL(60, 1106, 19), // "on_bt_clear_clicked"
QT_MOC_LITERAL(61, 1126, 43), // "on_comunication_protocal_curr..."
QT_MOC_LITERAL(62, 1170, 24), // "on_bt_search_net_clicked"
QT_MOC_LITERAL(63, 1195, 45), // "on_localtionIdSelection_windo..."
QT_MOC_LITERAL(64, 1241, 8), // "iconText"
QT_MOC_LITERAL(65, 1250, 47), // "on_localtionIdSelection_4_win..."
QT_MOC_LITERAL(66, 1298, 40), // "on_localtionFiltId_windowIcon..."
QT_MOC_LITERAL(67, 1339, 41), // "on_localtionFiltStr_windowIco..."
QT_MOC_LITERAL(68, 1381, 30), // "on_localtionFiltId_textChanged"
QT_MOC_LITERAL(69, 1412, 31), // "on_localtionFiltStr_textChanged"
QT_MOC_LITERAL(70, 1444, 30), // "on_locationStopDisplay_clicked"
QT_MOC_LITERAL(71, 1475, 7), // "checked"
QT_MOC_LITERAL(72, 1483, 25), // "on_coolFiltId_textChanged"
QT_MOC_LITERAL(73, 1509, 26), // "on_coolFiltStr_textChanged"
QT_MOC_LITERAL(74, 1536, 20), // "on_coolGetSn_clicked"
QT_MOC_LITERAL(75, 1557, 28), // "on_coolSetRepTime_Bt_clicked"
QT_MOC_LITERAL(76, 1586, 33), // "on_coolTemVerification_Bt_cli..."
QT_MOC_LITERAL(77, 1620, 33), // "on_coolHumVerification_Bt_cli..."
QT_MOC_LITERAL(78, 1654, 21), // "on_coolDisarm_clicked"
QT_MOC_LITERAL(79, 1676, 28), // "on_coolGetTempreture_clicked"
QT_MOC_LITERAL(80, 1705, 26), // "on_coolTemAlarm_Bt_clicked"
QT_MOC_LITERAL(81, 1732, 23), // "on_coolSetSn_Bt_clicked"
QT_MOC_LITERAL(82, 1756, 31), // "on_coolTemAlarmH_Edit_destroyed"
QT_MOC_LITERAL(83, 1788, 30), // "on_networkResetIdTable_clicked"
QT_MOC_LITERAL(84, 1819, 21), // "on_bt_clearId_clicked"
QT_MOC_LITERAL(85, 1841, 27), // "on_energyFiltId_textChanged"
QT_MOC_LITERAL(86, 1869, 28), // "on_energyFiltStr_textChanged"
QT_MOC_LITERAL(87, 1898, 31), // "on_energyGetMeasurement_clicked"
QT_MOC_LITERAL(88, 1930, 30), // "on_energySetRepTime_Bt_clicked"
QT_MOC_LITERAL(89, 1961, 19), // "on_StoreDir_clicked"
QT_MOC_LITERAL(90, 1981, 30), // "on_shortAddr_currentRowChanged"
QT_MOC_LITERAL(91, 2012, 10), // "currentRow"
QT_MOC_LITERAL(92, 2023, 24), // "on_shortAddr_itemChanged"
QT_MOC_LITERAL(93, 2048, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(94, 2065, 4), // "item"
QT_MOC_LITERAL(95, 2070, 22), // "on_shortAddr_activated"
QT_MOC_LITERAL(96, 2093, 26), // "on_shortAddr_itemActivated"
QT_MOC_LITERAL(97, 2120, 30), // "on_bt_setHeartBeatTime_clicked"
QT_MOC_LITERAL(98, 2151, 31), // "on_injectionTemAlarm_Bt_clicked"
QT_MOC_LITERAL(99, 2183, 28), // "on_injectionSetSn_Bt_clicked"
QT_MOC_LITERAL(100, 2212, 33), // "on_injectionSetRepTime_Bt_cli..."
QT_MOC_LITERAL(101, 2246, 25), // "on_injectionGetSn_clicked"
QT_MOC_LITERAL(102, 2272, 33), // "on_injectionSetSpeaker_Bt_cli..."
QT_MOC_LITERAL(103, 2306, 30), // "on_injectionFiltId_textChanged"
QT_MOC_LITERAL(104, 2337, 31), // "on_injectionFiltStr_textChanged"
QT_MOC_LITERAL(105, 2369, 27), // "on_sosSetRepTime_Bt_clicked"
QT_MOC_LITERAL(106, 2397, 25), // "on_sosFiltStr_textChanged"
QT_MOC_LITERAL(107, 2423, 24), // "on_sosFiltId_textChanged"
QT_MOC_LITERAL(108, 2448, 28), // "on_injectionStart_Bt_clicked"
QT_MOC_LITERAL(109, 2477, 27), // "on_injectionStop_Bt_clicked"
QT_MOC_LITERAL(110, 2505, 29), // "on_injectionFinish_Bt_clicked"
QT_MOC_LITERAL(111, 2535, 33), // "on_injectionSetTotalDi_Bt_cli..."
QT_MOC_LITERAL(112, 2569, 37), // "on_injectionSetStopTimeOut_Bt..."
QT_MOC_LITERAL(113, 2607, 42), // "on_injectionGetDeviceParamete..."
QT_MOC_LITERAL(114, 2650, 29), // "on_injectionDiInit_Bt_clicked"
QT_MOC_LITERAL(115, 2680, 28), // "on_injectionSetDi_Bt_clicked"
QT_MOC_LITERAL(116, 2709, 30), // "on_injectionSetName_Bt_clicked"
QT_MOC_LITERAL(117, 2740, 26), // "on_export_idList_2_clicked"
QT_MOC_LITERAL(118, 2767, 26), // "on_export_idList_3_clicked"
QT_MOC_LITERAL(119, 2794, 35), // "on_pushButton_requestNetPar_c..."
QT_MOC_LITERAL(120, 2830, 31), // "on_pushButton_setNetPar_clicked"
QT_MOC_LITERAL(121, 2862, 32), // "on_localtionFiltId_1_textChanged"
QT_MOC_LITERAL(122, 2895, 32), // "on_localtionFiltId_2_textChanged"
QT_MOC_LITERAL(123, 2928, 32), // "on_localtionFiltId_3_textChanged"
QT_MOC_LITERAL(124, 2961, 32), // "on_localtionFiltId_4_textChanged"
QT_MOC_LITERAL(125, 2994, 32), // "on_bt_setHeartBeatTime_3_clicked"
QT_MOC_LITERAL(126, 3027, 25), // "on_BLE_FiltId_textChanged"
QT_MOC_LITERAL(127, 3053, 27), // "on_BLE_FiltId_1_textChanged"
QT_MOC_LITERAL(128, 3081, 27), // "on_BLE_FiltId_2_textChanged"
QT_MOC_LITERAL(129, 3109, 27), // "on_BLE_FiltId_3_textChanged"
QT_MOC_LITERAL(130, 3137, 27), // "on_BLE_FiltId_4_textChanged"
QT_MOC_LITERAL(131, 3165, 26), // "on_BLE_FiltStr_textChanged"
QT_MOC_LITERAL(132, 3192, 21), // "on_BLE_addAnt_clicked"
QT_MOC_LITERAL(133, 3214, 24), // "on_BLE_deleteAnt_clicked"
QT_MOC_LITERAL(134, 3239, 27), // "on_BLE__set125KRssi_clicked"
QT_MOC_LITERAL(135, 3267, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(136, 3300, 28), // "on_BLE_showDeviceInf_clicked"
QT_MOC_LITERAL(137, 3329, 28), // "on_BLE_hideDeviceInf_clicked"
QT_MOC_LITERAL(138, 3358, 31), // "on_BLE_showAllDeviceInf_clicked"
QT_MOC_LITERAL(139, 3390, 31), // "on_BLE_hideAllDeviceInf_clicked"
QT_MOC_LITERAL(140, 3422, 40) // "on_BLE_rssiCalculatorSlider_v..."

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
    "storeHistoryLog\0on_bt_netSend_clicked\0"
    "on_bt_listen_clicked\0on_bt_stopListen_clicked\0"
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
    "on_coolFiltStr_textChanged\0"
    "on_coolGetSn_clicked\0on_coolSetRepTime_Bt_clicked\0"
    "on_coolTemVerification_Bt_clicked\0"
    "on_coolHumVerification_Bt_clicked\0"
    "on_coolDisarm_clicked\0"
    "on_coolGetTempreture_clicked\0"
    "on_coolTemAlarm_Bt_clicked\0"
    "on_coolSetSn_Bt_clicked\0"
    "on_coolTemAlarmH_Edit_destroyed\0"
    "on_networkResetIdTable_clicked\0"
    "on_bt_clearId_clicked\0on_energyFiltId_textChanged\0"
    "on_energyFiltStr_textChanged\0"
    "on_energyGetMeasurement_clicked\0"
    "on_energySetRepTime_Bt_clicked\0"
    "on_StoreDir_clicked\0on_shortAddr_currentRowChanged\0"
    "currentRow\0on_shortAddr_itemChanged\0"
    "QListWidgetItem*\0item\0on_shortAddr_activated\0"
    "on_shortAddr_itemActivated\0"
    "on_bt_setHeartBeatTime_clicked\0"
    "on_injectionTemAlarm_Bt_clicked\0"
    "on_injectionSetSn_Bt_clicked\0"
    "on_injectionSetRepTime_Bt_clicked\0"
    "on_injectionGetSn_clicked\0"
    "on_injectionSetSpeaker_Bt_clicked\0"
    "on_injectionFiltId_textChanged\0"
    "on_injectionFiltStr_textChanged\0"
    "on_sosSetRepTime_Bt_clicked\0"
    "on_sosFiltStr_textChanged\0"
    "on_sosFiltId_textChanged\0"
    "on_injectionStart_Bt_clicked\0"
    "on_injectionStop_Bt_clicked\0"
    "on_injectionFinish_Bt_clicked\0"
    "on_injectionSetTotalDi_Bt_clicked\0"
    "on_injectionSetStopTimeOut_Bt_clicked\0"
    "on_injectionGetDeviceParameters_Bt_clicked\0"
    "on_injectionDiInit_Bt_clicked\0"
    "on_injectionSetDi_Bt_clicked\0"
    "on_injectionSetName_Bt_clicked\0"
    "on_export_idList_2_clicked\0"
    "on_export_idList_3_clicked\0"
    "on_pushButton_requestNetPar_clicked\0"
    "on_pushButton_setNetPar_clicked\0"
    "on_localtionFiltId_1_textChanged\0"
    "on_localtionFiltId_2_textChanged\0"
    "on_localtionFiltId_3_textChanged\0"
    "on_localtionFiltId_4_textChanged\0"
    "on_bt_setHeartBeatTime_3_clicked\0"
    "on_BLE_FiltId_textChanged\0"
    "on_BLE_FiltId_1_textChanged\0"
    "on_BLE_FiltId_2_textChanged\0"
    "on_BLE_FiltId_3_textChanged\0"
    "on_BLE_FiltId_4_textChanged\0"
    "on_BLE_FiltStr_textChanged\0"
    "on_BLE_addAnt_clicked\0on_BLE_deleteAnt_clicked\0"
    "on_BLE__set125KRssi_clicked\0"
    "on_horizontalSlider_valueChanged\0"
    "on_BLE_showDeviceInf_clicked\0"
    "on_BLE_hideDeviceInf_clicked\0"
    "on_BLE_showAllDeviceInf_clicked\0"
    "on_BLE_hideAllDeviceInf_clicked\0"
    "on_BLE_rssiCalculatorSlider_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
     121,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  619,    2, 0x08 /* Private */,
       3,    0,  620,    2, 0x08 /* Private */,
       4,    0,  621,    2, 0x08 /* Private */,
       5,    0,  622,    2, 0x08 /* Private */,
       6,    0,  623,    2, 0x08 /* Private */,
       7,    0,  624,    2, 0x08 /* Private */,
       8,    0,  625,    2, 0x08 /* Private */,
       9,    3,  626,    2, 0x08 /* Private */,
      14,    0,  633,    2, 0x08 /* Private */,
      15,    2,  634,    2, 0x08 /* Private */,
      20,    2,  639,    2, 0x08 /* Private */,
      22,    0,  644,    2, 0x08 /* Private */,
      23,    1,  645,    2, 0x08 /* Private */,
      25,    0,  648,    2, 0x08 /* Private */,
      26,    0,  649,    2, 0x08 /* Private */,
      27,    0,  650,    2, 0x08 /* Private */,
      28,    1,  651,    2, 0x08 /* Private */,
      30,    0,  654,    2, 0x08 /* Private */,
      31,    0,  655,    2, 0x08 /* Private */,
      32,    0,  656,    2, 0x08 /* Private */,
      33,    0,  657,    2, 0x08 /* Private */,
      34,    0,  658,    2, 0x08 /* Private */,
      35,    0,  659,    2, 0x08 /* Private */,
      36,    0,  660,    2, 0x08 /* Private */,
      37,    0,  661,    2, 0x08 /* Private */,
      38,    0,  662,    2, 0x08 /* Private */,
      39,    1,  663,    2, 0x08 /* Private */,
      40,    0,  666,    2, 0x08 /* Private */,
      41,    1,  667,    2, 0x08 /* Private */,
      42,    1,  670,    2, 0x08 /* Private */,
      43,    1,  673,    2, 0x08 /* Private */,
      45,    1,  676,    2, 0x08 /* Private */,
      46,    0,  679,    2, 0x08 /* Private */,
      47,    0,  680,    2, 0x08 /* Private */,
      48,    0,  681,    2, 0x08 /* Private */,
      49,    0,  682,    2, 0x08 /* Private */,
      50,    0,  683,    2, 0x08 /* Private */,
      51,    1,  684,    2, 0x08 /* Private */,
      53,    0,  687,    2, 0x08 /* Private */,
      54,    0,  688,    2, 0x08 /* Private */,
      55,    0,  689,    2, 0x08 /* Private */,
      56,    0,  690,    2, 0x08 /* Private */,
      57,    0,  691,    2, 0x08 /* Private */,
      58,    0,  692,    2, 0x08 /* Private */,
      59,    0,  693,    2, 0x08 /* Private */,
      60,    0,  694,    2, 0x08 /* Private */,
      61,    1,  695,    2, 0x08 /* Private */,
      62,    0,  698,    2, 0x08 /* Private */,
      63,    1,  699,    2, 0x08 /* Private */,
      65,    1,  702,    2, 0x08 /* Private */,
      66,    1,  705,    2, 0x08 /* Private */,
      67,    1,  708,    2, 0x08 /* Private */,
      68,    0,  711,    2, 0x08 /* Private */,
      69,    0,  712,    2, 0x08 /* Private */,
      70,    1,  713,    2, 0x08 /* Private */,
      72,    0,  716,    2, 0x08 /* Private */,
      73,    0,  717,    2, 0x08 /* Private */,
      74,    0,  718,    2, 0x08 /* Private */,
      75,    0,  719,    2, 0x08 /* Private */,
      76,    0,  720,    2, 0x08 /* Private */,
      77,    0,  721,    2, 0x08 /* Private */,
      78,    0,  722,    2, 0x08 /* Private */,
      79,    0,  723,    2, 0x08 /* Private */,
      80,    0,  724,    2, 0x08 /* Private */,
      81,    0,  725,    2, 0x08 /* Private */,
      82,    0,  726,    2, 0x08 /* Private */,
      83,    0,  727,    2, 0x08 /* Private */,
      84,    0,  728,    2, 0x08 /* Private */,
      85,    0,  729,    2, 0x08 /* Private */,
      86,    0,  730,    2, 0x08 /* Private */,
      87,    0,  731,    2, 0x08 /* Private */,
      88,    0,  732,    2, 0x08 /* Private */,
      89,    0,  733,    2, 0x08 /* Private */,
      90,    1,  734,    2, 0x08 /* Private */,
      92,    1,  737,    2, 0x08 /* Private */,
      95,    1,  740,    2, 0x08 /* Private */,
      96,    1,  743,    2, 0x08 /* Private */,
      97,    0,  746,    2, 0x08 /* Private */,
      98,    0,  747,    2, 0x08 /* Private */,
      99,    0,  748,    2, 0x08 /* Private */,
     100,    0,  749,    2, 0x08 /* Private */,
     101,    0,  750,    2, 0x08 /* Private */,
     102,    0,  751,    2, 0x08 /* Private */,
     103,    0,  752,    2, 0x08 /* Private */,
     104,    0,  753,    2, 0x08 /* Private */,
     105,    0,  754,    2, 0x08 /* Private */,
     106,    0,  755,    2, 0x08 /* Private */,
     107,    0,  756,    2, 0x08 /* Private */,
     108,    0,  757,    2, 0x08 /* Private */,
     109,    0,  758,    2, 0x08 /* Private */,
     110,    0,  759,    2, 0x08 /* Private */,
     111,    0,  760,    2, 0x08 /* Private */,
     112,    0,  761,    2, 0x08 /* Private */,
     113,    0,  762,    2, 0x08 /* Private */,
     114,    0,  763,    2, 0x08 /* Private */,
     115,    0,  764,    2, 0x08 /* Private */,
     116,    0,  765,    2, 0x08 /* Private */,
     117,    0,  766,    2, 0x08 /* Private */,
     118,    0,  767,    2, 0x08 /* Private */,
     119,    0,  768,    2, 0x08 /* Private */,
     120,    0,  769,    2, 0x08 /* Private */,
     121,    0,  770,    2, 0x08 /* Private */,
     122,    0,  771,    2, 0x08 /* Private */,
     123,    0,  772,    2, 0x08 /* Private */,
     124,    0,  773,    2, 0x08 /* Private */,
     125,    0,  774,    2, 0x08 /* Private */,
     126,    0,  775,    2, 0x08 /* Private */,
     127,    0,  776,    2, 0x08 /* Private */,
     128,    0,  777,    2, 0x08 /* Private */,
     129,    0,  778,    2, 0x08 /* Private */,
     130,    0,  779,    2, 0x08 /* Private */,
     131,    0,  780,    2, 0x08 /* Private */,
     132,    0,  781,    2, 0x08 /* Private */,
     133,    0,  782,    2, 0x08 /* Private */,
     134,    0,  783,    2, 0x08 /* Private */,
     135,    1,  784,    2, 0x08 /* Private */,
     136,    0,  787,    2, 0x08 /* Private */,
     137,    0,  788,    2, 0x08 /* Private */,
     138,    0,  789,    2, 0x08 /* Private */,
     139,    0,  790,    2, 0x08 /* Private */,
     140,    1,  791,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   64,
    QMetaType::Void, QMetaType::QString,   64,
    QMetaType::Void, QMetaType::QString,   64,
    QMetaType::Void, QMetaType::QString,   64,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   71,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   91,
    QMetaType::Void, 0x80000000 | 93,   94,
    QMetaType::Void, QMetaType::QModelIndex,   44,
    QMetaType::Void, 0x80000000 | 93,   94,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   24,

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
        case 39: _t->storeHistoryLog(); break;
        case 40: _t->on_bt_netSend_clicked(); break;
        case 41: _t->on_bt_listen_clicked(); break;
        case 42: _t->on_bt_stopListen_clicked(); break;
        case 43: _t->on_bt_searchId_clicked(); break;
        case 44: _t->on_export_idList_clicked(); break;
        case 45: _t->on_bt_clear_clicked(); break;
        case 46: _t->on_comunication_protocal_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 47: _t->on_bt_search_net_clicked(); break;
        case 48: _t->on_localtionIdSelection_windowIconTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 49: _t->on_localtionIdSelection_4_windowIconTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 50: _t->on_localtionFiltId_windowIconTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 51: _t->on_localtionFiltStr_windowIconTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 52: _t->on_localtionFiltId_textChanged(); break;
        case 53: _t->on_localtionFiltStr_textChanged(); break;
        case 54: _t->on_locationStopDisplay_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 55: _t->on_coolFiltId_textChanged(); break;
        case 56: _t->on_coolFiltStr_textChanged(); break;
        case 57: _t->on_coolGetSn_clicked(); break;
        case 58: _t->on_coolSetRepTime_Bt_clicked(); break;
        case 59: _t->on_coolTemVerification_Bt_clicked(); break;
        case 60: _t->on_coolHumVerification_Bt_clicked(); break;
        case 61: _t->on_coolDisarm_clicked(); break;
        case 62: _t->on_coolGetTempreture_clicked(); break;
        case 63: _t->on_coolTemAlarm_Bt_clicked(); break;
        case 64: _t->on_coolSetSn_Bt_clicked(); break;
        case 65: _t->on_coolTemAlarmH_Edit_destroyed(); break;
        case 66: _t->on_networkResetIdTable_clicked(); break;
        case 67: _t->on_bt_clearId_clicked(); break;
        case 68: _t->on_energyFiltId_textChanged(); break;
        case 69: _t->on_energyFiltStr_textChanged(); break;
        case 70: _t->on_energyGetMeasurement_clicked(); break;
        case 71: _t->on_energySetRepTime_Bt_clicked(); break;
        case 72: _t->on_StoreDir_clicked(); break;
        case 73: _t->on_shortAddr_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 74: _t->on_shortAddr_itemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 75: _t->on_shortAddr_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 76: _t->on_shortAddr_itemActivated((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 77: _t->on_bt_setHeartBeatTime_clicked(); break;
        case 78: _t->on_injectionTemAlarm_Bt_clicked(); break;
        case 79: _t->on_injectionSetSn_Bt_clicked(); break;
        case 80: _t->on_injectionSetRepTime_Bt_clicked(); break;
        case 81: _t->on_injectionGetSn_clicked(); break;
        case 82: _t->on_injectionSetSpeaker_Bt_clicked(); break;
        case 83: _t->on_injectionFiltId_textChanged(); break;
        case 84: _t->on_injectionFiltStr_textChanged(); break;
        case 85: _t->on_sosSetRepTime_Bt_clicked(); break;
        case 86: _t->on_sosFiltStr_textChanged(); break;
        case 87: _t->on_sosFiltId_textChanged(); break;
        case 88: _t->on_injectionStart_Bt_clicked(); break;
        case 89: _t->on_injectionStop_Bt_clicked(); break;
        case 90: _t->on_injectionFinish_Bt_clicked(); break;
        case 91: _t->on_injectionSetTotalDi_Bt_clicked(); break;
        case 92: _t->on_injectionSetStopTimeOut_Bt_clicked(); break;
        case 93: _t->on_injectionGetDeviceParameters_Bt_clicked(); break;
        case 94: _t->on_injectionDiInit_Bt_clicked(); break;
        case 95: _t->on_injectionSetDi_Bt_clicked(); break;
        case 96: _t->on_injectionSetName_Bt_clicked(); break;
        case 97: _t->on_export_idList_2_clicked(); break;
        case 98: _t->on_export_idList_3_clicked(); break;
        case 99: _t->on_pushButton_requestNetPar_clicked(); break;
        case 100: _t->on_pushButton_setNetPar_clicked(); break;
        case 101: _t->on_localtionFiltId_1_textChanged(); break;
        case 102: _t->on_localtionFiltId_2_textChanged(); break;
        case 103: _t->on_localtionFiltId_3_textChanged(); break;
        case 104: _t->on_localtionFiltId_4_textChanged(); break;
        case 105: _t->on_bt_setHeartBeatTime_3_clicked(); break;
        case 106: _t->on_BLE_FiltId_textChanged(); break;
        case 107: _t->on_BLE_FiltId_1_textChanged(); break;
        case 108: _t->on_BLE_FiltId_2_textChanged(); break;
        case 109: _t->on_BLE_FiltId_3_textChanged(); break;
        case 110: _t->on_BLE_FiltId_4_textChanged(); break;
        case 111: _t->on_BLE_FiltStr_textChanged(); break;
        case 112: _t->on_BLE_addAnt_clicked(); break;
        case 113: _t->on_BLE_deleteAnt_clicked(); break;
        case 114: _t->on_BLE__set125KRssi_clicked(); break;
        case 115: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 116: _t->on_BLE_showDeviceInf_clicked(); break;
        case 117: _t->on_BLE_hideDeviceInf_clicked(); break;
        case 118: _t->on_BLE_showAllDeviceInf_clicked(); break;
        case 119: _t->on_BLE_hideAllDeviceInf_clicked(); break;
        case 120: _t->on_BLE_rssiCalculatorSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        if (_id < 121)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 121;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 121)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 121;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

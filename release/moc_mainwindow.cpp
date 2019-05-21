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
    QByteArrayData data[140];
    char stringdata0[3646];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 8), // "Crc16Bit"
QT_MOC_LITERAL(2, 20, 18), // "unsigned short int"
QT_MOC_LITERAL(3, 39, 0), // ""
QT_MOC_LITERAL(4, 40, 11), // "const char*"
QT_MOC_LITERAL(5, 52, 3), // "ptr"
QT_MOC_LITERAL(6, 56, 3), // "len"
QT_MOC_LITERAL(7, 60, 8), // "checkSum"
QT_MOC_LITERAL(8, 69, 8), // "puchData"
QT_MOC_LITERAL(9, 78, 22), // "on_bt_openFile_clicked"
QT_MOC_LITERAL(10, 101, 26), // "on_bt_getDeviceInf_clicked"
QT_MOC_LITERAL(11, 128, 24), // "on_bt_sendFirInf_clicked"
QT_MOC_LITERAL(12, 153, 24), // "on_bt_sendPacket_clicked"
QT_MOC_LITERAL(13, 178, 24), // "on_bt_autoUpdate_clicked"
QT_MOC_LITERAL(14, 203, 28), // "on_bt_stopAutoUpdate_clicked"
QT_MOC_LITERAL(15, 232, 22), // "on_bt_readBoot_clicked"
QT_MOC_LITERAL(16, 255, 26), // "on_bt_readFirmware_clicked"
QT_MOC_LITERAL(17, 282, 22), // "on_bt_stopRead_clicked"
QT_MOC_LITERAL(18, 305, 23), // "on_bt_storeFile_clicked"
QT_MOC_LITERAL(19, 329, 41), // "on_comboBox_updateMode_curren..."
QT_MOC_LITERAL(20, 371, 4), // "arg1"
QT_MOC_LITERAL(21, 376, 33), // "on_shortAddr_itemSelectionCha..."
QT_MOC_LITERAL(22, 410, 39), // "on_frimwareVersion_3_currentT..."
QT_MOC_LITERAL(23, 450, 35), // "on_cb_deviceType_currentTextC..."
QT_MOC_LITERAL(24, 486, 36), // "on_cb_deviceType_currentIndex..."
QT_MOC_LITERAL(25, 523, 5), // "index"
QT_MOC_LITERAL(26, 529, 26), // "on_shortAddr_doubleClicked"
QT_MOC_LITERAL(27, 556, 21), // "on_pb_addAddr_clicked"
QT_MOC_LITERAL(28, 578, 24), // "on_pb_deleteAddr_clicked"
QT_MOC_LITERAL(29, 603, 13), // "pressUartData"
QT_MOC_LITERAL(30, 617, 11), // "QTcpSocket*"
QT_MOC_LITERAL(31, 629, 6), // "socket"
QT_MOC_LITERAL(32, 636, 13), // "NET_newListen"
QT_MOC_LITERAL(33, 650, 20), // "NET_acceptConnection"
QT_MOC_LITERAL(34, 671, 16), // "NET_displayError"
QT_MOC_LITERAL(35, 688, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(36, 717, 11), // "NET_revData"
QT_MOC_LITERAL(37, 729, 21), // "NET_newListenLocation"
QT_MOC_LITERAL(38, 751, 28), // "NET_acceptConnectionLocation"
QT_MOC_LITERAL(39, 780, 19), // "NET_revDataLocation"
QT_MOC_LITERAL(40, 800, 22), // "BLE_locationCalculator"
QT_MOC_LITERAL(41, 823, 2), // "id"
QT_MOC_LITERAL(42, 826, 15), // "storeHistoryLog"
QT_MOC_LITERAL(43, 842, 21), // "on_bt_netSend_clicked"
QT_MOC_LITERAL(44, 864, 20), // "on_bt_listen_clicked"
QT_MOC_LITERAL(45, 885, 24), // "on_bt_stopListen_clicked"
QT_MOC_LITERAL(46, 910, 22), // "on_bt_searchId_clicked"
QT_MOC_LITERAL(47, 933, 24), // "on_export_idList_clicked"
QT_MOC_LITERAL(48, 958, 19), // "on_bt_clear_clicked"
QT_MOC_LITERAL(49, 978, 43), // "on_comunication_protocal_curr..."
QT_MOC_LITERAL(50, 1022, 24), // "on_bt_search_net_clicked"
QT_MOC_LITERAL(51, 1047, 30), // "on_localtionFiltId_textChanged"
QT_MOC_LITERAL(52, 1078, 31), // "on_localtionFiltStr_textChanged"
QT_MOC_LITERAL(53, 1110, 25), // "on_coolFiltId_textChanged"
QT_MOC_LITERAL(54, 1136, 26), // "on_coolFiltStr_textChanged"
QT_MOC_LITERAL(55, 1163, 20), // "on_coolGetSn_clicked"
QT_MOC_LITERAL(56, 1184, 28), // "on_coolSetRepTime_Bt_clicked"
QT_MOC_LITERAL(57, 1213, 33), // "on_coolTemVerification_Bt_cli..."
QT_MOC_LITERAL(58, 1247, 33), // "on_coolHumVerification_Bt_cli..."
QT_MOC_LITERAL(59, 1281, 21), // "on_coolDisarm_clicked"
QT_MOC_LITERAL(60, 1303, 28), // "on_coolGetTempreture_clicked"
QT_MOC_LITERAL(61, 1332, 26), // "on_coolTemAlarm_Bt_clicked"
QT_MOC_LITERAL(62, 1359, 23), // "on_coolSetSn_Bt_clicked"
QT_MOC_LITERAL(63, 1383, 31), // "on_coolTemAlarmH_Edit_destroyed"
QT_MOC_LITERAL(64, 1415, 30), // "on_networkResetIdTable_clicked"
QT_MOC_LITERAL(65, 1446, 21), // "on_bt_clearId_clicked"
QT_MOC_LITERAL(66, 1468, 27), // "on_energyFiltId_textChanged"
QT_MOC_LITERAL(67, 1496, 28), // "on_energyFiltStr_textChanged"
QT_MOC_LITERAL(68, 1525, 31), // "on_energyGetMeasurement_clicked"
QT_MOC_LITERAL(69, 1557, 30), // "on_energySetRepTime_Bt_clicked"
QT_MOC_LITERAL(70, 1588, 19), // "on_StoreDir_clicked"
QT_MOC_LITERAL(71, 1608, 30), // "on_shortAddr_currentRowChanged"
QT_MOC_LITERAL(72, 1639, 10), // "currentRow"
QT_MOC_LITERAL(73, 1650, 24), // "on_shortAddr_itemChanged"
QT_MOC_LITERAL(74, 1675, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(75, 1692, 4), // "item"
QT_MOC_LITERAL(76, 1697, 22), // "on_shortAddr_activated"
QT_MOC_LITERAL(77, 1720, 26), // "on_shortAddr_itemActivated"
QT_MOC_LITERAL(78, 1747, 30), // "on_bt_setHeartBeatTime_clicked"
QT_MOC_LITERAL(79, 1778, 31), // "on_injectionTemAlarm_Bt_clicked"
QT_MOC_LITERAL(80, 1810, 28), // "on_injectionSetSn_Bt_clicked"
QT_MOC_LITERAL(81, 1839, 33), // "on_injectionSetRepTime_Bt_cli..."
QT_MOC_LITERAL(82, 1873, 25), // "on_injectionGetSn_clicked"
QT_MOC_LITERAL(83, 1899, 33), // "on_injectionSetSpeaker_Bt_cli..."
QT_MOC_LITERAL(84, 1933, 30), // "on_injectionFiltId_textChanged"
QT_MOC_LITERAL(85, 1964, 31), // "on_injectionFiltStr_textChanged"
QT_MOC_LITERAL(86, 1996, 27), // "on_sosSetRepTime_Bt_clicked"
QT_MOC_LITERAL(87, 2024, 25), // "on_sosFiltStr_textChanged"
QT_MOC_LITERAL(88, 2050, 24), // "on_sosFiltId_textChanged"
QT_MOC_LITERAL(89, 2075, 28), // "on_injectionStart_Bt_clicked"
QT_MOC_LITERAL(90, 2104, 27), // "on_injectionStop_Bt_clicked"
QT_MOC_LITERAL(91, 2132, 29), // "on_injectionFinish_Bt_clicked"
QT_MOC_LITERAL(92, 2162, 33), // "on_injectionSetTotalDi_Bt_cli..."
QT_MOC_LITERAL(93, 2196, 37), // "on_injectionSetStopTimeOut_Bt..."
QT_MOC_LITERAL(94, 2234, 42), // "on_injectionGetDeviceParamete..."
QT_MOC_LITERAL(95, 2277, 29), // "on_injectionDiInit_Bt_clicked"
QT_MOC_LITERAL(96, 2307, 28), // "on_injectionSetDi_Bt_clicked"
QT_MOC_LITERAL(97, 2336, 30), // "on_injectionSetName_Bt_clicked"
QT_MOC_LITERAL(98, 2367, 26), // "on_export_idList_2_clicked"
QT_MOC_LITERAL(99, 2394, 26), // "on_export_idList_3_clicked"
QT_MOC_LITERAL(100, 2421, 35), // "on_pushButton_requestNetPar_c..."
QT_MOC_LITERAL(101, 2457, 31), // "on_pushButton_setNetPar_clicked"
QT_MOC_LITERAL(102, 2489, 32), // "on_localtionFiltId_1_textChanged"
QT_MOC_LITERAL(103, 2522, 32), // "on_localtionFiltId_2_textChanged"
QT_MOC_LITERAL(104, 2555, 32), // "on_localtionFiltId_3_textChanged"
QT_MOC_LITERAL(105, 2588, 32), // "on_localtionFiltId_4_textChanged"
QT_MOC_LITERAL(106, 2621, 32), // "on_bt_setHeartBeatTime_3_clicked"
QT_MOC_LITERAL(107, 2654, 25), // "on_BLE_FiltId_textChanged"
QT_MOC_LITERAL(108, 2680, 27), // "on_BLE_FiltId_1_textChanged"
QT_MOC_LITERAL(109, 2708, 27), // "on_BLE_FiltId_2_textChanged"
QT_MOC_LITERAL(110, 2736, 27), // "on_BLE_FiltId_3_textChanged"
QT_MOC_LITERAL(111, 2764, 27), // "on_BLE_FiltId_4_textChanged"
QT_MOC_LITERAL(112, 2792, 26), // "on_BLE_FiltStr_textChanged"
QT_MOC_LITERAL(113, 2819, 21), // "on_BLE_addAnt_clicked"
QT_MOC_LITERAL(114, 2841, 24), // "on_BLE_deleteAnt_clicked"
QT_MOC_LITERAL(115, 2866, 27), // "on_BLE__set125KRssi_clicked"
QT_MOC_LITERAL(116, 2894, 32), // "on_horizontalSlider_valueChanged"
QT_MOC_LITERAL(117, 2927, 5), // "value"
QT_MOC_LITERAL(118, 2933, 28), // "on_BLE_showDeviceInf_clicked"
QT_MOC_LITERAL(119, 2962, 28), // "on_BLE_hideDeviceInf_clicked"
QT_MOC_LITERAL(120, 2991, 31), // "on_BLE_showAllDeviceInf_clicked"
QT_MOC_LITERAL(121, 3023, 31), // "on_BLE_hideAllDeviceInf_clicked"
QT_MOC_LITERAL(122, 3055, 40), // "on_BLE_rssiCalculatorSlider_v..."
QT_MOC_LITERAL(123, 3096, 31), // "on_BLE_virtualRatio_textChanged"
QT_MOC_LITERAL(124, 3128, 29), // "on_bt_listen_location_clicked"
QT_MOC_LITERAL(125, 3158, 33), // "on_bt_stopListen_location_cli..."
QT_MOC_LITERAL(126, 3192, 30), // "on_BLE_setAlgorithmPar_clicked"
QT_MOC_LITERAL(127, 3223, 26), // "on_BLE_sendAntList_clicked"
QT_MOC_LITERAL(128, 3250, 30), // "on_textEdit_MIN_ID_textChanged"
QT_MOC_LITERAL(129, 3281, 30), // "on_textEdit_MAX_ID_textChanged"
QT_MOC_LITERAL(130, 3312, 26), // "on_TemTHFiltId_textChanged"
QT_MOC_LITERAL(131, 3339, 27), // "on_TemTHFiltStr_textChanged"
QT_MOC_LITERAL(132, 3367, 29), // "on_TemTHSetRepTime_Bt_clicked"
QT_MOC_LITERAL(133, 3397, 36), // "on_checkBox_productTest_state..."
QT_MOC_LITERAL(134, 3434, 33), // "on_checkBox_125KTest_stateCha..."
QT_MOC_LITERAL(135, 3468, 24), // "on_bt_setDevRssi_clicked"
QT_MOC_LITERAL(136, 3493, 38), // "on_pushButton_setHeartRateTim..."
QT_MOC_LITERAL(137, 3532, 43), // "on_cb_deviceTypeLocation_curr..."
QT_MOC_LITERAL(138, 3576, 34), // "on_TemTHTemVerification_Bt_cl..."
QT_MOC_LITERAL(139, 3611, 34) // "on_TemTHHumVerification_Bt_cl..."

    },
    "MainWindow\0Crc16Bit\0unsigned short int\0"
    "\0const char*\0ptr\0len\0checkSum\0puchData\0"
    "on_bt_openFile_clicked\0"
    "on_bt_getDeviceInf_clicked\0"
    "on_bt_sendFirInf_clicked\0"
    "on_bt_sendPacket_clicked\0"
    "on_bt_autoUpdate_clicked\0"
    "on_bt_stopAutoUpdate_clicked\0"
    "on_bt_readBoot_clicked\0"
    "on_bt_readFirmware_clicked\0"
    "on_bt_stopRead_clicked\0on_bt_storeFile_clicked\0"
    "on_comboBox_updateMode_currentTextChanged\0"
    "arg1\0on_shortAddr_itemSelectionChanged\0"
    "on_frimwareVersion_3_currentTextChanged\0"
    "on_cb_deviceType_currentTextChanged\0"
    "on_cb_deviceType_currentIndexChanged\0"
    "index\0on_shortAddr_doubleClicked\0"
    "on_pb_addAddr_clicked\0on_pb_deleteAddr_clicked\0"
    "pressUartData\0QTcpSocket*\0socket\0"
    "NET_newListen\0NET_acceptConnection\0"
    "NET_displayError\0QAbstractSocket::SocketError\0"
    "NET_revData\0NET_newListenLocation\0"
    "NET_acceptConnectionLocation\0"
    "NET_revDataLocation\0BLE_locationCalculator\0"
    "id\0storeHistoryLog\0on_bt_netSend_clicked\0"
    "on_bt_listen_clicked\0on_bt_stopListen_clicked\0"
    "on_bt_searchId_clicked\0on_export_idList_clicked\0"
    "on_bt_clear_clicked\0"
    "on_comunication_protocal_currentTextChanged\0"
    "on_bt_search_net_clicked\0"
    "on_localtionFiltId_textChanged\0"
    "on_localtionFiltStr_textChanged\0"
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
    "on_horizontalSlider_valueChanged\0value\0"
    "on_BLE_showDeviceInf_clicked\0"
    "on_BLE_hideDeviceInf_clicked\0"
    "on_BLE_showAllDeviceInf_clicked\0"
    "on_BLE_hideAllDeviceInf_clicked\0"
    "on_BLE_rssiCalculatorSlider_valueChanged\0"
    "on_BLE_virtualRatio_textChanged\0"
    "on_bt_listen_location_clicked\0"
    "on_bt_stopListen_location_clicked\0"
    "on_BLE_setAlgorithmPar_clicked\0"
    "on_BLE_sendAntList_clicked\0"
    "on_textEdit_MIN_ID_textChanged\0"
    "on_textEdit_MAX_ID_textChanged\0"
    "on_TemTHFiltId_textChanged\0"
    "on_TemTHFiltStr_textChanged\0"
    "on_TemTHSetRepTime_Bt_clicked\0"
    "on_checkBox_productTest_stateChanged\0"
    "on_checkBox_125KTest_stateChanged\0"
    "on_bt_setDevRssi_clicked\0"
    "on_pushButton_setHeartRateTime_clicked\0"
    "on_cb_deviceTypeLocation_currentTextChanged\0"
    "on_TemTHTemVerification_Bt_clicked\0"
    "on_TemTHHumVerification_Bt_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
     124,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,  634,    3, 0x08 /* Private */,
       7,    2,  639,    3, 0x08 /* Private */,
       7,    2,  644,    3, 0x08 /* Private */,
       9,    0,  649,    3, 0x08 /* Private */,
      10,    0,  650,    3, 0x08 /* Private */,
      11,    0,  651,    3, 0x08 /* Private */,
      12,    0,  652,    3, 0x08 /* Private */,
      13,    0,  653,    3, 0x08 /* Private */,
      14,    0,  654,    3, 0x08 /* Private */,
      15,    0,  655,    3, 0x08 /* Private */,
      16,    0,  656,    3, 0x08 /* Private */,
      17,    0,  657,    3, 0x08 /* Private */,
      18,    0,  658,    3, 0x08 /* Private */,
      19,    1,  659,    3, 0x08 /* Private */,
      21,    0,  662,    3, 0x08 /* Private */,
      22,    1,  663,    3, 0x08 /* Private */,
      23,    1,  666,    3, 0x08 /* Private */,
      24,    1,  669,    3, 0x08 /* Private */,
      26,    1,  672,    3, 0x08 /* Private */,
      27,    0,  675,    3, 0x08 /* Private */,
      28,    0,  676,    3, 0x08 /* Private */,
      29,    1,  677,    3, 0x08 /* Private */,
      32,    0,  680,    3, 0x08 /* Private */,
      33,    0,  681,    3, 0x08 /* Private */,
      34,    1,  682,    3, 0x08 /* Private */,
      36,    0,  685,    3, 0x08 /* Private */,
      37,    0,  686,    3, 0x08 /* Private */,
      38,    0,  687,    3, 0x08 /* Private */,
      39,    0,  688,    3, 0x08 /* Private */,
      40,    1,  689,    3, 0x08 /* Private */,
      42,    0,  692,    3, 0x08 /* Private */,
      43,    0,  693,    3, 0x08 /* Private */,
      44,    0,  694,    3, 0x08 /* Private */,
      45,    0,  695,    3, 0x08 /* Private */,
      46,    0,  696,    3, 0x08 /* Private */,
      47,    0,  697,    3, 0x08 /* Private */,
      48,    0,  698,    3, 0x08 /* Private */,
      49,    1,  699,    3, 0x08 /* Private */,
      50,    0,  702,    3, 0x08 /* Private */,
      51,    0,  703,    3, 0x08 /* Private */,
      52,    0,  704,    3, 0x08 /* Private */,
      53,    0,  705,    3, 0x08 /* Private */,
      54,    0,  706,    3, 0x08 /* Private */,
      55,    0,  707,    3, 0x08 /* Private */,
      56,    0,  708,    3, 0x08 /* Private */,
      57,    0,  709,    3, 0x08 /* Private */,
      58,    0,  710,    3, 0x08 /* Private */,
      59,    0,  711,    3, 0x08 /* Private */,
      60,    0,  712,    3, 0x08 /* Private */,
      61,    0,  713,    3, 0x08 /* Private */,
      62,    0,  714,    3, 0x08 /* Private */,
      63,    0,  715,    3, 0x08 /* Private */,
      64,    0,  716,    3, 0x08 /* Private */,
      65,    0,  717,    3, 0x08 /* Private */,
      66,    0,  718,    3, 0x08 /* Private */,
      67,    0,  719,    3, 0x08 /* Private */,
      68,    0,  720,    3, 0x08 /* Private */,
      69,    0,  721,    3, 0x08 /* Private */,
      70,    0,  722,    3, 0x08 /* Private */,
      71,    1,  723,    3, 0x08 /* Private */,
      73,    1,  726,    3, 0x08 /* Private */,
      76,    1,  729,    3, 0x08 /* Private */,
      77,    1,  732,    3, 0x08 /* Private */,
      78,    0,  735,    3, 0x08 /* Private */,
      79,    0,  736,    3, 0x08 /* Private */,
      80,    0,  737,    3, 0x08 /* Private */,
      81,    0,  738,    3, 0x08 /* Private */,
      82,    0,  739,    3, 0x08 /* Private */,
      83,    0,  740,    3, 0x08 /* Private */,
      84,    0,  741,    3, 0x08 /* Private */,
      85,    0,  742,    3, 0x08 /* Private */,
      86,    0,  743,    3, 0x08 /* Private */,
      87,    0,  744,    3, 0x08 /* Private */,
      88,    0,  745,    3, 0x08 /* Private */,
      89,    0,  746,    3, 0x08 /* Private */,
      90,    0,  747,    3, 0x08 /* Private */,
      91,    0,  748,    3, 0x08 /* Private */,
      92,    0,  749,    3, 0x08 /* Private */,
      93,    0,  750,    3, 0x08 /* Private */,
      94,    0,  751,    3, 0x08 /* Private */,
      95,    0,  752,    3, 0x08 /* Private */,
      96,    0,  753,    3, 0x08 /* Private */,
      97,    0,  754,    3, 0x08 /* Private */,
      98,    0,  755,    3, 0x08 /* Private */,
      99,    0,  756,    3, 0x08 /* Private */,
     100,    0,  757,    3, 0x08 /* Private */,
     101,    0,  758,    3, 0x08 /* Private */,
     102,    0,  759,    3, 0x08 /* Private */,
     103,    0,  760,    3, 0x08 /* Private */,
     104,    0,  761,    3, 0x08 /* Private */,
     105,    0,  762,    3, 0x08 /* Private */,
     106,    0,  763,    3, 0x08 /* Private */,
     107,    0,  764,    3, 0x08 /* Private */,
     108,    0,  765,    3, 0x08 /* Private */,
     109,    0,  766,    3, 0x08 /* Private */,
     110,    0,  767,    3, 0x08 /* Private */,
     111,    0,  768,    3, 0x08 /* Private */,
     112,    0,  769,    3, 0x08 /* Private */,
     113,    0,  770,    3, 0x08 /* Private */,
     114,    0,  771,    3, 0x08 /* Private */,
     115,    0,  772,    3, 0x08 /* Private */,
     116,    1,  773,    3, 0x08 /* Private */,
     118,    0,  776,    3, 0x08 /* Private */,
     119,    0,  777,    3, 0x08 /* Private */,
     120,    0,  778,    3, 0x08 /* Private */,
     121,    0,  779,    3, 0x08 /* Private */,
     122,    1,  780,    3, 0x08 /* Private */,
     123,    0,  783,    3, 0x08 /* Private */,
     124,    0,  784,    3, 0x08 /* Private */,
     125,    0,  785,    3, 0x08 /* Private */,
     126,    0,  786,    3, 0x08 /* Private */,
     127,    0,  787,    3, 0x08 /* Private */,
     128,    0,  788,    3, 0x08 /* Private */,
     129,    0,  789,    3, 0x08 /* Private */,
     130,    0,  790,    3, 0x08 /* Private */,
     131,    0,  791,    3, 0x08 /* Private */,
     132,    0,  792,    3, 0x08 /* Private */,
     133,    1,  793,    3, 0x08 /* Private */,
     134,    1,  796,    3, 0x08 /* Private */,
     135,    0,  799,    3, 0x08 /* Private */,
     136,    0,  800,    3, 0x08 /* Private */,
     137,    1,  801,    3, 0x08 /* Private */,
     138,    0,  804,    3, 0x08 /* Private */,
     139,    0,  805,    3, 0x08 /* Private */,

 // slots: parameters
    0x80000000 | 2, 0x80000000 | 4, 0x80000000 | 2,    5,    6,
    QMetaType::UChar, 0x80000000 | 4, QMetaType::UShort,    8,    6,
    QMetaType::UChar, QMetaType::QByteArray, QMetaType::UShort,    8,    6,
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
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::QModelIndex,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 30,   31,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 35,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UShort,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,
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
    QMetaType::Void, QMetaType::Int,   72,
    QMetaType::Void, 0x80000000 | 74,   75,
    QMetaType::Void, QMetaType::QModelIndex,   25,
    QMetaType::Void, 0x80000000 | 74,   75,
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
    QMetaType::Void, QMetaType::Int,  117,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  117,
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
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,
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
        case 0: { unsigned short int _r = _t->Crc16Bit((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< unsigned short int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< unsigned short int*>(_a[0]) = _r; }  break;
        case 1: { uchar _r = _t->checkSum((*reinterpret_cast< const char*(*)>(_a[1])),(*reinterpret_cast< ushort(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< uchar*>(_a[0]) = _r; }  break;
        case 2: { uchar _r = _t->checkSum((*reinterpret_cast< QByteArray(*)>(_a[1])),(*reinterpret_cast< ushort(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< uchar*>(_a[0]) = _r; }  break;
        case 3: _t->on_bt_openFile_clicked(); break;
        case 4: _t->on_bt_getDeviceInf_clicked(); break;
        case 5: _t->on_bt_sendFirInf_clicked(); break;
        case 6: _t->on_bt_sendPacket_clicked(); break;
        case 7: _t->on_bt_autoUpdate_clicked(); break;
        case 8: _t->on_bt_stopAutoUpdate_clicked(); break;
        case 9: _t->on_bt_readBoot_clicked(); break;
        case 10: _t->on_bt_readFirmware_clicked(); break;
        case 11: _t->on_bt_stopRead_clicked(); break;
        case 12: _t->on_bt_storeFile_clicked(); break;
        case 13: _t->on_comboBox_updateMode_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_shortAddr_itemSelectionChanged(); break;
        case 15: _t->on_frimwareVersion_3_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->on_cb_deviceType_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->on_cb_deviceType_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->on_shortAddr_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 19: _t->on_pb_addAddr_clicked(); break;
        case 20: _t->on_pb_deleteAddr_clicked(); break;
        case 21: _t->pressUartData((*reinterpret_cast< QTcpSocket*(*)>(_a[1]))); break;
        case 22: { bool _r = _t->NET_newListen();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 23: _t->NET_acceptConnection(); break;
        case 24: _t->NET_displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 25: _t->NET_revData(); break;
        case 26: _t->NET_newListenLocation(); break;
        case 27: _t->NET_acceptConnectionLocation(); break;
        case 28: _t->NET_revDataLocation(); break;
        case 29: _t->BLE_locationCalculator((*reinterpret_cast< ushort(*)>(_a[1]))); break;
        case 30: _t->storeHistoryLog(); break;
        case 31: _t->on_bt_netSend_clicked(); break;
        case 32: _t->on_bt_listen_clicked(); break;
        case 33: _t->on_bt_stopListen_clicked(); break;
        case 34: _t->on_bt_searchId_clicked(); break;
        case 35: _t->on_export_idList_clicked(); break;
        case 36: _t->on_bt_clear_clicked(); break;
        case 37: _t->on_comunication_protocal_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 38: _t->on_bt_search_net_clicked(); break;
        case 39: _t->on_localtionFiltId_textChanged(); break;
        case 40: _t->on_localtionFiltStr_textChanged(); break;
        case 41: _t->on_coolFiltId_textChanged(); break;
        case 42: _t->on_coolFiltStr_textChanged(); break;
        case 43: _t->on_coolGetSn_clicked(); break;
        case 44: _t->on_coolSetRepTime_Bt_clicked(); break;
        case 45: _t->on_coolTemVerification_Bt_clicked(); break;
        case 46: _t->on_coolHumVerification_Bt_clicked(); break;
        case 47: _t->on_coolDisarm_clicked(); break;
        case 48: _t->on_coolGetTempreture_clicked(); break;
        case 49: _t->on_coolTemAlarm_Bt_clicked(); break;
        case 50: _t->on_coolSetSn_Bt_clicked(); break;
        case 51: _t->on_coolTemAlarmH_Edit_destroyed(); break;
        case 52: _t->on_networkResetIdTable_clicked(); break;
        case 53: _t->on_bt_clearId_clicked(); break;
        case 54: _t->on_energyFiltId_textChanged(); break;
        case 55: _t->on_energyFiltStr_textChanged(); break;
        case 56: _t->on_energyGetMeasurement_clicked(); break;
        case 57: _t->on_energySetRepTime_Bt_clicked(); break;
        case 58: _t->on_StoreDir_clicked(); break;
        case 59: _t->on_shortAddr_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 60: _t->on_shortAddr_itemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 61: _t->on_shortAddr_activated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 62: _t->on_shortAddr_itemActivated((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 63: _t->on_bt_setHeartBeatTime_clicked(); break;
        case 64: _t->on_injectionTemAlarm_Bt_clicked(); break;
        case 65: _t->on_injectionSetSn_Bt_clicked(); break;
        case 66: _t->on_injectionSetRepTime_Bt_clicked(); break;
        case 67: _t->on_injectionGetSn_clicked(); break;
        case 68: _t->on_injectionSetSpeaker_Bt_clicked(); break;
        case 69: _t->on_injectionFiltId_textChanged(); break;
        case 70: _t->on_injectionFiltStr_textChanged(); break;
        case 71: _t->on_sosSetRepTime_Bt_clicked(); break;
        case 72: _t->on_sosFiltStr_textChanged(); break;
        case 73: _t->on_sosFiltId_textChanged(); break;
        case 74: _t->on_injectionStart_Bt_clicked(); break;
        case 75: _t->on_injectionStop_Bt_clicked(); break;
        case 76: _t->on_injectionFinish_Bt_clicked(); break;
        case 77: _t->on_injectionSetTotalDi_Bt_clicked(); break;
        case 78: _t->on_injectionSetStopTimeOut_Bt_clicked(); break;
        case 79: _t->on_injectionGetDeviceParameters_Bt_clicked(); break;
        case 80: _t->on_injectionDiInit_Bt_clicked(); break;
        case 81: _t->on_injectionSetDi_Bt_clicked(); break;
        case 82: _t->on_injectionSetName_Bt_clicked(); break;
        case 83: _t->on_export_idList_2_clicked(); break;
        case 84: _t->on_export_idList_3_clicked(); break;
        case 85: _t->on_pushButton_requestNetPar_clicked(); break;
        case 86: _t->on_pushButton_setNetPar_clicked(); break;
        case 87: _t->on_localtionFiltId_1_textChanged(); break;
        case 88: _t->on_localtionFiltId_2_textChanged(); break;
        case 89: _t->on_localtionFiltId_3_textChanged(); break;
        case 90: _t->on_localtionFiltId_4_textChanged(); break;
        case 91: _t->on_bt_setHeartBeatTime_3_clicked(); break;
        case 92: _t->on_BLE_FiltId_textChanged(); break;
        case 93: _t->on_BLE_FiltId_1_textChanged(); break;
        case 94: _t->on_BLE_FiltId_2_textChanged(); break;
        case 95: _t->on_BLE_FiltId_3_textChanged(); break;
        case 96: _t->on_BLE_FiltId_4_textChanged(); break;
        case 97: _t->on_BLE_FiltStr_textChanged(); break;
        case 98: _t->on_BLE_addAnt_clicked(); break;
        case 99: _t->on_BLE_deleteAnt_clicked(); break;
        case 100: _t->on_BLE__set125KRssi_clicked(); break;
        case 101: _t->on_horizontalSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 102: _t->on_BLE_showDeviceInf_clicked(); break;
        case 103: _t->on_BLE_hideDeviceInf_clicked(); break;
        case 104: _t->on_BLE_showAllDeviceInf_clicked(); break;
        case 105: _t->on_BLE_hideAllDeviceInf_clicked(); break;
        case 106: _t->on_BLE_rssiCalculatorSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 107: _t->on_BLE_virtualRatio_textChanged(); break;
        case 108: _t->on_bt_listen_location_clicked(); break;
        case 109: _t->on_bt_stopListen_location_clicked(); break;
        case 110: _t->on_BLE_setAlgorithmPar_clicked(); break;
        case 111: _t->on_BLE_sendAntList_clicked(); break;
        case 112: _t->on_textEdit_MIN_ID_textChanged(); break;
        case 113: _t->on_textEdit_MAX_ID_textChanged(); break;
        case 114: _t->on_TemTHFiltId_textChanged(); break;
        case 115: _t->on_TemTHFiltStr_textChanged(); break;
        case 116: _t->on_TemTHSetRepTime_Bt_clicked(); break;
        case 117: _t->on_checkBox_productTest_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 118: _t->on_checkBox_125KTest_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 119: _t->on_bt_setDevRssi_clicked(); break;
        case 120: _t->on_pushButton_setHeartRateTime_clicked(); break;
        case 121: _t->on_cb_deviceTypeLocation_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 122: _t->on_TemTHTemVerification_Bt_clicked(); break;
        case 123: _t->on_TemTHHumVerification_Bt_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTcpSocket* >(); break;
            }
            break;
        case 24:
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
        if (_id < 124)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 124;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 124)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 124;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

 #ifndef MAINWINDOW_H
 #define MAINWINDOW_H

#include <QMainWindow>
#include "ui_main_window_form.h"
#include <threadcomport.h>
#include "user_md5.h"


#include<QtNetwork>
#include<QtNetwork/QTcpSocket>
#include<QtNetwork/QTcpServer>
#include"mangeid.h"



#define Q_WS_WIN 1
enum TypeDataInOut {DEC_, ASCII_, HEX_, BIN_};

//update step
enum
{
    update_step_getDevInf = 0x00,
    update_step_senFirInf,
    update_step_senPacket,
    update_step_finish
};



//rf cmd
enum
{
    r_getDevNetInf = 0x00,  //查询/设置网络参数
    r_getDevInf = 0x01,            //请求设备详细信息
    r_senFirInf = 0x02,            //发送固件信息包
    r_senPacket = 0x03,            //发送固件数据包
    r_getDevCap = 0x04,            //查询设备所具备的功能
    r_getDevCapDat = 0x05,         //查询设备功能数据
    r_setDevCapDat = 0x06,         //设置设备功能
    r_setGetRepDat = 0x07,         //查询/设置设备自动回传功能数据参数
    r_getBootloader = 0x08,        //请求回传bootloader
    r_getFirmware = 0x09,          //请求回传firmware
    r_sendHeartbeat = 0x0A,        //心跳包
    r_searchNetwork = 0x0B,        //搜索网络
    r_gatewayInf = 0x0C,           //返回网关信息
    r_getId = 0x0D,                //申请/验证ID
    r_setId = 0x0E,                //分配ID
    r_getIdSuccess = 0x0F,          //ID申请成功确认
    r_requesetData = 0x10,          //请求数据
    r_setHeartbeat = 0x11,          //设置心跳包时间
    r_noDataResponse = 0x12,          //请求数据时无数据回复
    r_systemReset = 0x13,          //设置心跳包时间


    r_recDevNetInf = 0x80,  //返回网络参数
    r_recDevInf = 0x81,            //返回设备详细信息
    r_recUpdSta = 0x82,            //返回固件升级状态
    r_recPacSta = 0x83,            //返回固件数据包接收状态
    r_recDevCap = 0x84,            //返回设备所具备的功能
    r_recDevCapDat = 0x85,         //返回设备功能数据
    r_recRepDat = 0x86             //返回设备自动回传功能数据参数
};

//device type
enum
{
    dev_gatway                  = 0x00,  //网关
    dev_adultSpireLamella       = 0x01,  //成人腕带
    dev_patientSpireLamella     = 0x02,  //精神病腕带
    dev_childSpireLamella       = 0x03,  //婴儿腕带
    dev_sosPanicLocation        = 0x04,  //SOS按键（胸牌）
    dev_plug                    = 0x05,  //插座
    dev_tempreture              = 0x06,  //温度传感器
    dev_humidity                = 0x07,  //湿度传感器
    dev_multileSensor           = 0x08,  //多功能传感器
    dev_tag                     = 0x09,  //资产标签
    dev_rfidReader              = 0x0A,  //四通道读头
    dev_125kTag                 = 0x0B,  //125K资产标签
    dev_sosPanic                = 0x0C,  //不带定位SOS
    dev_863DriectModule         = 0x0D,  //蓝牙透传863模块
    dev_863ORModule             = 0x0E,  //手术室863模块




    dev_bleTag                  = 0xA0,  //蓝牙资产标签
    dev_bleAnt                  = 0xB0,  //蓝牙定位天线






    dev_repeater                = 0xFC,  //中继器
    dev_normal                  = 0xFD,  //普通节点
    dev_lowPower                = 0xFE,  //低功耗节点
    dev_unknow                  = 0xFF,  //未知节点


};






struct RF_PAR
{
    uchar sequence;
    uchar deviceType;
    uchar cmd;
    uchar *data;
};

struct UR_PAR
{
    uchar head;
    ushort len;
    ushort dstAddr;
    ushort srcAddr;
    char rssi;
    RF_PAR rf;
    ushort crc;
};



/*********************/
//device type
enum
{
    cmd_heartBeat       = 0x10,      //
    cmd_config          = 0x20,  //
    cmd_control         = 0x30,//
    cmd_app             = 0x40,  //
    cmd_idRequest       = 0x50,           //
    cmd_network         = 0x60,               //
    cmd_bleData         = 0x70,
    cmd_json            = 0x80
};


struct RF_FRAME
{
    uchar sequence;
    uchar deviceType;
    uchar cmd;
    uchar *data;
};

struct APP_FRAME
{
    RF_FRAME rf;
};


/******location*****/

#define BV(n)   (0x01<<n)

#define checkDrop(n)  (BV(4)&n)
#define checkTamper(n)  (BV(3)&n)
#define checkLocation(n)  (BV(2)&n)
#define checkAlarm(n)  (BV(1)&n)
#define checkLowBattery(n)  (BV(0)&n)

struct LOCATION_FRAME
{
    uchar head[2];
    ushort devie_id;
    ushort ant_id;
    char rssi;
    uchar alarm;
    uchar checksum;
};





struct LOC_PAR
{
    QByteArray filtStr;
    ushort filtId[5];
};


/**************************/


/************BLE*************/


enum
{
    location_device_125k    =0x00,  //125K
    location_device_868    =0x00,  //868
    location_device_ble    =0x00,  //ble
};

struct BLE_LOCATION_FRAME
{
    uchar head[2];
    uchar device_type;
    uchar sequence;
    uchar devie_id[8];
    uchar ant_ble_id[8];
    ushort ant_125k_id;
    char rssi;
    uchar sensor_x;
    uchar sensor_y;
    uchar sensor_z;
    uchar battery;
    uchar alarm;
    uchar checksum;
};


struct BLE_PAR
{
    QByteArray filtStr;
    ushort filtId[5];
};
/**************************/


/************cool*************/
enum
{
    coolCmdUnkown = 0x00,//ERROR
    coolCmdGetDisNum = 0x01,//
    coolCmdSetDisNum = 0x02,//
    coolCmdAlarm = 0x03,//
    coolCmdDisarm = 0x04,//
    coolCmdSetRepTime = 0x05,//
    coolCmdTemVer = 0x06,//
    coolCmdHumVer = 0x07,//
    coolCmdGetSenVal = 0x08,//
    coolCmdSetAlaVal = 0x09,//
    coolCmdSenError = 0x0A,//
    coolCmdStatus = 0xFE//
};


/************energy*************/
enum
{
    energyCmdSetRepTime = 0x05,//
    energyCmdGetMeasurement= 0x09,//
    energyCmdSenError = 0x0A,//
    energyCmdStatus = 0xFE//
};


/************energy*************/
enum
{
    sosCmdSetRepTime = 0x05,//
    sosCmdReportStatus= 0x06,//
    sosCmdSenError = 0x0A,//
    sosCmdStatus = 0xFE//
};
/************injection*************/
enum
{
    injectionCmdUnkown = 0x00,//ERROR
    injectionCmdPowerOn = 0x01,//
    injectionCmdSetSpeed= 0x02,//
    injectionCmdSetSpeaker = 0x03,//
    injectionCmdSetDisNum = 0x04,//
    injectionCmdSetRepTime = 0x05,//
    injectionCmdRepStatus = 0x06,//
    injectionCmdDevReset = 0x07,//
    injectionCmdDevCutoff = 0x08,//
    injectionCmdPowerOff = 0x09,//ERROR
    injectionCmdDevError = 0x0A,//
    injectionCmdDevStart = 0x0B,//
    injectionCmdDevStop = 0x0C,//
    injectionCmdDevFinish = 0x0D,//
    injectionCmdSetTotalDi = 0x0E,//
    injectionCmdSetStopTimeout = 0x0F,//
    injectionCmdGetDeviceParameter = 0x10,//
    injectionCmdDiInit = 0x11,//
    injectionCmdSetDi = 0x12,//
    injectionCmdSetName = 0x13,//
    injectionCmdStatus = 0xFE//
};
enum
{
    coolDevUnkown = 0x00,//ERROR
    coolDevTempreture = 0x01,//
    coolDevSiren = 0x02,//
    coolDevSosPanic = 0x03,//
    coolDevEnergy = 0x04,//
    coolDevInjection = 0x05,
    coolDevSosNoLocationPanic = 0x06,//
};



struct COOL_FRAME
{
    uchar head[2];
    ushort sensorId;
    uchar deviceType;
    char len;
    uchar cmd;
    uchar *data;
    uchar checksum;
};

struct COO_PAR
{
    QByteArray filtStr;
    ushort filtId;
};


struct ENE_PAR
{
    QByteArray filtStr;
    ushort filtId;
};

struct INJ_PAR
{
    QByteArray filtStr;
    ushort filtId;
};

struct SOS_PAR
{
    QByteArray filtStr;
    ushort filtId;
};
/*************************/

struct IOT_FRAME
{
    ushort head;
    ushort gateway_id;
    ushort device_id;
    uchar cmd;
    uchar length;
    uchar *data;
    char rssi;
    uchar checkSum;
};
/*********************/


struct RF_SEND
{
    ushort device_id;
    char rssi;
    uchar sequence;
    uchar device;
};




struct ota_firmwares
{
    uchar mode;
    uchar device_type;
    ushort total_packet;
    uchar packet_byte;
    uint total_byte;
    uchar version;
    QByteArray md5;
    QByteArray buff;
    ushort send_cout;
    ushort send_max;
};


struct firmwares
{
    uchar auto_step;
    ota_firmwares ota_w;
    ota_firmwares ota_r;
};


struct TRANSPORT
{
    uchar send[65535];
    ushort s_count;
    uchar receive[65535];
    ushort r_count;
};



#define SOCKET_MAX 100

struct NET_PAR
{
    QTcpSocket *Socket[SOCKET_MAX];
    QTcpSocket *currentSocket;
    QTcpServer *Server;
    QTcpSocket *bind_socket[65536];
    QTcpSocket *clientSocket;
};



struct HISTORY_PAR
{
    QString Network_path;
    QString Uart_path;
    QString Update_path;
    QString location_path;
    QString cool_path;
    QString energy_path;
    QString injection_path;
    QString sos_path;
    QString custom_path;
    QString ble_path;

    QByteArray Network_buff;
    QByteArray Uart_buff;
    QByteArray Update_buff;
    QByteArray location_buff;
    QByteArray cool_buff;
    QByteArray energy_buff;
    QByteArray injection_buff;
    QByteArray sos_buff;
    QByteArray custom_buff;
    QByteArray ble_buff;

    QFile *Network_file;
    QFile *Uart_file;
    QFile *Update_file;
    QFile *location_file;
    QFile *cool_file;
    QFile *energy_file;
    QFile *injection_file;
    QFile *sos_file;
    QFile *custom_file;
    QFile *ble_file;

    QTimer *timer;
    ushort time_count;
};


#define ALGORITHM_DEVICE_MAX 100
#define ALGORITHM_ANT_MAX 50

struct BLE_DEVICE_PAR
{
    ushort device_id;
    uchar sequence;
    uchar receive_count;
    bool update_flag;
    ushort ant_id[ALGORITHM_ANT_MAX];
    char rssi[ALGORITHM_ANT_MAX];
};


struct ALGORITHM_CACULATER_PAR{
    double  ratio;
    bool translate;
    bool translate_center;
    bool filter;
    bool limit_xy;
    bool limit_r;
    double compare;
};
struct BLE_ALGORITHM
{
  BLE_DEVICE_PAR ble_algorithm[ALGORITHM_DEVICE_MAX];
  uchar location_bit[300][300];
  ALGORITHM_CACULATER_PAR par;
  QTimer *timer;
};


struct DEVICE_DISPLAY_PAR
{
    int x;
    int y;
    ushort id;
    uchar mac[8];
    ushort radius;
    short rssi_offset;
    QColor color;
    bool displayInfFlag;
};



#define DEVICE_DISPLAY_MAX 100

struct DISPLAY_PAR
{
    uint xy_unit;
    uint xy_max;
    DEVICE_DISPLAY_PAR device[DEVICE_DISPLAY_MAX];
    DEVICE_DISPLAY_PAR ant[DEVICE_DISPLAY_MAX];

};



#define meter_xy(n) (10*n)
#define x_convert(n) (10*(int)n)
#define y_convert(n) (-10*(int)n)



class MainWindow : public QMainWindow, private Ui::MainWindow {
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();

protected:
     void closeEvent(QCloseEvent *event);

private:
	Qthreadcomport *port;
	QMainComThread *mainComThread;
	QTimer *timerout;
	QMenu *fileMenu;
	QMenu *helpMenu;
	QMenu *editMenu;
	QAction *exitAct;
	QAction *aboutAct;
	QAction *calcTimeoutAct;
	QTime *timeoutTime;
	QLabel *labelReceive;
	QLabel *labelTransmit;
	int counter_in,counter_out;
    firmwares fir;
    TRANSPORT transport;
    QTimer *receiveTimer;
    QTimer *sendTimer;
    RF_SEND rf_send;
    HISTORY_PAR history_par;
    DISPLAY_PAR display_par;
    BLE_ALGORITHM ble_algorithm;

	bool bRTS;
	bool bDTR;
	void createMainMenu();
	void getdataout(QByteArray *data);
	void readSettings(PortSettings *portsettings);
    QString transformInpData(const unsigned char *data, const int size);
    void writeSettings();



    //add bye lekee
    void user_init();
    void UART_send(QByteArray src);
    void pressCmdData(uchar *data , ushort size);
    void processJsonData(QByteArray datas);
    void pressOldCmdData(uchar *data , ushort size);
    void DisplayWithTime(const QString &text);
    void DisplayWithNoTime(const QString &text);
    QString uint8ToHex(uchar data);
    QString uint16ToHex(ushort data);
    QString uint32ToHex(uint data);
    QString strToHex(uchar *data , ushort len);
    ushort hexToUint8(QString str,uint start);
    void rcmdSetHeartbeatTime(ushort gateway_id,ushort device_id);
    void rcmdSendsendPacket(ushort gateway_id,ushort device_id,ushort packet);
    void rcmdSendFirInf(ushort gateway_id,ushort device_id);
    void rcmdGetDeviceInf(ushort gateway_id,ushort device_id);
    void rcmdSystemReset(ushort gateway_id,ushort device_id);
    void rcmdSetNetPar(ushort gateway_id,ushort device_id);
    void rcmdRequestNetPar(ushort gateway_id,ushort device_id);

    void IOT_cmdNetwork(ushort gateway_id,ushort device_id,QByteArray data);
    void IOT_cmdAsscessId(ushort gateway_id,ushort device_id,ID_SEND *id);
    void IOT_cmdHeartBeat(IOT_FRAME *ptr);
    void IOT_cmdHeartBeat(ushort gateway_id,ushort device_id,ushort time,ushort bandwith,uchar rssi);
    void IOT_cmdApp(ushort gateway_id,ushort device_id,QByteArray data);

    NET_PAR net_par;
    MangeId id_access;
    QString NET_get_localmachine_ip();
    void NET_DisplayWithTime(const QString &text);
    void NET_DisplayWithNoTime(const QString &text);
    void NET_Init();
    void NET_send(QByteArray src);
    void NET_sendById(QByteArray src);
    void NET_getBindSocket(ushort id);
    void NET_setBindSocket(ushort id);
    void NET_clientToServer();


    LOC_PAR loc_par;
    void LOC_DisplayWithTime(const QString &text);
    void LOC_DisplayWithNoTime(const QString &text);
    void LOC_init();
    void LOC_Set125KRssi(ushort gateway_id,ushort device_id);

    COO_PAR coo_par;
    void COO_init();
    void COO_DisplayWithTime(const QString &text);
    void COO_DisplayWithNoTime(const QString &text);
    void COO_getSnNumber(ushort gateway_id,ushort device_id);
    void COO_ackSuccess(ushort gateway_id,ushort device_id,uchar ack_cmd);
    void COO_ackError(ushort gateway_id,ushort device_id,uchar ack_cmd);
    void COO_setSnNumber(ushort gateway_id,ushort device_id);
    void COO_setReportTime(ushort gateway_id,ushort device_id);
    void COO_clearTemAlarm(ushort gateway_id,ushort device_id);
    void COO_tempretureVerfication(ushort gateway_id,ushort device_id);
    void COO_HumVerfication(ushort gateway_id,ushort device_id);
    void COO_tempretureAlarmHL(ushort gateway_id,ushort device_id);
    void COO_getSensorValue(ushort gateway_id,ushort device_id);


    ENE_PAR ene_par;
    void ENE_init();
    void ENE_DisplayWithTime(const QString &text);
    void ENE_DisplayWithNoTime(const QString &text);
    void ENE_getMeasurementValue(ushort gateway_id,ushort device_id);
    void ENE_setReportTime(ushort gateway_id,ushort device_id);
    void ENE_ackSuccess(ushort gateway_id,ushort device_id,uchar ack_cmd);
    void ENE_ackError(ushort gateway_id,ushort device_id,uchar ack_cmd);


    INJ_PAR inj_par;
    void INJ_init();
    void INJ_DisplayWithTime(const QString &text);
    void INJ_DisplayWithNoTime(const QString &text);
    void INJ_setSnNumber(ushort gateway_id,ushort device_id);
    void INJ_setSpeaker(ushort gateway_id,ushort device_id);
    void INJ_tempretureAlarmHL(ushort gateway_id,ushort device_id);
    void INJ_setReportTime(ushort gateway_id,ushort device_id);
    void INJ_ackSuccess(ushort gateway_id,ushort device_id,uchar ack_cmd);
    void INJ_ackError(ushort gateway_id,ushort device_id,uchar ack_cmd);
    void INJ_startInjection(ushort gateway_id,ushort device_id);
    void INJ_stopInjection(ushort gateway_id,ushort device_id);
    void INJ_finishInjection(ushort gateway_id,ushort device_id);
    void INJ_setTotalDi(ushort gateway_id,ushort device_id);
    void INJ_setStopTimeout(ushort gateway_id,ushort device_id);
    void INJ_getDeviceParameters(ushort gateway_id,ushort device_id);
    void INJ_DiInit(ushort gateway_id,ushort device_id);
    void INJ_SetDi(ushort gateway_id,ushort device_id);
    void INJ_SetName(ushort gateway_id,ushort device_id);

    SOS_PAR sos_par;
    void SOS_init();
    void SOS_DisplayWithTime(const QString &text);
    void SOS_DisplayWithNoTime(const QString &text);
    void SOS_setReportTime(ushort gateway_id,ushort device_id);
    void SOS_ackSuccess(ushort gateway_id,ushort device_id,uchar ack_cmd);
    void SOS_ackError(ushort gateway_id,ushort device_id,uchar ack_cmd);


    BLE_PAR ble_par;
    void BLE_DisplayInit(void);
    void BLE_init(void);
    void BLE_DisplayWithTime(const QString &text);
    void BLE_DisplayWithNoTime(const QString &text);
    void BLE_Set125KRssi(ushort gateway_id,ushort device_id);
    void BLE_displayUpdate();
    void BLE_DisplayDrawXY(uint xy_unit,uint xy_max,QGraphicsScene *scene);
    void BLE_storeData(ushort device_id,ushort ant_id,uchar sequence,char rssi);
    bool BLE_idInfoWriteInFile();
    bool BLE_idInfoReadFromFile();

private slots:
	void about();
	void applyPortOptions();
	void btsendClick();
	void btstopsendClick();
	void closePort();
	void enabledPortBt();
	void openPort();
    void receiveMsg(const QTime timesl, const unsigned char *data, const int size);
	void SetCurComboBState();
    unsigned short int Crc16Bit(const char *ptr, unsigned short int len);
    uchar checkSum(const char* puchData, ushort len);
	void transmitMsg();
	void intervalChange(int value);
    void on_File_clicked();
    void on_pushButton_clicked();
    void on_bt_openFile_clicked();
    void on_comboBox_updateWay_currentIndexChanged(const QString &arg1);


    void on_bt_getDeviceInf_clicked();
    void on_bt_sendFirInf_clicked();
    void on_bt_sendPacket_clicked();
    void on_bt_autoUpdate_clicked();
    void on_bt_stopAutoUpdate_clicked();
    void on_bt_readBoot_clicked();
    void on_bt_readFirmware_clicked();
    void on_bt_stopRead_clicked();
    void on_bt_storeFile_clicked();
    void on_comboBox_updateMode_currentTextChanged(const QString &arg1);
    void on_shortAddr_itemSelectionChanged();
    void on_frimwareVersion_3_currentTextChanged(const QString &arg1);
    void on_cb_deviceType_currentTextChanged(const QString &arg1);
    void on_cb_deviceType_currentIndexChanged(int index);
    void on_shortAddr_doubleClicked(const QModelIndex &index);
    void on_pb_addAddr_clicked();
    void on_pb_deleteAddr_clicked();


    void pressUartData();

    void NET_newListen(); //建立TCP监听事件
    void NET_acceptConnection(); //接受客户端连接
    void NET_displayError(QAbstractSocket::SocketError); //显示错误信息
    void NET_revData();
    void BLE_locationCalculator(ushort id);


    void storeHistoryLog();


    void on_bt_netSend_clicked();
    void on_bt_listen_clicked();
    void on_bt_stopListen_clicked();
    void on_bt_searchId_clicked();
    void on_export_idList_clicked();
    void on_bt_clear_clicked();
    void on_comunication_protocal_currentTextChanged(const QString &arg1);
    void on_bt_search_net_clicked();
    void on_localtionIdSelection_windowIconTextChanged(const QString &iconText);
    void on_localtionIdSelection_4_windowIconTextChanged(const QString &iconText);
    void on_localtionFiltId_windowIconTextChanged(const QString &iconText);
    void on_localtionFiltStr_windowIconTextChanged(const QString &iconText);
    void on_localtionFiltId_textChanged();
    void on_localtionFiltStr_textChanged();
    void on_locationStopDisplay_clicked(bool checked);
    void on_coolFiltId_textChanged();
    void on_coolFiltStr_textChanged();
    void on_coolGetSn_clicked();
    void on_coolSetRepTime_Bt_clicked();
    void on_coolTemVerification_Bt_clicked();
    void on_coolHumVerification_Bt_clicked();
    void on_coolDisarm_clicked();
    void on_coolGetTempreture_clicked();
    void on_coolTemAlarm_Bt_clicked();
    void on_coolSetSn_Bt_clicked();
    void on_coolTemAlarmH_Edit_destroyed();
    void on_networkResetIdTable_clicked();
    void on_bt_clearId_clicked();
    void on_energyFiltId_textChanged();
    void on_energyFiltStr_textChanged();
    void on_energyGetMeasurement_clicked();
    void on_energySetRepTime_Bt_clicked();
    void on_StoreDir_clicked();
    void on_shortAddr_currentRowChanged(int currentRow);
    void on_shortAddr_itemChanged(QListWidgetItem *item);
    void on_shortAddr_activated(const QModelIndex &index);
    void on_shortAddr_itemActivated(QListWidgetItem *item);
    void on_bt_setHeartBeatTime_clicked();
    void on_injectionTemAlarm_Bt_clicked();
    void on_injectionSetSn_Bt_clicked();
    void on_injectionSetRepTime_Bt_clicked();
    void on_injectionGetSn_clicked();
    void on_injectionSetSpeaker_Bt_clicked();
    void on_injectionFiltId_textChanged();
    void on_injectionFiltStr_textChanged();
    void on_sosSetRepTime_Bt_clicked();
    void on_sosFiltStr_textChanged();
    void on_sosFiltId_textChanged();
    void on_injectionStart_Bt_clicked();
    void on_injectionStop_Bt_clicked();
    void on_injectionFinish_Bt_clicked();
    void on_injectionSetTotalDi_Bt_clicked();
    void on_injectionSetStopTimeOut_Bt_clicked();
    void on_injectionGetDeviceParameters_Bt_clicked();
    void on_injectionDiInit_Bt_clicked();
    void on_injectionSetDi_Bt_clicked();
    void on_injectionSetName_Bt_clicked();
    void on_export_idList_2_clicked();
    void on_export_idList_3_clicked();
    void on_pushButton_requestNetPar_clicked();
    void on_pushButton_setNetPar_clicked();
    void on_localtionFiltId_1_textChanged();
    void on_localtionFiltId_2_textChanged();
    void on_localtionFiltId_3_textChanged();
    void on_localtionFiltId_4_textChanged();
    void on_bt_setHeartBeatTime_3_clicked();
    void on_BLE_FiltId_textChanged();
    void on_BLE_FiltId_1_textChanged();
    void on_BLE_FiltId_2_textChanged();
    void on_BLE_FiltId_3_textChanged();
    void on_BLE_FiltId_4_textChanged();
    void on_BLE_FiltStr_textChanged();
    void on_BLE_addAnt_clicked();
    void on_BLE_deleteAnt_clicked();
    void on_BLE__set125KRssi_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void on_BLE_showDeviceInf_clicked();
    void on_BLE_hideDeviceInf_clicked();
    void on_BLE_showAllDeviceInf_clicked();
    void on_BLE_hideAllDeviceInf_clicked();
    void on_BLE_rssiCalculatorSlider_valueChanged(int value);
    void on_BLE_virtualSetBt_clicked();
    void on_BLE_virtualRatio_textChanged();
};

 #endif

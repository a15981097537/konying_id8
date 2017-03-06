 #ifndef MAINWINDOW_H	
 #define MAINWINDOW_H

#include <QMainWindow>
#include "ui_main_window_form.h"
#include <threadcomport.h>
#include <md5.h>
#include "usercmd.h"
#include "user_md5.h"

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

//uart cmd
enum
{
    u_getDevNetInf = 0x00,  //查询/设置网络参数
    u_getDevInf,            //请求设备详细信息
    u_senFirInf,            //发送固件信息包
    u_senPacket,            //发送固件数据包
    u_getBootloader,        //请求回传bootloader
    u_getFirmware,          //请求回传firmware
    u_recDevNetInf=0x80,    //返回网络参数
    u_recDevInf,            //返回设备详细信息
    u_recUpdSta,            //返回固件升级状态
    u_recPacSta             //返回固件数据包接收状态
};

//rf cmd
enum
{
    r_getDevNetInf = 0x00,  //查询/设置网络参数
    r_getDevInf,            //请求设备详细信息
    r_senFirInf,            //发送固件信息包
    r_senPacket,            //发送固件数据包
    r_getDevCap,            //查询设备所具备的功能
    r_getDevCapDat,         //查询设备功能数据
    r_setDevCapDat,         //设置设备功能
    r_setGetRepDat,         //查询/设置设备自动回传功能数据参数
    r_getBootloader,        //请求回传bootloader
    r_getFirmware,          //请求回传firmware
    r_recDevNetInf = 0x80,  //返回网络参数
    r_recDevInf,            //返回设备详细信息
    r_recUpdSta,            //返回固件升级状态
    r_recPacSta,            //返回固件数据包接收状态
    r_recDevCap,            //返回设备所具备的功能
    r_recDevCapDat,         //返回设备功能数据
    r_recRepDat             //返回设备自动回传功能数据参数
};

//device type
enum
{
    dev_gatway = 0x00,      //网关
    dev_adultSpireLamella,  //成人腕带
    dev_patientSpireLamella,//精神病腕带
    dev_childSpireLamella,  //婴儿腕带
    dev_sosPanic,           //SOS按键（胸牌）
    dev_plug,               //插座
    dev_tempreture,         //温度传感器
    dev_humidity,           //湿度传感器
    dev_multileSensor       //多功能传感器
};





struct UC_PAR
{
    uchar head;
    uchar len;
    uchar cmd;
    uchar *data;
    ushort crc;
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
    signed char rssi;
    RF_PAR rf;
    ushort crc;
};


struct RF_SEND
{
    ushort dest_addr;
    ushort src_addr;
    uchar rssi;
    uchar sequence;
    uchar device;
};


struct local_firmwares
{
    ushort total_packet;
    ushort packet_byte;
    uint total_byte;
    uchar version;
    QByteArray md5;
    QByteArray buff;
    ushort send_cout;
    ushort send_max;
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
    local_firmwares local_w;
    local_firmwares local_r;
    ota_firmwares ota_w;
    ota_firmwares ota_r;
};


struct USART
{
    uchar send[65535];
    ushort s_count;
    uchar receive[65535];
    ushort r_count;
};

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
    USART usart;
    QTimer *receiveTimer;
    QTimer *sendTimer;
    RF_SEND rf_send;




	bool bRTS;
	bool bDTR;
	void createMainMenu();
	void getdataout(QByteArray *data);
	void readSettings(PortSettings *portsettings);
    QString transformInpData(const unsigned char *data, const int size);
    void writeSettings();
	
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
	void transmitMsg();
	void intervalChange(int value);
    void on_File_clicked();
    void on_pushButton_clicked();
    void on_bt_openFile_clicked();
    void on_comboBox_updateWay_currentIndexChanged(const QString &arg1);
    //add bye lekee
    void user_init();
    void pressUartData();
    char u_sendMessage(unsigned char cmd,QByteArray *data);
    char r_sendMessage(unsigned char cmd,QByteArray *data);
    void usartAck(uchar head);
    void pressCmdData(uchar *data , ushort size);
    void DisplayWithTime(const QString &text);
    void DisplayWithNoTime(const QString &text);
    QString uint8ToHex(uchar data);
    QString uint16ToHex(ushort data);
    QString uint32ToHex(uint data);
    QString strToHex(uchar *data , ushort len);
    void ucmdGetDeviceInf();
    void ucmdSendFirInf();
    void ucmdSendsendPacket(ushort packet);
    void ucmdAutoUpdate(uchar step);
    void rcmdSendsendPacket(ushort packet);
    void rcmdSendFirInf();
    void rcmdGetDeviceInf();

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
};

 #endif

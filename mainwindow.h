 #ifndef MAINWINDOW_H	
 #define MAINWINDOW_H

#include <QMainWindow>
#include "ui_main_window_form.h"
#include <threadcomport.h>
#include <md5.h>

#define Q_WS_WIN 1
enum TypeDataInOut {DEC_, ASCII_, HEX_, BIN_};



#define uint8 unsigned char
#define uint16 unsigned short
#define uint32 unsigned int



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
#define DEVICE_GATWAY               0x00
#define DEVICE_SPIRE_LAMELLA        0x01





struct UC_PAR
{
    uint8 head;
    uint16 len;
    uint8 cmd;
    uint8 *data;
    uint16 crc;
};

struct RF_PAR
{
    uint8 sequence;
    uint8 deviceType;
    uint8 cmd;
    uint8 *data;
};

struct UR_PAR
{
    uint8 head;
    uint16 len;
    uint16 dstAddr;
    uint16 srcAddr;
    uint8 rssi;
    RF_PAR rf;
    uint16 crc;
};



struct local_firmwares
{
    unsigned short total_packet;
    unsigned short packet_byte;
    unsigned int total_byte;
    unsigned char version;
    QByteArray md5;
    QByteArray buff;
    unsigned int send_cout;
    unsigned int send_max;
};

struct ota_firmwares
{
    unsigned char mode;
    unsigned char device_type;
    unsigned short total_packet;
    unsigned char packet_byte;
    unsigned int total_byte;
    unsigned char version;
    QByteArray md5;
    QByteArray buff;
    unsigned int send_cout;
    unsigned int send_max;
};


struct firmwares
{
    local_firmwares local_w;
    local_firmwares local_r;
    ota_firmwares ota_w;
    ota_firmwares ota_r;
};


struct USART
{
    uint8 send[65535];
    uint16 s_count;
    uint8 receive[65535];
    uint16 r_count;
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
    void update_init();
    void pressUartData();
    char u_sendMessage(unsigned char cmd,QByteArray *data);
    char r_sendMessage(unsigned short dest_addr,
                                   unsigned char sequence,
                                   unsigned char device_type,
                                   unsigned char cmd,
                                   QByteArray *data);
    void usartAck();
    void pressCmdData(uint8 *data , uint16 size);
    void DisplayWithTime(const QString &text);
    void DisplayWithNoTime(const QString &text);
    QString uint8ToHex(uint8 data);
    QString uint16ToHex(uint16 data);
    QString uint32ToHex(uint32 data);
    QString strToHex(uint8 *data , uint16 len);
    void on_bt_getDeviceInf_clicked();
    void on_bt_sendFirInf_clicked();
    void on_bt_sendPacket_clicked();
    void on_bt_autoUpdate_clicked();
    void on_bt_stopAutoUpdate_clicked();
    void on_bt_readBoot_clicked();
    void on_bt_readFirmware_clicked();
    void on_bt_stopRead_clicked();
    void on_bt_storeFile_clicked();
};

 #endif

#ifndef USERCMD_H
#define USERCMD_H


#include "mainwindow.h"

class usercmd
{
public:
    usercmd();

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
        unsigned char head;
        unsigned short len;
        unsigned char cmd;
        unsigned char *data;
        unsigned short crc;
    };

    struct RF_PAR
    {
        unsigned char sequence;
        unsigned char deviceType;
        unsigned char cmd;
        unsigned char *data;
    };

    struct UR_PAR
    {
        unsigned char head;
        unsigned short len;
        unsigned short dstAddr;
        unsigned short srcAddr;
        unsigned char rssi;
        RF_PAR rf;
        unsigned short crc;
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
        unsigned char send[65535];
        unsigned short s_count;
        unsigned char receive[65535];
        unsigned short r_count;
    };

    unsigned short Crc16Bit(const char *ptr, unsigned short int len);
    QString uint8ToHex(unsigned char data);
    QString uint16ToHex(unsigned short data);
    QString uint32ToHex(unsigned int data);
    QString strToHex(unsigned char *data , unsigned short len);
};

#endif // USERCMD_H

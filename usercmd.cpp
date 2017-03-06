#include "usercmd.h"

usercmd::usercmd()
{

}
unsigned short usercmd::Crc16Bit(const char *ptr, unsigned short int len)
{
    unsigned short int i,j;
    const char *src = ptr;
    unsigned short int CRC16 = 0xFFFF;

    for (j = len; j != 0; j--)
    {
        CRC16 =CRC16 ^ (0x00ff&(*src++));
        for (i = 8; i != 0; i--)
        {
            if ((CRC16 & 0x0001) != 0)
            {
                CRC16 >>= 1;
                CRC16 ^= 0xA001;
            }
            else
            {
                CRC16 >>= 1;
            }
        }
    }

    return (CRC16);
}


QString usercmd::uint8ToHex(unsigned char data)
{
    QByteArray buff;
    buff[0] = data;
    return buff.toHex();
}

QString usercmd::uint16ToHex(unsigned short data)
{
    QByteArray buff;
    buff[0] = (data>>8)&0xFF;
    buff[1] = (data>>0)&0xFF;
    return buff.toHex();
}

QString usercmd::uint32ToHex(unsigned int data)
{
    QByteArray buff;
    buff[0] = (data>>24)&0xFF;
    buff[1] = (data>>16)&0xFF;
    buff[2] = (data>>8)&0xFF;
    buff[3] = (data>>0)&0xFF;
    return buff.toHex();
}

QString usercmd::strToHex(unsigned char *data , unsigned short len)
{
    QByteArray buff;
    for(int i = 0 ; i<len;i++)
    {
        buff[i] = data[i];
    }
    return buff.toHex();
}



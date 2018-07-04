#include "mangeid.h"

MangeId::MangeId()
{
    init();
}


void MangeId::init()
{
    readFromFile();
}



bool MangeId::writeInFile()
{
    ulong i;
    uchar *ptr;
    QByteArray buff;
    buff.clear();



    ptr = (uchar *)&id_store;

    for(i=0;i<sizeof(id_store);i++)
    {
        buff.append(*ptr++);
    }


    QString path = QDir::currentPath();
    path+="/id_information.bin";
    QFile file(path);
    file.open(QIODevice::ReadWrite);
    file.write(buff);
    file.close();

    return true;
}


QString MangeId::resetAllId()
{
    //reset
    uchar *ptr;
    ptr = (uchar *)&id_store;
    memset(ptr,0xFF,sizeof(id_store));
    writeInFile();
    return "reset finish";
}

QString MangeId::clearId(ushort id)
{
    QString str = "clear id information\n";
    str = getIdInf(id);

    memset(id_store[id].mac,0xFF,8);
    id_store[id].panid=0xFFFF;
    id_store[id].gateway_id=0xFFFF;
    id_store[id].frequence=0xFFFF;
    id_store[id].channel=0xFF;
    id_store[id].device_id=0xFFFF;
    memset(id_store[id].un,0xFF,4);
    writeInFile();

    return str;
}



bool MangeId::readFromFile()
{
    ulong i;
    QByteArray buff;
    uchar *ptr;
    buff.clear();
    QString path = QDir::currentPath();
    path+="/id_information.bin";
    QFile file(path);


    if(!file.open(QIODevice::ReadOnly))
    {
       //creat a file and wirte the firmware
       ptr = (uchar *)&id_store;
       memset(ptr,0xFF,sizeof(id_store));

       for(i=0;i<sizeof(id_store);i++)
       {
           buff.append(*ptr++);
       }


       QFile fd_creat(path);
       fd_creat.open(QIODevice::ReadWrite);
       fd_creat.write(buff);
       fd_creat.close();
    }
    else
    {
        buff = file.readAll();
        file.close();
        memcpy((uchar *)&id_store,buff.data(),buff.length());
    }
    return true;
}


ID_SEND MangeId::accessId(uchar *src)
{
    ulong i;
    uchar *ptr = src;
    memcpy(id_receive.mac,ptr,8);
    ptr+=8;
    id_receive.gateway_id = (ptr[0]<<8)+ptr[1];
    ptr+=2;
    id_receive.panid = (ptr[0]<<8)+ptr[1];
    ptr+=2;
    id_receive.frequence = (ptr[0]<<8)+ptr[1];
    ptr+=2;
    id_receive.channel = *ptr;
    ptr++;
    memcpy(id_receive.un,ptr,4);


    for(i=0;i<0xFFFF;i++)
    {
        if(memcmp(id_store[i].mac,id_receive.mac,8)==0)
        {


            memcpy(id_store[i].mac,id_receive.mac,8);
            id_store[i].gateway_id = id_receive.gateway_id;
            id_store[i].panid = id_receive.panid;
            id_store[i].frequence = id_receive.frequence;
            id_store[i].channel = id_receive.channel;
            id_store[i].device_id = i;
            memcpy(id_store[i].un,id_receive.un,4);



            memcpy(id_send.mac,id_store[i].mac,8);
            id_send.panid=id_store[i].panid;
            id_send.gateway_id=id_store[i].gateway_id;
            id_send.device_id=id_store[i].device_id;
            memcpy(id_send.un,id_store[i].un,4);
            writeInFile();
            return id_send;
        }
    }

    for(i=1;i<0xFF02;i++)
    {
        if(id_store[i].device_id == 0xFFFF)
        {
            memcpy(id_store[i].mac,id_receive.mac,8);
            id_store[i].gateway_id = id_receive.gateway_id;
            id_store[i].panid = id_receive.panid;
            id_store[i].frequence = id_receive.frequence;
            id_store[i].channel = id_receive.channel;
            id_store[i].device_id = i;
            memcpy(id_store[i].un,id_receive.un,4);


            memcpy(id_send.mac,id_store[i].mac,8);
            id_send.panid=id_store[i].panid;
            id_send.gateway_id=id_store[i].gateway_id;
            id_send.device_id=id_store[i].device_id;
            memcpy(id_send.un,id_store[i].un,4);
            writeInFile();
            return id_send;
        }
    }



    memset(id_send.mac,0xFF,8);
    id_send.panid=0xFFFF;
    id_send.gateway_id=0xFFFF;
    id_send.device_id=0xFFFF;
    memset(id_send.un,0xFF,4);
    return id_send;
}


ID_SEND MangeId::accessId(uchar *src,ushort max_id,ushort min_id)
{
    ulong i;
    uchar *ptr = src;
    memcpy(id_receive.mac,ptr,8);
    ptr+=8;
    id_receive.gateway_id = (ptr[0]<<8)+ptr[1];
    ptr+=2;
    id_receive.panid = (ptr[0]<<8)+ptr[1];
    ptr+=2;
    id_receive.frequence = (ptr[0]<<8)+ptr[1];
    ptr+=2;
    id_receive.channel = *ptr;
    ptr++;
    memcpy(id_receive.un,ptr,4);




    for(i=0;i<0xFFFF;i++)
    {
        if(memcmp(id_store[i].mac,id_receive.mac,8)==0)
        {


            memcpy(id_store[i].mac,id_receive.mac,8);
            id_store[i].gateway_id = id_receive.gateway_id;
            id_store[i].panid = id_receive.panid;
            id_store[i].frequence = id_receive.frequence;
            id_store[i].channel = id_receive.channel;
            id_store[i].device_id = i;
            memcpy(id_store[i].un,id_receive.un,4);



            memcpy(id_send.mac,id_store[i].mac,8);
            id_send.panid=id_store[i].panid;
            id_send.gateway_id=id_store[i].gateway_id;
            id_send.device_id=id_store[i].device_id;
            memcpy(id_send.un,id_store[i].un,4);
            writeInFile();
            return id_send;
        }
    }


    for(i=min_id;i<0xFF02;i++)
    {
        if(i>max_id)break;
        if(id_store[i].device_id == 0xFFFF)
        {
            memcpy(id_store[i].mac,id_receive.mac,8);
            id_store[i].gateway_id = id_receive.gateway_id;
            id_store[i].panid = id_receive.panid;
            id_store[i].frequence = id_receive.frequence;
            id_store[i].channel = id_receive.channel;
            id_store[i].device_id = i;
            memcpy(id_store[i].un,id_receive.un,4);


            memcpy(id_send.mac,id_store[i].mac,8);
            id_send.panid=id_store[i].panid;
            id_send.gateway_id=id_store[i].gateway_id;
            id_send.device_id=id_store[i].device_id;
            memcpy(id_send.un,id_store[i].un,4);
            writeInFile();
            return id_send;
        }
    }

    memset(id_send.mac,0xFF,8);
    id_send.panid=0xFFFF;
    id_send.gateway_id=0xFFFF;
    id_send.device_id=0xFFFF;
    memset(id_send.un,0xFF,4);
    return id_send;
}



ID_SEND MangeId::checkId(uchar *src)
{
    ulong i;
    uchar *ptr = src;
    memcpy(id_receive.mac,ptr,8);
    ptr+=8;
    id_receive.gateway_id = (ptr[0]<<8)+ptr[1];
    ptr+=2;
    id_receive.panid = (ptr[0]<<8)+ptr[1];
    ptr+=2;
    id_receive.frequence = (ptr[0]<<8)+ptr[1];
    ptr+=2;
    id_receive.channel = *ptr;
    ptr++;
    memcpy(id_receive.un,ptr,4);


    for(i=0;i<0xFFFF;i++)
    {
        if(memcmp(id_store[i].mac,id_receive.mac,8)==0)
        {


            memcpy(id_store[i].mac,id_receive.mac,8);
            id_store[i].gateway_id = id_receive.gateway_id;
            id_store[i].panid = id_receive.panid;
            id_store[i].frequence = id_receive.frequence;
            id_store[i].channel = id_receive.channel;
            id_store[i].device_id = i;
            memcpy(id_store[i].un,id_receive.un,4);



            memcpy(id_send.mac,id_store[i].mac,8);
            id_send.panid=id_store[i].panid;
            id_send.gateway_id=id_store[i].gateway_id;
            id_send.device_id=id_store[i].device_id;
            memcpy(id_send.un,id_store[i].un,4);
            writeInFile();
            return id_send;
        }
    }


    memset(id_send.mac,0xFF,8);
    id_send.panid=0xFFFF;
    id_send.gateway_id=0xFFFF;
    id_send.device_id=0xFFFF;
    memset(id_send.un,0xFF,4);
    return id_send;
}



QString MangeId::manuId(uchar *mac,ushort gateway_id,ushort device_id,ushort panid)
{
    ulong i;

    if(device_id>0xFF00)return "device_id>0xFF00,不进行处理";

    for(i=0;i<0xFFFF;i++)
    {
        if(memcmp(id_store[i].mac,mac,8)==0)
        {
            if(i == device_id)
            {
                memcpy(id_store[i].mac,mac,8);
                id_store[i].gateway_id = gateway_id;
                id_store[i].panid = panid;
                id_store[i].device_id = device_id;
                writeInFile();

                return getIdInf(i);
            }
            else
            {
                memset(id_store[i].mac,0xFF,8);
                id_store[i].gateway_id = 0xFFFF;
                id_store[i].panid = 0xFFFF;
                id_store[i].frequence = 0xFFFF;
                id_store[i].channel = 0xFF;
                id_store[i].device_id = 0xFFFF;
                memset(id_store[i].un,0xFF,4);

            }
        }
    }
    if(device_id<0xFF00)
    {
        memcpy(id_store[device_id].mac,mac,8);
        id_store[device_id].gateway_id = gateway_id;
        id_store[device_id].panid = panid;
        id_store[device_id].frequence = 0xFFFF;
        id_store[device_id].channel = 0xFF;
        id_store[device_id].device_id = device_id;
        memset(id_store[device_id].un,0xFF,4);
        writeInFile();

        return getIdInf(device_id);
    }
    else
    {
        return "cant not access id";
    }



}

QString MangeId::getIdInf(ushort id)
{
    QString str;

    str.clear();
    //str += QString("ID %1 information: ").arg(id);
    str += "ID 0x"+uint16ToHex(id)+ " information: ";
    str += "/ MAC:"+strToHex(id_store[id].mac , 8).toUpper();
    str += "/ Gateway_id:0x"+uint16ToHex(id_store[id].gateway_id).toUpper();
    str += "/ Panid:0x"+uint16ToHex(id_store[id].panid).toUpper();
    str += "/ Frequence:"+QString("%1MHZ").arg(id_store[id].frequence);
    str += "/ Channel:0x"+uint16ToHex(id_store[id].channel).toUpper();
    str += "/ Device_id:0x"+uint16ToHex(id_store[id].device_id).toUpper();
    str += "/ Un:"+strToHex(id_store[id].un , 4).toUpper();
    return str;
}


QString MangeId::getIdMac(ushort id)
{
    return strToHex(id_store[id].mac , 8).toUpper();
}

ushort MangeId::getIdMac(uchar *mac)
{
    uint i;
    for(i=0;i<65536;i++){
        if(id_store[i].device_id != 0xFFFF){
            if(memcmp(id_store[i].mac,mac,8)==0)return i;
        }
    }
}


ID_SEND MangeId::getIdSendInf(ushort id)
{

    memcpy(id_send.mac,id_store[id].mac,8);
    id_send.panid=id_store[id].panid;
    id_send.gateway_id=id_store[id].gateway_id;
    id_send.device_id=id_store[id].device_id;
    memcpy(id_send.un,id_store[id].un,4);
    return id_send;
}


bool MangeId::updateBindID(ushort gateway_id, ushort device_id)
{
    if(id_store[device_id].gateway_id!=gateway_id){
        id_store[device_id].gateway_id = gateway_id;
        writeInFile();
        return true;
    }
    return false;
}


void MangeId::ExportIdInformation()
{
    ulong i;
    QByteArray buff;


    buff.clear();

    for(i=0; i<65536;i++)
    {
        //buff += QString("ID %1 information: ").arg(i);
        buff += "ID 0x"+uint16ToHex(i)+ " information: ";
        buff += "/ MAC:"+strToHex(id_store[i].mac , 8).toUpper();
        buff += "/ Gateway_id:0x"+uint16ToHex(id_store[i].gateway_id).toUpper();
        buff += "/ Panid:0x"+uint16ToHex(id_store[i].panid).toUpper();
        buff += "/ Frequence:0x"+QString("%1MHZ").arg(id_store[i].frequence);
        buff += "/ Channel:0x"+uint16ToHex(id_store[i].channel).toUpper();
        buff += "/ Device_id:0x"+uint16ToHex(id_store[i].device_id).toUpper();
        buff += "/ Un:"+strToHex(id_store[i].un , 4).toUpper();
        buff += "\r\n";
    }



    QString path = QDir::currentPath();
    path+="/id_information.txt";
    QFile file(path);
    file.open(QIODevice::ReadWrite);
    file.write(buff);
    file.close();

}



QString MangeId::uint8ToHex(uchar data)
{
    QByteArray buff;
    buff[0] = data;
    return buff.toHex();
}

QString MangeId::uint16ToHex(ushort data)
{
    QByteArray buff;
    buff[0] = (data>>8)&0xFF;
    buff[1] = (data>>0)&0xFF;
    return buff.toHex();
}

QString MangeId::uint32ToHex(uint data)
{
    QByteArray buff;
    buff[0] = (data>>24)&0xFF;
    buff[1] = (data>>16)&0xFF;
    buff[2] = (data>>8)&0xFF;
    buff[3] = (data>>0)&0xFF;
    return buff.toHex();
}

QString MangeId::strToHex(uchar *data , ushort len)
{
    QByteArray buff;
    for(int i = 0 ; i<len;i++)
    {
        buff.append(data[i]);
    }
    return buff.toHex();
}


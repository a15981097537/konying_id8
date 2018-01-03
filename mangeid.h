#ifndef MANGEID_H
#define MANGEID_H

#include "qglobal.h"
#include "string.h"
#include <qfiledialog.h>

struct ID_RECEIVE
{
    uchar mac[8];
    ushort gateway_id;
    ushort panid;
    ushort frequence;
    uchar channel;
    uchar un[4];
};

struct ID_SEND
{
    uchar mac[8];
    ushort gateway_id;
    ushort panid;
    ushort device_id;
    uchar un[4];
};


struct ID_STORE
{
    uchar mac[8];
    ushort gateway_id;
    ushort panid;
    ushort frequence;
    uchar channel;
    ushort device_id;
    uchar un[4];
};





class MangeId
{
public:
    MangeId();
    ID_SEND accessId(uchar *src);
    ID_SEND accessId(uchar *src,ushort max_id,ushort min_id);
    ID_SEND checkId(uchar *src);
    QString manuId(uchar *mac,ushort gateway_id,ushort device_id,ushort panid);
    QString getIdInf(ushort id);
    QString getIdMac(ushort id);
    ID_SEND getIdSendInf(ushort id);
    void ExportIdInformation();


    QString uint8ToHex(uchar data);
    QString uint16ToHex(ushort data);
    QString uint32ToHex(uint data);
    QString strToHex(uchar *data , ushort len);
    QString resetAllId();
    QString clearId(ushort id);
    bool updateBindID(ushort gateway_id, ushort device_id);
private:
    ID_RECEIVE id_receive;
    ID_SEND id_send;
    ID_STORE id_store[65536];
    QByteArray file_read;
    void init();
    bool writeInFile();
    bool readFromFile();
};

#endif // MANGEID_H

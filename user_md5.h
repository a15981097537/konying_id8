#ifndef USER_MD5_H
#define USER_MD5_H
#include <QtGui>
#include <QtDebug>
#include <QRegExp>
#include <QTextCodec>
#include <QTime>
#include <QString>
#include <QTextCodec>
#include <QMessageBox>
#include <qfiledialog.h>

class user_MD5
{
public:

    user_MD5();
    void CalcFileMD5(const void *md5_buf , unsigned int File_len);
    byte buffer[16];
private:
#define MD5_F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define MD5_G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define MD5_H(x, y, z) ((x) ^ (y) ^ (z))
#define MD5_I(x, y, z) ((y) ^ ((x) | (~z)))
#define MD5_RL(x, y) (((x) << (y)) | ((x) >> (32 - (y))))


#define MD5_FF(a, b, c, d, x, s, ac) a = b + (MD5_RL((a + MD5_F(b,c,d) + x + ac),s))
#define MD5_GG(a, b, c, d, x, s, ac) a = b + (MD5_RL((a + MD5_G(b,c,d) + x + ac),s))
#define MD5_HH(a, b, c, d, x, s, ac) a = b + (MD5_RL((a + MD5_H(b,c,d) + x + ac),s))
#define MD5_II(a, b, c, d, x, s, ac) a = b + (MD5_RL((a + MD5_I(b,c,d) + x + ac),s))



unsigned int MD5_A,MD5_B,MD5_C,MD5_D,MD5_a,MD5_b,MD5_c,MD5_d,MD5_i,MD5_len,MD5_x[16];
unsigned char MD5_fp[64];

void Md5_ucCpytoui(unsigned int *uidest,  unsigned char *ucsrc , unsigned int uilen);
void Md5_ucSet( unsigned char *ucstr ,unsigned char ucValue, unsigned int uilen);
void Md5_uiSet( unsigned int *uistr ,unsigned int uiValue, unsigned int uilen);
void md5();

};

#endif // USER_MD5_H

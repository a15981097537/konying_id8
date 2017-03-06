#include "user_md5.h"

user_MD5::user_MD5()
{

}

void user_MD5::md5()
{



    MD5_a=MD5_A,MD5_b=MD5_B,MD5_c=MD5_C,MD5_d=MD5_D;

    /**//* Round 1 */

    MD5_FF (MD5_a, MD5_b, MD5_c, MD5_d, MD5_x[ 0], 7, 0xd76aa478); /**//* 1 */
    MD5_FF (MD5_d, MD5_a, MD5_b, MD5_c, MD5_x[ 1], 12, 0xe8c7b756); /**//* 2 */
    MD5_FF (MD5_c, MD5_d, MD5_a, MD5_b, MD5_x[ 2], 17, 0x242070db); /**//* 3 */
    MD5_FF (MD5_b, MD5_c, MD5_d, MD5_a, MD5_x[ 3], 22, 0xc1bdceee); /**//* 4 */
    MD5_FF (MD5_a, MD5_b, MD5_c, MD5_d, MD5_x[ 4], 7, 0xf57c0faf); /**//* 5 */
    MD5_FF (MD5_d, MD5_a, MD5_b, MD5_c, MD5_x[ 5], 12, 0x4787c62a); /**//* 6 */
    MD5_FF (MD5_c, MD5_d, MD5_a, MD5_b, MD5_x[ 6], 17, 0xa8304613); /**//* 7 */
    MD5_FF (MD5_b, MD5_c, MD5_d, MD5_a, MD5_x[ 7], 22, 0xfd469501); /**//* 8 */
    MD5_FF (MD5_a, MD5_b, MD5_c, MD5_d, MD5_x[ 8], 7, 0x698098d8); /**//* 9 */
    MD5_FF (MD5_d, MD5_a, MD5_b, MD5_c, MD5_x[ 9], 12, 0x8b44f7af); /**//* 10 */
    MD5_FF (MD5_c, MD5_d, MD5_a, MD5_b, MD5_x[10], 17, 0xffff5bb1); /**//* 11 */
    MD5_FF (MD5_b, MD5_c, MD5_d, MD5_a, MD5_x[11], 22, 0x895cd7be); /**//* 12 */
    MD5_FF (MD5_a, MD5_b, MD5_c, MD5_d, MD5_x[12], 7, 0x6b901122); /**//* 13 */
    MD5_FF (MD5_d, MD5_a, MD5_b, MD5_c, MD5_x[13], 12, 0xfd987193); /**//* 14 */
    MD5_FF (MD5_c, MD5_d, MD5_a, MD5_b, MD5_x[14], 17, 0xa679438e); /**//* 15 */
    MD5_FF (MD5_b, MD5_c, MD5_d, MD5_a, MD5_x[15], 22, 0x49b40821); /**//* 16 */



    /**//* Round 2 */

    MD5_GG (MD5_a, MD5_b, MD5_c, MD5_d, MD5_x[ 1], 5, 0xf61e2562); /**//* 17 */
    MD5_GG (MD5_d, MD5_a, MD5_b, MD5_c, MD5_x[ 6], 9, 0xc040b340); /**//* 18 */
    MD5_GG (MD5_c, MD5_d, MD5_a, MD5_b, MD5_x[11], 14, 0x265e5a51); /**//* 19 */
    MD5_GG (MD5_b, MD5_c, MD5_d, MD5_a, MD5_x[ 0], 20, 0xe9b6c7aa); /**//* 20 */
    MD5_GG (MD5_a, MD5_b, MD5_c, MD5_d, MD5_x[ 5], 5, 0xd62f105d); /**//* 21 */
    MD5_GG (MD5_d, MD5_a, MD5_b, MD5_c, MD5_x[10], 9, 0x02441453); /**//* 22 */
    MD5_GG (MD5_c, MD5_d, MD5_a, MD5_b, MD5_x[15], 14, 0xd8a1e681); /**//* 23 */
    MD5_GG (MD5_b, MD5_c, MD5_d, MD5_a, MD5_x[ 4], 20, 0xe7d3fbc8); /**//* 24 */
    MD5_GG (MD5_a, MD5_b, MD5_c, MD5_d, MD5_x[ 9], 5, 0x21e1cde6); /**//* 25 */
    MD5_GG (MD5_d, MD5_a, MD5_b, MD5_c, MD5_x[14], 9, 0xc33707d6); /**//* 26 */
    MD5_GG (MD5_c, MD5_d, MD5_a, MD5_b, MD5_x[ 3], 14, 0xf4d50d87); /**//* 27 */
    MD5_GG (MD5_b, MD5_c, MD5_d, MD5_a, MD5_x[ 8], 20, 0x455a14ed); /**//* 28 */
    MD5_GG (MD5_a, MD5_b, MD5_c, MD5_d, MD5_x[13], 5, 0xa9e3e905); /**//* 29 */
    MD5_GG (MD5_d, MD5_a, MD5_b, MD5_c, MD5_x[ 2], 9, 0xfcefa3f8); /**//* 30 */
    MD5_GG (MD5_c, MD5_d, MD5_a, MD5_b, MD5_x[ 7], 14, 0x676f02d9); /**//* 31 */
    MD5_GG (MD5_b, MD5_c, MD5_d, MD5_a, MD5_x[12], 20, 0x8d2a4c8a); /**//* 32 */



    /**//* Round 3 */

    MD5_HH (MD5_a, MD5_b, MD5_c, MD5_d, MD5_x[ 5], 4, 0xfffa3942); /**//* 33 */
    MD5_HH (MD5_d, MD5_a, MD5_b, MD5_c, MD5_x[ 8], 11, 0x8771f681); /**//* 34 */
    MD5_HH (MD5_c, MD5_d, MD5_a, MD5_b, MD5_x[11], 16, 0x6d9d6122); /**//* 35 */
    MD5_HH (MD5_b, MD5_c, MD5_d, MD5_a, MD5_x[14], 23, 0xfde5380c); /**//* 36 */
    MD5_HH (MD5_a, MD5_b, MD5_c, MD5_d, MD5_x[ 1], 4, 0xa4beea44); /**//* 37 */
    MD5_HH (MD5_d, MD5_a, MD5_b, MD5_c, MD5_x[ 4], 11, 0x4bdecfa9); /**//* 38 */
    MD5_HH (MD5_c, MD5_d, MD5_a, MD5_b, MD5_x[ 7], 16, 0xf6bb4b60); /**//* 39 */
    MD5_HH (MD5_b, MD5_c, MD5_d, MD5_a, MD5_x[10], 23, 0xbebfbc70); /**//* 40 */
    MD5_HH (MD5_a, MD5_b, MD5_c, MD5_d, MD5_x[13], 4, 0x289b7ec6); /**//* 41 */
    MD5_HH (MD5_d, MD5_a, MD5_b, MD5_c, MD5_x[ 0], 11, 0xeaa127fa); /**//* 42 */
    MD5_HH (MD5_c, MD5_d, MD5_a, MD5_b, MD5_x[ 3], 16, 0xd4ef3085); /**//* 43 */
    MD5_HH (MD5_b, MD5_c, MD5_d, MD5_a, MD5_x[ 6], 23, 0x04881d05); /**//* 44 */
    MD5_HH (MD5_a, MD5_b, MD5_c, MD5_d, MD5_x[ 9], 4, 0xd9d4d039); /**//* 45 */
    MD5_HH (MD5_d, MD5_a, MD5_b, MD5_c, MD5_x[12], 11, 0xe6db99e5); /**//* 46 */
    MD5_HH (MD5_c, MD5_d, MD5_a, MD5_b, MD5_x[15], 16, 0x1fa27cf8); /**//* 47 */
    MD5_HH (MD5_b, MD5_c, MD5_d, MD5_a, MD5_x[ 2], 23, 0xc4ac5665); /**//* 48 */



    /**//* Round 4 */

    MD5_II (MD5_a, MD5_b, MD5_c, MD5_d, MD5_x[ 0], 6, 0xf4292244); /**//* 49 */
    MD5_II (MD5_d, MD5_a, MD5_b, MD5_c, MD5_x[ 7], 10, 0x432aff97); /**//* 50 */
    MD5_II (MD5_c, MD5_d, MD5_a, MD5_b, MD5_x[14], 15, 0xab9423a7); /**//* 51 */
    MD5_II (MD5_b, MD5_c, MD5_d, MD5_a, MD5_x[ 5], 21, 0xfc93a039); /**//* 52 */
    MD5_II (MD5_a, MD5_b, MD5_c, MD5_d, MD5_x[12], 6, 0x655b59c3); /**//* 53 */
    MD5_II (MD5_d, MD5_a, MD5_b, MD5_c, MD5_x[ 3], 10, 0x8f0ccc92); /**//* 54 */
    MD5_II (MD5_c, MD5_d, MD5_a, MD5_b, MD5_x[10], 15, 0xffeff47d); /**//* 55 */
    MD5_II (MD5_b, MD5_c, MD5_d, MD5_a, MD5_x[ 1], 21, 0x85845dd1); /**//* 56 */
    MD5_II (MD5_a, MD5_b, MD5_c, MD5_d, MD5_x[ 8], 6, 0x6fa87e4f); /**//* 57 */
    MD5_II (MD5_d, MD5_a, MD5_b, MD5_c, MD5_x[15], 10, 0xfe2ce6e0); /**//* 58 */
    MD5_II (MD5_c, MD5_d, MD5_a, MD5_b, MD5_x[ 6], 15, 0xa3014314); /**//* 59 */
    MD5_II (MD5_b, MD5_c, MD5_d, MD5_a, MD5_x[13], 21, 0x4e0811a1); /**//* 60 */
    MD5_II (MD5_a, MD5_b, MD5_c, MD5_d, MD5_x[ 4], 6, 0xf7537e82); /**//* 61 */
    MD5_II (MD5_d, MD5_a, MD5_b, MD5_c, MD5_x[11], 10, 0xbd3af235); /**//* 62 */
    MD5_II (MD5_c, MD5_d, MD5_a, MD5_b, MD5_x[ 2], 15, 0x2ad7d2bb); /**//* 63 */
    MD5_II (MD5_b, MD5_c, MD5_d, MD5_a, MD5_x[ 9], 21, 0xeb86d391); /**//* 64 */



    MD5_A += MD5_a;
    MD5_B += MD5_b;
    MD5_C += MD5_c;
    MD5_D += MD5_d;



}

void user_MD5::Md5_ucCpytoui(unsigned int *uidest, unsigned char *ucsrc , unsigned int uilen)
{
    for(unsigned int i=0;i<uilen;i++)
    {
        uidest[i/4] |= (unsigned int)(ucsrc[i])<<((i%4)*8);
    }
}

void user_MD5::Md5_ucSet( unsigned char *ucstr ,unsigned char ucValue, unsigned int uilen)
{
    for(unsigned int i=0;i<uilen;i++)
    {
        ucstr[i] = ucValue;
    }
}
void user_MD5::Md5_uiSet( unsigned int *uistr ,unsigned int uiValue, unsigned int uilen)
{
    for(unsigned int i=0;i<uilen;i++)
    {
        uistr[i] = uiValue;
    }
}




void user_MD5::CalcFileMD5(const void *md5_buf , size_t File_len)
{

    const byte *src = (byte* )md5_buf;
    byte *ptr;

    MD5_A=0x67452301,MD5_B=0xefcdab89,MD5_C=0x98badcfe,MD5_D=0x10325476;

    MD5_len=File_len;

    for(MD5_i=0; MD5_i<MD5_len/64; MD5_i++)
    {

        Md5_uiSet(MD5_x,0,16);

        Md5_ucSet(MD5_fp,0,64);

        //halEepromRead(File_addr,MD5_fp,64);//一次读取64个字节
        memcpy(MD5_fp,&src[64*MD5_i],64);

        //File_addr += 64;

        Md5_ucCpytoui(MD5_x,MD5_fp,64);

        md5();

    }

    if(MD5_len%64)
    {

        Md5_uiSet(MD5_x,0,16);

        Md5_ucSet(MD5_fp,0,64);

        //halEepromRead(File_addr,MD5_fp,MD5_len%64);//读写最后的字节
        memcpy(MD5_fp,&src[64*MD5_i],MD5_len%64);

        Md5_ucCpytoui(MD5_x,MD5_fp,64);

        md5();
    }


    ptr = buffer;
    *ptr++ = (MD5_A>>24)&0xFF;
    *ptr++ = (MD5_A>>16)&0xFF;
    *ptr++ = (MD5_A>>8)&0xFF;
    *ptr++ = (MD5_A>>0)&0xFF;
    *ptr++ = (MD5_B>>24)&0xFF;
    *ptr++ = (MD5_B>>16)&0xFF;
    *ptr++ = (MD5_B>>8)&0xFF;
    *ptr++ = (MD5_B>>0)&0xFF;
    *ptr++ = (MD5_C>>24)&0xFF;
    *ptr++ = (MD5_C>>16)&0xFF;
    *ptr++ = (MD5_C>>8)&0xFF;
    *ptr++ = (MD5_C>>0)&0xFF;
    *ptr++ = (MD5_D>>24)&0xFF;
    *ptr++ = (MD5_D>>16)&0xFF;
    *ptr++ = (MD5_D>>8)&0xFF;
    *ptr++ = (MD5_D>>0)&0xFF;



}

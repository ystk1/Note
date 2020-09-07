// C_TEST.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include "lib_mojiretu.h"


/**
* main関数
*
* @param[in] 
* @param[out] 
* @return 
*/
int _tmain(int argc, _TCHAR *argv[])
{
    unsigned char cbuf[64];
    memset(cbuf, 0x00, sizeof(cbuf));

//! 10進⇒ASCII変換 test 
    decToASCIIHex(45, 4, cbuf);

//! 10進⇒ASCII変換 test 
    decToASCIIHex(0xABCD, 4, cbuf);

    int itest = 0x12345;
    int ibuf;
    ibuf = itest >> 4;

    char cbuf1[20] = {};
    char cbuf2[6]  = {"TEST"};
    char cbuf3[4]  = {"123"};
    char *pcbuf1   = cbuf1;

    pcbuf1 = my_strcpy(cbuf1, cbuf2);
    pcbuf1 = my_strcpy(pcbuf1, cbuf3);


    unsigned char cbuf12[64];
    unsigned char* pcbuf12 = cbuf12;
    memset( cbuf12,0x00, sizeof(cbuf12));
    pcbuf12  = AddValASCII2USHORT(12,4,pcbuf12);
    pcbuf12  = AddValASCII2USHORT(555,4,pcbuf12);
    pcbuf12  = AddValASCII2USHORT(1234,4,pcbuf12);
    pcbuf12  = AddValASCII2USHORT(123,4,pcbuf12);
    pcbuf12  = AddValASCII2USHORT(1234,4,pcbuf12);
    pcbuf12  = AddValASCII2USHORT(1,4,pcbuf12);



    return 0;
}

// C_TEST.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include "lib_mojiretu.h"

/**
* unsigned short型数値⇒ASCII文字生成
*
* @param[in]    usval : 数値 ucFig : 桁数(最大16まで) 
* @param[out] 
* @return 
*/
unsigned char* AddValASCII2USHORT(unsigned short usval, unsigned char ucFig,unsigned char* pchar)
{
    unsigned char uctemp[16];
    memset(uctemp, 0x0,sizeof(uctemp));

    decToASCIIHex( usval, ucFig,uctemp);
    return (unsigned char *)my_strcpy((char *)pchar, (char *)uctemp);
}


/**
 * unsigned short型の数値をASCII 16進数の指定桁数分の文字列に変換する
 *
 * @param[in] usval 数値 , iFig 文字列桁数
 * @param[out] ptar ASCII16進文字列(iFig桁分の文字列長さ)
 * @return
 */
int decToASCIIHex(unsigned short usVal, unsigned char ucFig, unsigned char *ptar)
{
    char hexaDeciNum[8]; // 最大iFig 8桁数
    // int iCnt = 0;

    memset(hexaDeciNum, 0x00, sizeof(hexaDeciNum));

    // counter for hexadecimal number array
    int i = 0;
    while (usVal != 0) {
        // temporary variable to store remainder
        int temp = 0;

        // storing remainder in temp variable.
        temp = usVal % 16;

        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + 0x30; // 0~
            i++;
        } else {
            hexaDeciNum[i] = temp + 0x37; // A~
            i++;
        }

        usVal = usVal / 16;
    }

    for (unsigned char j = 0; j < ucFig; j++) {
        *(ptar + j) = (hexaDeciNum[(ucFig - 1) - j] == 0x00) ? '0' : hexaDeciNum[(ucFig - 1) - j];
    }

    return 0;
}

/**
 * 文字列結合
 *
 * @param[in]
 * @param[out]
 * @return
 */
char *my_strcpy(char *dest, const char *src)
{
    char *tmp = dest;
    int icnt  = 0;

    while ((*dest++ = *src++) != '\0') {
        icnt++;
    }
    return tmp + icnt;
}

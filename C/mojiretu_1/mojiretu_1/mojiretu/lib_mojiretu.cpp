// C_TEST.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include "lib_mojiretu.h"

/**
* unsigned short�^���l��ASCII��������
*
* @param[in]    usval : ���l ucFig : ����(�ő�16�܂�) 
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
 * unsigned short�^�̐��l��ASCII 16�i���̎w�茅�����̕�����ɕϊ�����
 *
 * @param[in] usval ���l , iFig �����񌅐�
 * @param[out] ptar ASCII16�i������(iFig�����̕����񒷂�)
 * @return
 */
int decToASCIIHex(unsigned short usVal, unsigned char ucFig, unsigned char *ptar)
{
    char hexaDeciNum[8]; // �ő�iFig 8����
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
 * �����񌋍�
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

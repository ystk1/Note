#include "stdio.h"
#include <string.h>
#include "lib.h"

/**
* ���l��ASCII�����i�w�茅���j�ɕϊ�����
*
* @param[in] usVal : ���l iFig : ASCII����
* @param[out] 
* @return ASCII��������߲��
*/
unsigned char*  decToASCIIHex(unsigned short usVal, int iFig)
{
    static char hexaDeciNum[16];                     // �ő�iFig 16����
    static unsigned char cASCII[16];                    // �ϊ��� ASCII�����ő�iFig 16����
    memset(hexaDeciNum, 0x00, sizeof(hexaDeciNum)); // ��Ɨp�ޯ̧������
    unsigned char *p_ret = cASCII;


    //!   ���l��ASCII����(�w�茅��)�ɕϊ�
    int i = 0;
    while (usVal != 0) {
        int temp = 0;
        temp     = usVal % 16;

        if (temp < 10) {
            hexaDeciNum[i] = temp + 0x30; // 0~
            i++;
        } else {
            hexaDeciNum[i] = temp + 0x37; // A~
            i++;
        }
        usVal = usVal / 16;
    }

    for (int j = 0; j < iFig; j++) {
        *(p_ret + j) = (hexaDeciNum[(iFig - 1) - j] == 0x00) ? '0' : hexaDeciNum[(iFig - 1) - j];
    }

    return p_ret;
}



/**
 * �����񌋍�
 *
 * @param[in] 	dest : ��߰����ڽ  src :��߰�����ڽ
 * @param[out]
 * @return ������̕�����I�[�ʒu�������߲����Ԃ�
 */
unsigned char *my_strcpy(unsigned char *dest, const unsigned char *src)
{
    unsigned char *tmp = dest;
    int icnt           = 0;

    while ((*dest++ = *src++) != '\0') {
        icnt++;
    }

    return tmp + icnt;
}

/**
* enum �ް� �ݸ����
*
* @param[in] 
* @param[out] 
* @return 
*/
void UpEnumParameter(short* psEnumData, short sRangeOver)
{
	if (*psEnumData < sRangeOver-1) {
		++*psEnumData;
	} else {
		*psEnumData = 0;
	}
}

/**
* enum �ް� �ݸ���� (�����l�w���)
*
* @param[in] 
* @param[out] 
* @return 
*/
void UpEnumParameter2(short* psEnumData, short sMinimum, short sRangeOver)
{
	if (*psEnumData < sRangeOver-1) {
		++*psEnumData;
	} else {
		*psEnumData = sMinimum;
	}
}
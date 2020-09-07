#include "stdio.h"
#include <string.h>
#include "lib.h"

// /**
//  * unsigned short�^�̕ϐ��l��ASCII 16�i���̎w�茅�����̕�����ɕϊ����� �i������ϊ��ۑ���̻��� ���菈���L & NULL�������L)
//  *
//  * @param[in] usval ���l , iFig �����񌅐�
//  * @param[out] ptar ASCII16�i������(iFig�����̕����񒷂�)
//  * @return
//  */
// EN_RETURN_CODE decToASCIIHex_s(unsigned short usVal, int iFig, unsigned char *ptar, unsigned char ucSz)
// {

//     // ������o�͐��߲���̕����񻲽ނ�8���傫���ꍇ�A�װ�o��
//     if (ucSz > 8) {
//         return en_RETURN_CODE_NG;
//     }

//     memset(ptar, 0x00, ucSz * sizeof(unsigned char)); // �����o�͐��߲���y���ޯ̧���ޗ̈� NULL�ɏ�����
//     EN_RETURN_CODE decToASCIIHex(unsigned short usVal, int iFig, unsigned char *ptar);
//     return en_RETURN_CODE_OK;
// }

/**
 * unsigned short�^�̕ϐ��l��ASCII 16�i���̎w�茅�����̕�����ɕϊ�����
 *
 * @param[in] usval ���l , iFig �����񌅐�
 * @param[out] ptar ASCII16�i������(iFig�����̕����񒷂�)
 * @return
 */
//EN_RETURN_CODE decToASCIIHex(unsigned short usVal, int iFig, unsigned char *ptar)
//{
//    char hexaDeciNum[8];                            // �ő�iFig 8����
//    memset(hexaDeciNum, 0x00, sizeof(hexaDeciNum)); // ��Ɨp�ޯ̧������
//
//    //!   ���l��ASCII����(�w�茅��)�ɕϊ�
//    int i = 0;
//    while (usVal != 0) {
//        int temp = 0;
//        temp     = usVal % 16;
//
//        if (temp < 10) {
//            hexaDeciNum[i] = temp + 0x30; // 0~
//            i++;
//        } else {
//            hexaDeciNum[i] = temp + 0x37; // A~
//            i++;
//        }
//        usVal = usVal / 16;
//    }
//
//    for (int j = 0; j < iFig; j++) {
//        *(ptar + j) = (hexaDeciNum[(iFig - 1) - j] == 0x00) ? '0' : hexaDeciNum[(iFig - 1) - j];
//    }
//
//    return en_RETURN_CODE_OK;
//}

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
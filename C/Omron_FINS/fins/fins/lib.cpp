#include "stdio.h"
#include <string.h>
#include "lib.h"

/**
* 数値をASCII文字（指定桁数）に変換する
*
* @param[in] usVal : 数値 iFig : ASCII桁数
* @param[out] 
* @return ASCII文字列のﾎﾟｲﾝﾀ
*/
unsigned char*  decToASCIIHex(unsigned short usVal, int iFig)
{
    static char hexaDeciNum[16];                     // 最大iFig 16桁数
    static unsigned char cASCII[16];                    // 変換後 ASCII文字最大iFig 16桁数
    memset(hexaDeciNum, 0x00, sizeof(hexaDeciNum)); // 作業用ﾊﾞｯﾌｧ初期化
    unsigned char *p_ret = cASCII;


    //!   数値⇒ASCII文字(指定桁数)に変換
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
 * 文字列結合
 *
 * @param[in] 	dest : ｺﾋﾟｰ先ｱﾄﾞﾚｽ  src :ｺﾋﾟｰ元ｱﾄﾞﾚｽ
 * @param[out]
 * @return 結合後の文字列終端位置を示すﾎﾟｲﾝﾀを返す
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
* enum ﾃﾞｰﾀ ｲﾝｸﾘﾒﾝﾄ
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
* enum ﾃﾞｰﾀ ｲﾝｸﾘﾒﾝﾄ (下限値指定版)
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
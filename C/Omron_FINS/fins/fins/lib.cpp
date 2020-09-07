#include "stdio.h"
#include <string.h>
#include "lib.h"

// /**
//  * unsigned short型の変数値をASCII 16進数の指定桁数分の文字列に変換する （文字列変換保存先のｻｲｽﾞ 判定処理有 & NULL初期化有)
//  *
//  * @param[in] usval 数値 , iFig 文字列桁数
//  * @param[out] ptar ASCII16進文字列(iFig桁分の文字列長さ)
//  * @return
//  */
// EN_RETURN_CODE decToASCIIHex_s(unsigned short usVal, int iFig, unsigned char *ptar, unsigned char ucSz)
// {

//     // 文字列出力先ﾎﾟｲﾝﾀの文字列ｻｲｽﾞが8より大きい場合、ｴﾗｰ出力
//     if (ucSz > 8) {
//         return en_RETURN_CODE_NG;
//     }

//     memset(ptar, 0x00, ucSz * sizeof(unsigned char)); // 文字出力先ﾎﾟｲﾝﾀ及びﾊﾞｯﾌｧｻｲｽﾞ領域 NULLに初期化
//     EN_RETURN_CODE decToASCIIHex(unsigned short usVal, int iFig, unsigned char *ptar);
//     return en_RETURN_CODE_OK;
// }

/**
 * unsigned short型の変数値をASCII 16進数の指定桁数分の文字列に変換する
 *
 * @param[in] usval 数値 , iFig 文字列桁数
 * @param[out] ptar ASCII16進文字列(iFig桁分の文字列長さ)
 * @return
 */
//EN_RETURN_CODE decToASCIIHex(unsigned short usVal, int iFig, unsigned char *ptar)
//{
//    char hexaDeciNum[8];                            // 最大iFig 8桁数
//    memset(hexaDeciNum, 0x00, sizeof(hexaDeciNum)); // 作業用ﾊﾞｯﾌｧ初期化
//
//    //!   数値⇒ASCII文字(指定桁数)に変換
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
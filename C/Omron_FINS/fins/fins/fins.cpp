#include "stdio.h"
#include "lib.h"
#include "Test.h"
#include <string>

//** ﾃﾞﾊﾞｯｸﾞ　ﾌﾟﾘﾌﾟﾛｾｯｻ */
#ifdef _DEBUG
volatile struct TDATA_SH tdat; // SH2で使用するティーチングデータ
// unsigned char ucTemp[200];                      // 作業用ﾊﾞｯﾌｧ

typedef struct
{
    unsigned char uc_CommDatBuf[200]; //! 送受信ﾊﾞｯﾌｧ
    unsigned char *puc_commdatbufCur; //! 送受信ﾊﾞｯﾌｧﾎﾟｲﾝﾀ
} TS_COMM_BUF;

TS_COMM_BUF ts_SendDatTemp; // 送信ﾊﾞｯﾌｧ
TS_COMM_BUF ts_RecvDatTemp; // 受信ﾊﾞｯﾌｧ

unsigned char Ichg(unsigned char i);
unsigned char Ihex(unsigned char i, unsigned char j);
unsigned short Ihexn(unsigned char *asc, unsigned char cnt);

#endif

//** 定数宣言 */
//! FINS MEMORY TYPE
#define DM_TYPE     ("82")          // DM ⇒(82)ASCII

// //! FINS HEADER (ASCII)
#define FINS_HEADER	"@00FA000000000"			// FINS 送信HEADDER @00FA000000000

//! FINS COMMAND TYPE (ASCII)
#define FINS_CMDTYPE_WRITE "0101"
#define FINS_CMDTYPE_READ "0102"

//** 列挙　宣言部 */
//! FINS ｺﾏﾝﾄﾞ
typedef enum{
    en_FINSCMD_DM0 =0,
    en_FINSCMD_DM20,
    en_FINSCMD_DM1000,
    en_FINSCMD_DM1500,
    en_FINSCMD_DM1520,
    en_FINSCMD_NUM
}TE_FINSCMD;

//! FINS 通信方向 
typedef enum{
    en_FINSDIRE_WRITE =0,
    en_FINSDIRE_READ,
    en_FINSDIRE_NUM
}TE_FINSDIRE;


//** 構造体　宣言部 */

//! FINS通信関連　ﾃﾞｰﾀ構造体
typedef struct
{
    TE_FINSCMD te_cmd;           // 通信ｺﾏﾝﾄﾞ
    TE_FINSDIRE te_direction;    // 通信方向
    unsigned char uc_MemType[3]; // 通信先 PLCﾒﾓﾘﾀｲﾌﾟ(2byte)
    unsigned char uc_Addr[5];    // 送受信　先頭ｱﾄﾞﾚｽ(ASCII 4byte)
    unsigned char uc_Sz;         // 送受信 ｱﾄﾞﾚｽ領域ｻｲｽﾞ
} TS_FINS_INF;

//** 定数宣言 */
//!　PLC通信ｺﾏﾝﾄﾞ 定数部
const TS_FINS_INF FINS_INF[en_FINSCMD_NUM] = {
    {en_FINSCMD_DM0, en_FINSDIRE_WRITE, DM_TYPE, "0000", 20},    // DM0ｺﾏﾝﾄﾞ
    {en_FINSCMD_DM20, en_FINSDIRE_WRITE, DM_TYPE, "0014", 20},   // DM20ｺﾏﾝﾄﾞ
    {en_FINSCMD_DM1000, en_FINSDIRE_READ, DM_TYPE, "03E8", 20}, // DM1000ｺﾏﾝﾄﾞ
    {en_FINSCMD_DM1500, en_FINSDIRE_WRITE, DM_TYPE, "05DC", 20}, // DM1500ｺﾏﾝﾄﾞ
    {en_FINSCMD_DM1520, en_FINSDIRE_WRITE, DM_TYPE, "05F0", 20}  // DM1520ｺﾏﾝﾄﾞ
};


//** 静的 変数*/


//** 静的関数　宣言 */
static void FINS_CommString(TE_FINSDIRE en_dire, const unsigned char *pcuc_MemType, const unsigned char *pucAdd, unsigned char ucSz, unsigned char *pcFINS_DatSection,TS_COMM_BUF* pComBuf); // FINS　通信文字列生成

static EN_RETURN_CODE CreateFinsDatSection(TE_FINSCMD encmd, unsigned char *pucDat, unsigned char ucSz); // FINS 通信ﾃﾞｰﾀ部生成

static EN_RETURN_CODE Check_RecvDat(TE_FINSDIRE en_dire, TS_COMM_BUF *ptsComBuf); // FINS 受信ﾃﾞｰﾀ整合性のﾁｪｯｸ
static EN_RETURN_CODE Parser_RecvDat(TE_FINSCMD en_cmd, TS_COMM_BUF *ptsComBuf);  // FINS 受信ﾃﾞｰﾀ解析

/**
 * FINS　ﾃﾞｰﾀ部を生成
 *
 * @param[in]
 * @param[out]
 * @return
 */
static EN_RETURN_CODE CreateFinsDatSection(TE_FINSCMD encmd, unsigned char *pucDat, unsigned char ucSz)
{
    memset(pucDat, 0x00, ucSz * sizeof(unsigned char)); // NULL初期化
    unsigned char ustemp[5];                     // 作業用ﾊﾞｯﾌｧ

    // 書き込みﾊﾞｯﾌｧｻｲｽﾞが足りるか
    if (ucSz < FINS_INF[encmd].uc_Sz) {
        return en_RETURN_CODE_NG; // 書き込みﾊﾞｯﾌｧｻｲｽﾞが足りない
    }

    switch (encmd) {
    //! DM0
    case en_FINSCMD_DM0: 
	{
                //!  DM0 ~ DM19 書き込み
        // DM0 ~ DM..
        // PP1ｻｲｸﾙﾀｲﾑｱｳﾄ(4桁)
        pucDat = my_strcpy(pucDat,  decToASCIIHex(tdat.g_tm.PP_T1, 4));

        // PP出引動作ﾀｲﾑｱｳﾄ(4桁)
        pucDat = my_strcpy(pucDat,  decToASCIIHex(tdat.g_tm.PP_T2, 4));

        // PP開閉動作ﾀｲﾑｱｳﾄ(4桁)
        pucDat = my_strcpy(pucDat,  decToASCIIHex(tdat.g_tm.PP_T3, 4));

        // PP原点復帰動作ﾀｲﾑｱｳﾄ
        pucDat = my_strcpy(pucDat,  decToASCIIHex(tdat.g_tm.PP_T4, 4));

        // PP原点復帰offﾃﾞｨﾚｰﾀｲﾏ(開閉)
        pucDat = my_strcpy(pucDat,  decToASCIIHex(tdat.g_tm.PP_T5, 4));

        // PP原点復帰onﾃﾞｨﾚｰﾀｲﾏ(開閉)
        pucDat = my_strcpy(pucDat,  decToASCIIHex(tdat.g_tm.PP_T6, 4));

        // PP原点復帰offﾃﾞｨﾚｰﾀｲﾏ(伸縮)
        pucDat = my_strcpy(pucDat,  decToASCIIHex(tdat.g_tm.PP_T7, 4));

        // PP原点復帰onﾃﾞｨﾚｰﾀｲﾏ(伸縮)
        pucDat = my_strcpy(pucDat,  decToASCIIHex(tdat.g_tm.PP_T8, 4));

        // 予備
        pucDat = my_strcpy(pucDat,  decToASCIIHex(0, 4)); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)

        // 予備
        pucDat = my_strcpy(pucDat,  decToASCIIHex(0, 4)); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)

        // 微小開動作
        pucDat = my_strcpy(pucDat, decToASCIIHex(tdat.g_tm.PP_T1, 4));
        // decToASCIIHex(tdat.g_fw.oPP, 4, ustemp);
        // pucDat = my_strcpy(pucDat, ustemp);

        pucDat = my_strcpy(pucDat, decToASCIIHex(0, 4)); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)
        pucDat = my_strcpy(pucDat, decToASCIIHex(0, 4)); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)
        pucDat = my_strcpy(pucDat, decToASCIIHex(0, 4)); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)
        pucDat = my_strcpy(pucDat, decToASCIIHex(0, 4)); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)
        pucDat = my_strcpy(pucDat, decToASCIIHex(0, 4)); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)
        pucDat = my_strcpy(pucDat, decToASCIIHex(0, 4)); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)
        pucDat = my_strcpy(pucDat, decToASCIIHex(0, 4)); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)
        pucDat = my_strcpy(pucDat, decToASCIIHex(0, 4)); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)

     break;
    }
    }

	return en_RETURN_CODE_OK;
}

/**
* FINS 送信ﾃﾞｰﾀ文字列生成
*
* @param[in] 
* @param[out] 
* @return 
*/
static void FINS_CommString( TE_FINSDIRE en_dire, const unsigned char* pcuc_MemType, const unsigned char* pucAdd, unsigned char ucSz, unsigned char* pcFINS_DatSection,TS_COMM_BUF* pComBuf)
{
    unsigned char* pcur = pComBuf->uc_CommDatBuf;
    char cFcs;
    unsigned char* pfciIdx;     // FCI導出時にFOR文で使用する
    
    memset( pComBuf->uc_CommDatBuf, 0x00, sizeof( pComBuf->uc_CommDatBuf));     // 送信ﾊﾞｯﾌｧ初期化

    //! 通信HEADER生成 
    pcur = my_strcpy(pcur, (unsigned char*)FINS_HEADER);

    //! 通信方向
    pcur =  (en_dire ==en_FINSDIRE_WRITE) ? my_strcpy(pcur,(unsigned char*)FINS_CMDTYPE_WRITE) :my_strcpy(pcur,(unsigned char*)FINS_CMDTYPE_READ);

 	//! memory type
    pcur =  my_strcpy(pcur,pcuc_MemType);

 	//! ｱﾄﾞﾚｽｾｯﾄ
    pcur =  my_strcpy(pcur,pucAdd);

    //! 固定文字 0x0000 (2桁)
    pcur = my_strcpy(pcur, (unsigned char *)"00");

 	//! ｻｲｽﾞ (4桁)
    pcur =my_strcpy( pcur, decToASCIIHex(ucSz, 4));

 	//! ﾃﾞｰﾀ部
     pcur = my_strcpy(pcur, pcFINS_DatSection);

 	//! FCI
  	cFcs = 0;								
	for( pfciIdx = pComBuf->uc_CommDatBuf; *pfciIdx !=NULL;){
		cFcs ^= *pfciIdx++;
	}
    pcur = my_strcpy(pcur, decToASCIIHex(cFcs, 2));

 	//! 終端ｺｰﾄﾞ 
     *pcur = '*'; 
     *pcur++;
     *pcur = 0x0d;  // CR
     *pcur++;
}

/**
* FINS 受信文字列を解析
*
* @param[in] 
* @param[out] 
* @return 
*/
static EN_RETURN_CODE Check_RecvDat(TE_FINSDIRE en_dire, TS_COMM_BUF *ptsComBuf)
{
    unsigned char *puc_RecvDatCur = ptsComBuf->uc_CommDatBuf;
    char cFcs;

    //! '@'確認
    if (*puc_RecvDatCur != '@') {
        // 受信ﾃﾞｰﾀ不正
    }

    //! FCS確認
    for (cFcs = 0; *(puc_RecvDatCur + 2) != '*'; puc_RecvDatCur++) {
        cFcs ^= *puc_RecvDatCur;
    }
    // FCS OK? (ここの時点では、puc_RecvDatCur はFCSの最初の1byte位置を指し示している）
    if (Ihex(*puc_RecvDatCur, *(puc_RecvDatCur + 1)) != cFcs) {
        return en_RETURN_FCS_ERR;
    }

    //!   Hedder,Rcode OK?
    puc_RecvDatCur = &ptsComBuf->uc_CommDatBuf[3];
    if (Ihexn(puc_RecvDatCur, 4) != 0xfa00) { // Hedder,Rcode OK?
        return en_RETUEN_RECVDAT_ERR;
    }

    //! ICF+DA2 OK?
    puc_RecvDatCur = &ptsComBuf->uc_CommDatBuf[7];
    if (Ihexn(puc_RecvDatCur, 4) != 0x4000) { // Hedder,Rcode OK?
        return en_RETUEN_RECVDAT_ERR;
    }

    //! SA2+SID OK?
    puc_RecvDatCur = &ptsComBuf->uc_CommDatBuf[11];
    if (Ihexn(puc_RecvDatCur, 4) != 0x0000) { // Hedder,Rcode OK?
        return en_RETUEN_RECVDAT_ERR;
    }

    //! ｱﾄﾞﾚｽ先書き込みor読み込みで処理分岐
    if (en_dire == en_FINSDIRE_READ) {
        //!  0101?
        puc_RecvDatCur = &ptsComBuf->uc_CommDatBuf[15];
        if (Ihexn(puc_RecvDatCur, 4) != 0x0101) { // 読み出しｺﾏﾝﾄﾞ?
            return en_RETUEN_RECVDAT_ERR;
        }

        else {
            //! 0102 省略
        }
    }

    //! 正常終了?
    puc_RecvDatCur = &ptsComBuf->uc_CommDatBuf[19];
    if (en_dire == en_FINSDIRE_READ) {
       if (Ihexn(puc_RecvDatCur, 4) >= 0x0000) { // 正常終了?
            return en_RETUEN_RECVDAT_ERR;
        }
    } else {
      
        if (Ihexn(puc_RecvDatCur, 4) != 0x0000) { // 正常終了?
            return en_RETUEN_RECVDAT_ERR;
        }
    }

    return en_RETURN_CODE_OK;
}

/**
* FINS 受信文字 解析
*
* @param[in] 
* @param[out] 
* @return 
*/
static EN_RETURN_CODE Parser_RecvDat(TE_FINSCMD en_cmd, TS_COMM_BUF *ptsComBuf)
{
    unsigned char *puc_RecvDatCur;
    unsigned short usbuf;

    switch (en_cmd) {
    case en_FINSCMD_DM1000: {
        puc_RecvDatCur = &ptsComBuf->uc_CommDatBuf[19];

        usbuf = Ihexn(puc_RecvDatCur, 4); // 受信ﾒﾓﾘﾊﾞｯﾌｧｻｲｽﾞ取得
        if (usbuf != 20) {
            return en_RETURN_CODE_NG;
        }

        // DM1000取得
        puc_RecvDatCur = &ptsComBuf->uc_CommDatBuf[23];
        usbuf          = Ihexn(puc_RecvDatCur, 4);
        g_Read_D1000   = (short)usbuf;

        // DM1010取得
        puc_RecvDatCur = &ptsComBuf->uc_CommDatBuf[23 + 4 * 10];
        usbuf          = Ihexn(puc_RecvDatCur, 4);
        g_Read_D1010   = (short)usbuf;

        // DM1011取得
        puc_RecvDatCur = &ptsComBuf->uc_CommDatBuf[23 + 4 * 11];
        usbuf          = Ihexn(puc_RecvDatCur, 4);
        g_Read_D1011   = (short)usbuf;

        break;
    }
    }

    return en_RETURN_CODE_OK;
}

//
//	switch( g_cS3Tflg) {
//	case 0:										// ポーリング
//		
//		if( Ihexn( pSinb, 4) != 0x0101) {		// 読み出しｺﾏﾝﾄﾞ?
//			break;
//		}
//		pSinb += 4;
//		if( Ihexn( pSinb, 4) != 0x0000) {		// 正常終了?
//			break;
//		}
//		pSinb += 4;
//n
//		g_Read_D1000 = Ihexn( pSinb, 4 );		// D1000
//		pSinb += 4;
//
////		g_Read_D1001 = Ihexn( pSinb, 4 );		// D1001
//
//		pSinb += 40;
//
//		g_Read_D1010 = Ihexn( pSinb, 4 );		// D1010
//		pSinb += 4;
//		g_Read_D1011 = Ihexn( pSinb, 4 );		// D1011
//		pSinb += 4;
//
////		g_lRead_D0 = (long)((unsigned int)nHiDat << 16) | (unsigned int)nLowDat;
//
//		break;
//
//	case 1:
//
//		pSinb += 4;
//		if( Ihexn( pSinb, 4) != 0x0000) {		// 正常終了?
//			break;
//		}
//		pSinb += 4;
//		g_cS3Txd[0] = 0;						// 完了
//		strcpy( g_cS3Rxd, pSinb);				// 受信データをコピー
//		break;
//	}
//	}else if(g_cS3TflgA){
//		
//	} 
//}

#ifdef _DEBUG

unsigned char Ichg(unsigned char i)
{
    unsigned char j;
    j = 0;
    if ((i >= 0x30) && (i < 0x3a)) /* 0....9 */
        j = i & 0x0f;
    if ((i >= 0x41) && (i < 0x47)) /* A....F */
        j = i - 0x37;
    return (j);
}
unsigned char	Ihex(unsigned char	i,unsigned char	j)
{
	unsigned char	k;

	k = (Ichg(i) << 4) + Ichg(j);
	return(k);
}

unsigned short Ihexn(unsigned char	*asc,unsigned char	cnt)
{
	int hex;

	for( hex = 0; cnt != 0; cnt--){
		hex |= Ichg( *asc++) << ((cnt-1) * 4);
		}
	return( hex);
}




int main()
{
    unsigned char ucBuff[200];

    tdat.g_tm.PP_T1 = 100;
    tdat.g_tm.PP_T2 = 200;
    tdat.g_tm.PP_T3 = 300;
    tdat.g_tm.PP_T4 = 400;
    tdat.g_tm.PP_T5 = 500;
    tdat.g_tm.PP_T6 = 600;
    tdat.g_tm.PP_T7 = 700;
    tdat.g_tm.PP_T8 = 800;

    CreateFinsDatSection(en_FINSCMD_DM0, ucBuff, sizeof(ucBuff));

    // 送信ﾊﾞｯﾌｧ ｸﾘｱ
    memset(ts_SendDatTemp.uc_CommDatBuf, 0x00, sizeof(ts_SendDatTemp.uc_CommDatBuf));
    ts_SendDatTemp.puc_commdatbufCur = ts_SendDatTemp.uc_CommDatBuf;

    FINS_CommString(FINS_INF[en_FINSCMD_DM0].te_direction, FINS_INF[en_FINSCMD_DM0].uc_MemType, FINS_INF[en_FINSCMD_DM0].uc_Addr, FINS_INF[en_FINSCMD_DM0].uc_Sz, ucBuff, &ts_SendDatTemp);

    return 0;
}
#endif
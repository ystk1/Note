#include "stdio.h"
#include "lib.h"
#include "Test.h"
#include <string>

//** 定数宣言 */
//! FINS MEMORY TYPE
#define DM_TYPE     ("82")          // DM ⇒(82)ASCII

// //! FINS HEADER (ASCII)
#define FINS_HEADER	"@00FA000000000"			// FINS 送信HEADDER @00FA000000000 + 0101  (0101は送信を意味する)

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
    TE_FINSCMD te_cmd;					// 通信ｺﾏﾝﾄﾞ
    TE_FINSDIRE te_direction;			// 通信方向
    unsigned char	uc_MemType[3];			// 通信先 PLCﾒﾓﾘﾀｲﾌﾟ(2byte)
    unsigned char  uc_Addr[5];            // 送受信　先頭ｱﾄﾞﾚｽ(ASCII 4byte)
    unsigned char   uc_Sz;                  // 送受信 ｱﾄﾞﾚｽ領域ｻｲｽﾞ
}TS_FINS_INF;

//** 定数宣言 */
//!　PLC通信ｺﾏﾝﾄﾞ 定数部 
const TS_FINS_INF FINS_INF[en_FINSCMD_NUM] = {
    {en_FINSCMD_DM0,    en_FINSDIRE_WRITE, DM_TYPE, "0000",20},       // DM0ｺﾏﾝﾄﾞ
    {en_FINSCMD_DM20,   en_FINSDIRE_WRITE, DM_TYPE, "0014",20},       // DM20ｺﾏﾝﾄﾞ
    {en_FINSCMD_DM1000, en_FINSDIRE_WRITE, DM_TYPE, "03E8",20},       // DM1000ｺﾏﾝﾄﾞ
    {en_FINSCMD_DM1500, en_FINSDIRE_WRITE, DM_TYPE, "05DC",20},       // DM1500ｺﾏﾝﾄﾞ
    {en_FINSCMD_DM1520, en_FINSDIRE_WRITE, DM_TYPE, "05F0",20}       // DM1520ｺﾏﾝﾄﾞ
};


//** 静的 変数*/


//** 静的関数　宣言 */
static void FINS_CommString(TE_FINSDIRE en_dire, const unsigned char *pcuc_MemType, const unsigned char *pucAdd, unsigned char ucSz, unsigned char *pcFINS_DatSection); // FINS　通信文字列生成

static void CreateFinsDatSection(); // FINS 通信ﾃﾞｰﾀ部生成

static void Parser_RecvDat();   // FINS 受信ﾃﾞｰﾀ解析

//** ﾃﾞﾊﾞｯｸﾞ　ﾌﾟﾘﾌﾟﾛｾｯｻ */
#ifdef _DEBUG
volatile struct TDATA_SH tdat;					// SH2で使用するティーチングデータ
unsigned char ucTemp[200];                      // 作業用ﾊﾞｯﾌｧ
#endif

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

        // //!  DM0 ~ DM19 書き込み
        // // DM0 ~ DM..
        // // PP1ｻｲｸﾙﾀｲﾑｱｳﾄ(4桁)
        // decToASCIIHex(tdat.g_tm.PP_T1, 4, ustemp);
        // pucDat = my_strcpy(pucDat, ustemp);

        // // PP出引動作ﾀｲﾑｱｳﾄ(4桁)
        // decToASCIIHex(tdat.g_tm.PP_T2, 4, ustemp);
        // pucDat = my_strcpy(pucDat, ustemp);

        // // PP開閉動作ﾀｲﾑｱｳﾄ(4桁)
        // decToASCIIHex(tdat.g_tm.PP_T3, 4, ustemp);
        // pucDat = my_strcpy(pucDat, ustemp);

        // // PP原点復帰動作ﾀｲﾑｱｳﾄ
        // decToASCIIHex(tdat.g_tm.PP_T4, 4, ustemp);
        // pucDat = my_strcpy(pucDat, ustemp);

        // // PP原点復帰offﾃﾞｨﾚｰﾀｲﾏ(開閉)
        // decToASCIIHex(tdat.g_tm.PP_T5, 4, ustemp);
        // pucDat = my_strcpy(pucDat, ustemp);

        // // PP原点復帰onﾃﾞｨﾚｰﾀｲﾏ(開閉)
        // decToASCIIHex(tdat.g_tm.PP_T6, 4, ustemp);
        // pucDat = my_strcpy(pucDat, ustemp);

        // // PP原点復帰offﾃﾞｨﾚｰﾀｲﾏ(伸縮)
        // decToASCIIHex(tdat.g_tm.PP_T7, 4, ustemp);
        // pucDat = my_strcpy(pucDat, ustemp);

        // // PP原点復帰onﾃﾞｨﾚｰﾀｲﾏ(伸縮)
        // decToASCIIHex(tdat.g_tm.PP_T8, 4, ustemp);
        // pucDat = my_strcpy(pucDat, ustemp);

        // // 予備
        // memset(ustemp,0x00,sizeof(ustemp));
        // decToASCIIHex(0, 4,ustemp);
        // pucDat = my_strcpy(pucDat, ustemp); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)

        // // 予備
        // memset(ustemp,0x00,sizeof(ustemp));
        // decToASCIIHex(0, 4, ustemp);
        // pucDat = my_strcpy(pucDat, ustemp); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)

        // // 微小開動作
        // decToASCIIHex(6666, 4, ustemp);
        // pucDat = my_strcpy(pucDat, ustemp);
        // // decToASCIIHex(tdat.g_fw.oPP, 4, ustemp);
        // // pucDat = my_strcpy(pucDat, ustemp);

        // // 予備
        // memset(ustemp,0x00,sizeof(ustemp));
        // decToASCIIHex(0, 4, ustemp);
        // pucDat = my_strcpy(pucDat, ustemp); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)
        // // 予備
        // memset(ustemp,0x00,sizeof(ustemp));
        // decToASCIIHex(0, 4, ustemp);
        // pucDat = my_strcpy(pucDat, ustemp); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)
        // // 予備
        // memset(ustemp,0x00,sizeof(ustemp));
        // decToASCIIHex(0, 4, ustemp);
        // pucDat = my_strcpy(pucDat, ustemp); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)
        // // 予備
        // memset(ustemp,0x00,sizeof(ustemp));
        // decToASCIIHex(0, 4, ustemp);
        // pucDat = my_strcpy(pucDat, ustemp); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)
        // // 予備
        // memset(ustemp,0x00,sizeof(ustemp));
        // decToASCIIHex(0, 4, ustemp);
        // pucDat = my_strcpy(pucDat, ustemp); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)
        // // 予備
        // memset(ustemp,0x00,sizeof(ustemp));
        // decToASCIIHex(0, 4, ustemp);
        // pucDat = my_strcpy(pucDat, ustemp); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)
        // // 予備
        // memset(ustemp,0x00,sizeof(ustemp));
        // decToASCIIHex(0, 4, ustemp);
        // pucDat = my_strcpy(pucDat, ustemp); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)
        // // 予備
        // memset(ustemp,0x00,sizeof(ustemp));
        // decToASCIIHex(0, 4, ustemp);
        // pucDat = my_strcpy(pucDat, ustemp); // 予備 (4byte分ｲﾝｸﾘﾒﾝﾄ)
        // break;
    }
    }
}

// FINS　書込通信
static void FINS_CommString( TE_FINSDIRE en_dire, const unsigned char* pcuc_MemType, const unsigned char* pucAdd, unsigned char ucSz, unsigned char* pcFINS_DatSection)
{
    unsigned char* pcur = ucTemp;
    char cFcs;
    unsigned char* pfciIdx;     // FCI導出時にFOR文で使用する
    unsigned char ucbuf[5];     //作業用ﾊﾞｯﾌｧ
    
    memset( ucTemp, 0x00, sizeof( ucTemp));


    //! 通信HEADER生成 
    pcur = my_strcpy(ucTemp, (unsigned char*)FINS_HEADER);

    //! 通信方向
    pcur =  (en_dire ==en_FINSDIRE_WRITE) ? my_strcpy(pcur,(unsigned char*)FINS_CMDTYPE_WRITE) :my_strcpy(pcur,(unsigned char*)FINS_CMDTYPE_READ);

 	//! memory type
    pcur =  my_strcpy(pcur,pcuc_MemType);

 	//! ｱﾄﾞﾚｽｾｯﾄ
    pcur =  my_strcpy(pcur,pucAdd);

    //! 固定文字 0x0000 (2桁)
    pcur = my_strcpy(pcur, (unsigned char *)"00");

 	//! ｻｲｽﾞ (4桁)
     memset( ucbuf, NULL,sizeof(ucbuf)); 
    pcur =my_strcpy( pcur, decToASCIIHex(ucSz, 4));

 	//! ﾃﾞｰﾀ部
     pcur = my_strcpy(pcur, pcFINS_DatSection);

 	//! FCI
  	cFcs = 0;								
	for( pfciIdx =ucTemp; *pfciIdx !=NULL;){
		cFcs ^= *pfciIdx++;
	}
    pcur = my_strcpy(pcur, decToASCIIHex(cFcs, 2));

 	//! 終端ｺｰﾄﾞ 
     *pcur = '*'; 
     *pcur++;
     *pcur = 0x0d;  // CR
     *pcur++;
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

    FINS_CommString(FINS_INF[en_FINSCMD_DM0].te_direction, FINS_INF[en_FINSCMD_DM0].uc_MemType, FINS_INF[en_FINSCMD_DM0].uc_Addr, FINS_INF[en_FINSCMD_DM0].uc_Sz, ucBuff);
    return 0;
}

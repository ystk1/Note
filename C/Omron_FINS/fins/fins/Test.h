
//各種タイマー値
typedef struct _timer
{
    //		unsigned char		Swait;				// 予備

    unsigned short nFrkStop;    // ﾌｫｰｸ中央停止ｵﾌﾃﾞｨﾚｰ
    unsigned short nLvl_Chk_Up; // 上ﾚﾍﾞﾙ動作時定位置確認ﾀｲﾏｰ
    unsigned short nLvl_Chk_Dw; // 下ﾚﾍﾞﾙ動作時定位置確認ﾀｲﾏｰ

    //		unsigned short				yobi0;				// 予備 <61136>
    unsigned short PP_T1; // PP1サイクルタイムアウト <61136>

    unsigned short lvl_l;      // フォーク出制限タイマー（棚）
    unsigned short nBay_Tech1; // 走行自動ﾃｨｰﾁﾝｸﾞ端柱検出後停止ﾃﾞｨﾚｰ
                               //		unsigned short				Br_Off;				// ブレーキOFFタイマー（未使用） <61136>
    unsigned short PP_T2;      // PP出引動作タイムアウト <61136>
    unsigned short rool;       // 揺れ止め

    unsigned short cl_pa;     // 荷はみ出し異常
    unsigned short cw_pa;     // 荷姿異常確認
    unsigned short nBay_Wait; // 走行定位置確認ﾀｲﾏｰ
    unsigned short nLvl_Wait; // 昇降定位置確認ﾀｲﾏｰ
    unsigned short nFrk_Wait; // ﾌｫｰｸ定位置確認ﾀｲﾏｰ
    unsigned short nBay_Tech; // 走行自動ﾃｨｰﾁﾝｸﾞ反転時待ち時間

    unsigned short nBay_T_On;  // 走行Pset  ONﾃﾞｨﾚｰ
    unsigned short nBay_T_Off; //          OFFﾃﾞｨﾚｰ
    unsigned short nLvl_T_On;  // 昇降Pset  ONﾃﾞｨﾚｰ
    unsigned short nLvl_T_Off; //          OFFﾃﾞｨﾚｰ
    unsigned short nFrk_T_On;  // ﾌｫｰｸPset  ONﾃﾞｨﾚｰ
    unsigned short nFrk_T_Off; //          OFFﾃﾞｨﾚｰ

    unsigned short nLvl_H_Check; // 昇降ﾚﾍﾞﾙ動作方向監視開始

    unsigned short over[3]; // オーバータイム・チェツク

    unsigned short lvl_ls; // フォーク出制限タイマー（ＳＴ）
    unsigned short Bz_On;  // ブザーオンタイム

    unsigned short nT_Bay_SON_Off; // S-ON OFFタイマ
    unsigned short nT_Lvl_SON_Off; // S-ON OFFタイマ
    unsigned short nT_Frk_SON_Off; // S-ON OFFタイマ

    unsigned short nSt_Ovt1; // STｵｰﾊﾞﾀｲﾑ(予約・実行)
    unsigned short nSt_Ovt2; // STｵｰﾊﾞﾀｲﾑ(荷積・荷降)
    unsigned short nLvl_Son; // S-ONﾃﾞｨﾚｰ

    unsigned short Bz_On_Wait; // 初回動作待ちﾌﾞｻﾞｰON時間
    unsigned short overEco[3]; // オーバータイム(省ｴﾈ専用)
                               //		unsigned short				nFrk_Org[2];		// ﾌｫｰｸ原点復帰用ﾀｲﾏｰ
    unsigned short PP_T3;      // PP開閉動作タイムアウト <61136>
    unsigned short PP_T4;      // PP原点復帰動作タイムアウト <61136>

    //		unsigned short				yobi[4];			// 予備 <61136>
    unsigned short PP_T5; // PP原点復帰offディレータイマー(開閉) <61136>
    unsigned short PP_T6; // PP原点復帰onディレータイマー(開閉) <61136>
    unsigned short PP_T7; // PP原点復帰offディレータイマー(伸縮) <61136>
    unsigned short PP_T8; // PP原点復帰onディレータイマー(伸縮) <61136>
};

// 各種タイマー値
typedef struct _timer_P1
{
    //		unsigned char		Swait;				// 予備

    unsigned short nFrkStop;    // ﾌｫｰｸ中央停止ｵﾌﾃﾞｨﾚｰ
    unsigned short nLvl_Chk_Up; // 上ﾚﾍﾞﾙ動作時定位置確認ﾀｲﾏｰ
    unsigned short nLvl_Chk_Dw; // 下ﾚﾍﾞﾙ動作時定位置確認ﾀｲﾏｰ

    //		unsigned short		yobi0;				// 予備 <61136>
    unsigned short PP_T1; // PP1サイクルタイムアウト <61136>

    unsigned short lvl_l;      // フォーク出制限タイマー（棚）
    unsigned short nBay_Tech1; // 走行自動ﾃｨｰﾁﾝｸﾞ端柱検出後停止ﾃﾞｨﾚｰ
                               //		unsigned short		Br_Off;				// ブレーキOFFタイマー（未使用） <61136>
    unsigned short PP_T2;      // PP出引動作タイムアウト <61136>
    unsigned short rool;       // 揺れ止め

    unsigned short cl_pa; // 荷はみ出し異常
    unsigned short cw_pa; // 荷姿異常確認

    unsigned short nBay_Wait; // 走行定位置確認ﾀｲﾏｰ
    unsigned short nLvl_Wait; // 昇降定位置確認ﾀｲﾏｰ
    unsigned short nFrk_Wait; // ﾌｫｰｸ定位置確認ﾀｲﾏｰ
    unsigned short nBay_Tech; // 走行自動ﾃｨｰﾁﾝｸﾞ反転時待ち時間

    unsigned short nBay_T_On;  // 走行Pset  ONﾃﾞｨﾚｰ
    unsigned short nBay_T_Off; //          OFFﾃﾞｨﾚｰ
    unsigned short nLvl_T_On;  // 昇降Pset  ONﾃﾞｨﾚｰ
    unsigned short nLvl_T_Off; //          OFFﾃﾞｨﾚｰ
    unsigned short nFrk_T_On;  // ﾌｫｰｸPset  ONﾃﾞｨﾚｰ
    unsigned short nFrk_T_Off; //          OFFﾃﾞｨﾚｰ

    unsigned short nLvl_H_Check; // 昇降ﾚﾍﾞﾙ動作方向監視開始

    unsigned short over[3]; // オーバータイム・チェツク

    unsigned short lvl_ls; // フォーク出制限タイマー（ＳＴ）
    unsigned short Bz_On;  // ブザーオンタイム

    unsigned short nT_Bay_SON_Off; // S-ON OFFタイマ
    unsigned short nT_Lvl_SON_Off; // S-ON OFFタイマ
    unsigned short nT_Frk_SON_Off; // S-ON OFFタイマ

    unsigned short nSt_Ovt1; // STｵｰﾊﾞﾀｲﾑ(予約・実行)
    unsigned short nSt_Ovt2; // STｵｰﾊﾞﾀｲﾑ(荷積・荷降)
    unsigned short nLvl_Son; // S-ONﾃﾞｨﾚｰ

    unsigned short Bz_On_Wait; // 初回動作待ちﾌﾞｻﾞｰON時間
    unsigned short overEco[3]; // オーバータイム(省ｴﾈ専用)
                               //		unsigned short		nFrk_Org[2];		// ﾌｫｰｸ原点復帰用ﾀｲﾏｰ
    unsigned short PP_T3;      // PP開閉動作タイムアウト <61136>
    unsigned short PP_T4;      // PP原点復帰動作タイムアウト <61136>

    //		unsigned short		yobi[4];			// 予備 <61136>
    unsigned short PP_T5; // PP原点復帰offディレータイマー(開閉) <61136>
    unsigned short PP_T6; // PP原点復帰onディレータイマー(開閉) <61136>
    unsigned short PP_T7; // PP原点復帰offディレータイマー(伸縮) <61136>
    unsigned short PP_T8; // PP原点復帰onディレータイマー(伸縮) <61136>
};

//*************************************************************************************************
//　SH2-CD2用の実際にﾌﾟﾛｸﾞﾗﾑで使用するﾃｨｰﾁﾝｸﾞﾃﾞｰﾀ構造体
//  ※EMAKEで"extern"を付けさせない為、構造体内の変数定義には、先頭にｽﾍﾟｰｽ or TABを入れる
//*************************************************************************************************
typedef struct TDATA_SH // SH2内で使用する為に、偶数境界で定義
                        // 各ﾃｰﾌﾞﾙは固定長で領域確保して、可変長を止める
                        // 各ﾃｰﾌﾞﾙ数MAXは、MD4.Hで定義
{
    // //*************************************************************************************************

    // //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // //		各種テーブル
    // //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // //************************************************
    // // SH2ﾎﾟｲﾝﾀは、int(4ﾊﾞｲﾄ)となる
    // //************************************************
    // unsigned char *g_end_add;     // 規定値エンドアドレス
    // short g_Ramrom;               // 予備
    // unsigned char *g_pKasoBayAdr; // 仮想連テーブル
    // unsigned char g_cKasoBayCnt;
    // unsigned char *g_pKasoLvlAdr; // 仮想段テーブル
    // unsigned char g_pKasoLvlCnt;
    // struct TBL_NISUGATA *g_pNisugataAdr; // 特殊荷検出用テーブル
    // unsigned char g_cNisugataCnt;
    // struct TBL_TOKUSYU *g_pTokuTanaAdr; // 特殊棚テーブル
    // unsigned char g_cTokuTanaCnt;
    // long *g_pBayStopAdr; // 走行停止位置
    // unsigned char g_cBayStopCnt;
    // long *g_pLvlStopAdr; // 昇降停止位置
    // unsigned char g_cLvlStopCnt;
    // struct HOSEI_DATA *g_pBayHoseiAdr; // 走行補正
    // short g_nBayHoseiCnt;
    // struct HOSEI_DATA *g_pLvlHoseiAdr; // 昇降補正
    // unsigned char g_cLvlHoseiCnt;
    // unsigned char *g_pTechLvlAdr; // ティーチング段
    // unsigned char g_cTechLvlCnt;
    // struct TECH_DATA *g_pTechCalAdr; // ティーチング演算指示テーブル
    // unsigned char g_cTechtCalCnt;
    // struct TECH_KINSHI_AREA *g_pTechKinAreaAdr; // ティーチング禁止区域
    // unsigned char g_cTechtKinAreaCnt;

    // long g_lTableYobi[5]; // 予備エリア（テーブル定義追加用）

    // //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // //			固定領域
    // //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

     struct _timer g_tm;   // 各種タイマー値
    // long g_lTimerYobi[5]; // 予備エリア

    // // 各種規定値
    // unsigned char g_cTanFlg; // 		端異常無視ﾌﾗｸﾞ
    //                          // 		bit0:走行 bit1:昇降
    // unsigned char g_Cropt;   // 		クレーン・オプション
    // unsigned char g_yobi[2]; // 		予備
    // struct RACK_LAYOUT g_Rack_Tbl;     // ラックレイアウト
    // struct _org g_org;                 // 各種各原点値
    // struct _l_lv g_lv;                 // 棚上下レベル
    // struct _frk_w g_fw;                // フォークストローク
    // struct _frk_h g_FrkHosei;          // フォーク補正データ（未使用）
    // struct _ok g_Ok;                   // 許容停止誤差
    // struct _TenkenD g_TenkenD;         // 点検動作時余裕距離
    // struct _CountD g_CountD;           // ｶｳﾝﾄ余裕距離
    // struct BAY_INV_Data g_Bay_Inv_Dat; // 走行INVﾃﾞｰﾀ
    // struct LVL_INV_Data g_Lvl_Inv_Dat; // 昇降INVﾃﾞｰﾀ
    // struct FRK_INV_Data g_Frk_Inv_Dat; // ﾌｫｰｸINVﾃﾞｰﾀ
    // struct Kg_Dat g_Bay_Kg_Dat;        // 走行強制減速ﾃﾞｰﾀ
    // struct Kg_Dat g_Lvl_Kg_Dat;        // 昇降強制減速ﾃﾞｰﾀ
    // struct Oikomi_Dat g_Oikomi;        // 定位置追い込みﾃﾞｰﾀ
    // struct _AUTOTECH g_AutoTech;       // 自動ﾃｨｰﾁﾝｸﾞﾊﾟﾗﾒｰﾀ
    // struct _SOFTLIMIT g_SoftLimit;     // ｿﾌﾄﾘﾐｯﾄ設定
    //long g_lYobi[20]; // 予備ｴﾘｱ

    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //			可変領域（領域確保用として最大数での定義を行う）
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    // unsigned char g_Ks_Bay_dumy[TABLE_KASO_BAY_MAX];                 // 仮想連ﾃｰﾌﾞﾙ
    // unsigned char g_Ks_Lvl_dumy[TABLE_KASO_LVL_MAX];                 // 仮想段ﾃｰﾌﾞﾙ
    // struct TBL_NISUGATA g_cag_tbl_d[TABLE_CAG_MAX];                  // 特殊荷検出ﾃｰﾌﾞﾙ
    // struct TBL_TOKUSYU g_st_dumy[TABLE_TOKUSYU_MAX];                 // 特殊棚ﾃｰﾌﾞﾙ
    // long g_b_dumy[TABLE_BAY_MAX];                                    // 走行停止位置
    // long g_l_dumy[TABLE_LVL_MAX];                                    // 昇降停止位置
    // unsigned char g_tlvl_dumy[TABLE_LVL_TECH_MAX];                   // ﾃｨｰﾁﾝｸﾞ段ﾃｰﾌﾞﾙ
    // struct TECH_DATA g_td_dumy[TABLE_TECH_CAL_MAX];                  // ﾃｨｰﾁﾝｸﾞ演算指示ﾃｰﾌﾞﾙ
    // struct TECH_KINSHI_AREA g_tk_dumy[TABLE_KIN_AREA_MAX];           // ﾃｨｰﾁﾝｸﾞ禁止区域
    // struct HOSEI_DATA g_bh_dumy[TABLE_BAY_MAX * TABLE_LVL_TECH_MAX]; // 走行補正
    // struct HOSEI_DATA g_lh_dumy[TABLE_BAY_MAX];                      // 昇降補正

    // struct TBL_TOKUSYU g_st_dumy2[500]; // 予備として特殊棚ﾃｰﾌﾞﾙ500個分の領域を確保

    // unsigned short g_DUMMY[94]; // データサイズ調整用
    // unsigned char g_end;        // データ・エンドフラグ

    //*************************************************************************************************
};
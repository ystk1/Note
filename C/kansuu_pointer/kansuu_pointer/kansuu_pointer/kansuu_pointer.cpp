// kansuu_pointer.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <stdio.h>

//#include <iostream>
//! 通信ﾌｪｰｽﾞ
typedef enum
{
    en_SCH3PHASE_INIT = 0,        // SCI CH3 通信初期起動
    en_SCH3PHASE_RESET_EXE_CMD,   // 実行するｺﾏﾝﾄﾞをｾｯﾄ
    en_SCH3PAHSE_CREATE_SENDDAT,  // 送信ﾃﾞｰﾀ生成
    en_SCH3PHASE_SEND,            // 送信処理
    en_SCH3PHASE_WAIT_SENDCOMP,   //送信完了処理
    en_SCH3PHASE_RECV,            // 受信処理
    en_SCH3PHASE_WAIT_RECVCOMP,   // 受信ﾃﾞｰﾀ受信完了
    en_SCH3PHASE_PARSER_RECV_DAT, // 受信ﾃﾞｰﾀ解析
    en_SCH3PHASE_NUM
} EN_SCH3PHASE_STEP;

static EN_SCH3PHASE_STEP en_ComPhaseCur; //!通信ﾌｪｰｽﾞ ｽﾃｰﾀｽ

static const void ComPhaseInit(void);
static const void ComPhaseResetExeCmd(void);
static const void ComPhaseCreateSendDat(void);
static const void ComPhaseSend(void);
static const void ComPhaseWaitSendComp(void);
static const void ComPhaseRecv(void);
static const void ComPhaseWaitRecvComp(void);
static const void ComPhaseRecvDatParser(void);

static void UpDatePhaseStatus(EN_SCH3PHASE_STEP enCur) //! ｶﾚﾝﾄﾌｪｰｽﾞ をUpdate
{
    en_ComPhaseCur = enCur;
}
// static void UpDatePhaseStatus(EN_COM_STAT enStatus)
// {
// 	//	データステータス 初期化
// 	g_unDataStat.wField = 0;
// 	//	受信割込みステータス 初期化
// 	ComIntInitialize(en_COM_RECV);
// 	//	通信ステータス 更新
// 	g_enComStatus = enStatus;
// }


/**
* 通信STEP　関数ﾎﾟｲﾝﾀ
*
* @param[in] 
* @param[out] 
* @return 
*/
static const void (*const ComStatusTable[en_SCH3PHASE_NUM])(void) = {
    ComPhaseInit,          //
    ComPhaseResetExeCmd,   //
    ComPhaseCreateSendDat, //
    ComPhaseSend,          //
    ComPhaseWaitSendComp,  //
    ComPhaseRecv,          //
    ComPhaseWaitRecvComp,  //
    ComPhaseRecvDatParser  //
};

static const void ComPhaseInit(void)
{
    UpDatePhaseStatus(en_SCH3PHASE_RESET_EXE_CMD);
}
static const void ComPhaseResetExeCmd(void)
{
    UpDatePhaseStatus(en_SCH3PAHSE_CREATE_SENDDAT);
}
static const void ComPhaseCreateSendDat(void)
{
    UpDatePhaseStatus(en_SCH3PHASE_SEND);
}
static const void ComPhaseSend(void)
{
    UpDatePhaseStatus(en_SCH3PHASE_WAIT_SENDCOMP);
}
static const void ComPhaseWaitSendComp(void)
{
    UpDatePhaseStatus(en_SCH3PHASE_RECV);
}
static const void ComPhaseRecv(void)
{
    UpDatePhaseStatus(en_SCH3PHASE_WAIT_RECVCOMP);
}
static const void ComPhaseWaitRecvComp(void)
{
    UpDatePhaseStatus(en_SCH3PHASE_PARSER_RECV_DAT);
}
static const void ComPhaseRecvDatParser(void)
{
    UpDatePhaseStatus(en_SCH3PHASE_RESET_EXE_CMD);
}

/**
* 通信STEP制御 ｶﾚﾝﾄﾌｪｰｽﾞ実行
*
* @param[in] 
* @param[out] 
* @return 
*/
static const void ComControl(void)
{
	//	通信ステップ制御
	ComStatusTable[en_ComPhaseCur]();
}


int main()
{
   en_ComPhaseCur = en_SCH3PHASE_INIT;
   while(1){
   ComControl();
   }
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します

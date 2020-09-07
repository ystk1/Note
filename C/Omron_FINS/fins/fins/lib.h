//! 汎用返却値
typedef enum {
	en_RETURN_CODE_OK,								//!<OK
	en_RETURN_CODE_NG,								//!<NG

	en_RETURN_CODE_YES,								//!<YES
	en_RETURN_CODE_NO,								//!<NO

	en_RETURN_CODE_SUCCESS,							//!<成功
	en_RETURN_CODE_RUN,								//!<処理中
	en_RETURN_CODE_FAILURE,							//!<失敗
	en_RETURN_CODE_FINISH,							//!<終了

	en_RETURN_CODE_UPDATE,							//!<更新あり
	en_RETURN_CODE_KEEP,							//!<更新なし

	en_RETURN_CODE_BUS_BUSY,						//!<バス使用状態
	en_RETURN_CODE_BUS_FREE,						//!<バス開放状態

	en_RETURN_CODE_DETECT,							//!<検出

	en_RETURN_CODE_NON,								//!<エラー発生なし
	en_RETURN_CODE_ERROR,							//!<エラー発生中

	en_RETURN_CODE_BUSY,							//!<処理中
	en_RETURN_CODE_DONE,							//!<完了

	en_RETURN_CODE_DBG_ERR,							//!<デバッグエラー

	en_END_OF_RETURN_CODE

} EN_RETURN_CODE;


// EN_RETURN_CODE decToASCIIHex_s(unsigned short usVal, int iFig, unsigned char *ptar,unsigned char ucSz);
unsigned char* decToASCIIHex(unsigned short usVal, int iFig);
unsigned char *my_strcpy(unsigned char *dest, const unsigned char *src);
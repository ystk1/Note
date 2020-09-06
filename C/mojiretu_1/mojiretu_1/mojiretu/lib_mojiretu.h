// C_TEST.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

//! 10進⇒ASCIIに変換
int decToASCIIHex(unsigned short n, unsigned char ucFig, unsigned char *pchar);

//! 文字列結合(戻り値のunsigned char* はコピー先文字列の終端文字NULLを指し示す)
char *my_strcpy(char *dest, const char *src);

//! 文字列ﾎﾟｲﾝﾀに文字追加
void AddValASCII2USHORT(unsigned short usval, unsigned char ucFig,unsigned char* pchar);


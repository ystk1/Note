// C_TEST.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>

//! 10�i��ASCII�ɕϊ�
int decToASCIIHex(unsigned short n, unsigned char ucFig, unsigned char *pchar);

//! �����񌋍�(�߂�l��unsigned char* �̓R�s�[�敶����̏I�[����NULL���w������)
char *my_strcpy(char *dest, const char *src);

//! �������߲���ɕ����ǉ�
void AddValASCII2USHORT(unsigned short usval, unsigned char ucFig,unsigned char* pchar);


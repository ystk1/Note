// C_TEST.cpp : �R���\�[�� �A�v���P�[�V�����̃G���g�� �|�C���g���`���܂��B
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include "lib_mojiretu.h"


/**
* main�֐�
*
* @param[in] 
* @param[out] 
* @return 
*/
int _tmain(int argc, _TCHAR *argv[])
{
    unsigned char cbuf[64];
    memset(cbuf, 0x00, sizeof(cbuf));

//! 10�i��ASCII�ϊ� test 
    decToASCIIHex(45, 4, cbuf);

//! 10�i��ASCII�ϊ� test 
    decToASCIIHex(0xABCD, 4, cbuf);

    int itest = 0x12345;
    int ibuf;
    ibuf = itest >> 4;

    char cbuf1[20] = {};
    char cbuf2[6]  = {"TEST"};
    char cbuf3[4]  = {"123"};
    char *pcbuf1   = cbuf1;

    pcbuf1 = my_strcpy(cbuf1, cbuf2);
    pcbuf1 = my_strcpy(pcbuf1, cbuf3);
    return 0;
}

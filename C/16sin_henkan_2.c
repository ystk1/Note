#include <stdio.h>

int decToHexa(int Val, int iFig, char *pchar);

int main(void)
{
    char cbuf[64];
    memset(cbuf, 0x00, sizeof(cbuf));

    decToHexa(45, 2, cbuf);
}
// iFig 最大4桁
int decToHexa(int Val, int iFig, char *ptar)
{
    char hexaDeciNum[8]; // 最大8桁
    int iCnt = 0;

    memset(hexaDeciNum, 0x00, sizeof(hexaDeciNum));

    // counter for hexadecimal number array
    int i = 0;
    while (Val != 0) {
        // temporary variable to store remainder
        int temp = 0;

        // storing remainder in temp variable.
        temp = Val % 16;

        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + 0x30; // 0~
            i++;
        } else {
            hexaDeciNum[i] = temp + 0x37; // A~
            i++;
        }

        Val = Val / 16;
    }

    for (int j = 0; j < iFig; j++) {
        *(ptar + j) = (hexaDeciNum[(iFig - 1)-j] ==0x00) ? '0':hexaDeciNum[(iFig - 1)-j];
    }

	return 0;
}
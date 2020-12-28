#include <stdio.h>

char *decToHexa(int n, int iFig, char *pchar);

int main(void)
{
    char cbuf[64];
    memset(cbuf, 0x00, sizeof(cbuf));

    decToHexa(45, 2, cbuf);
}
// iFig 最大4桁
char *decToHexa(int n, int iFig, char *psrc)
{
    // char array to store hexadecimal number
    char hexaDeciNum[4]; // 最大4桁
    int iCnt = 0;

    memset(hexaDeciNum, 0x00, sizeof(hexaDeciNum));

    // counter for hexadecimal number array
    int i = 0;
    while (n != 0) {
        // temporary variable to store remainder
        int temp = 0;

        // storing remainder in temp variable.
        temp = n % 16;

        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + 0x30; // 0~
            i++;
        } else {
            hexaDeciNum[i] = temp + 0x37; // A~
            i++;
        }

        n = n / 16;
    }

    for (int j = 0; j < iFig; j++) {
        *(psrc + j) = hexaDeciNum[(iFig - 1)-j];
    }
}
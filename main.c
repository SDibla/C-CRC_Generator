#include <stdio.h>
#include "crc_lib.h"

int main()
{
    // ************* TEST *************
    char data[4] = {0xE1,0x00,0xCA,0xFE};
    printf("CRC: 0x%02x\n", crc_generator(data, sizeof(data)));

    return 0;
}

#include "crc_lib.h"
#include <stdio.h>

// Currently set for CRC-5-USB

#define PLY 0x05                // Polynomial
#define CRC_DIM 5               // Dim of CRC
#define INIT 0x00               // Initial value

unsigned char crc_generator(const char message[], int len) {
    
    char data[len];
    char DoInvert;
    unsigned char Res = INIT;               // Initialization of the residual
    char last_bit_mask = 1<<(CRC_DIM-1);    // To take always the last bit of the residual seq.

    for (int j = 0; j < len; j++){
        data[j] = message[j];
        for (int i = 0; i < 8; i++) {

            DoInvert = (data[j] & 0x80)>>7 ^ (Res & last_bit_mask)>>(CRC_DIM-1);      // XOR is required?
            Res <<= 1;
            if(DoInvert == 1)               // Do the XOR (related to the polynomial) only in the case in which the actual bit of the message is 1
                Res ^= PLY;
            data[j] <<=1;                   // Next bit

        }
    }

    return (Res & (0xFF>>(8-CRC_DIM)));
}

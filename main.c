

#include <stdio.h>
#include "genetics.h"
# include <stdint.h>

int lfsr(int count);
int main(void) {
    //runTest();
    popTest();
}

int lfsr(int count)
    {
        count = (count%65536) ? (count%65536) : ((count%65536) + 1);
        uint16_t lfsr = 0xFEED;
        uint16_t bit;
        int counter = 0;
        do
        {
            bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
            lfsr =  (lfsr >> 1) | (bit << 15);
            counter++;
        } while (count != counter);
        return lfsr;
    }






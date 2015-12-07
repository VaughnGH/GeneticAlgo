//TODO : Make classes and methods less dependent on strings, more dependent on bit operations

#include "DataOperations.h"

unsigned char readBit(unsigned char byte, int position){
    return (byte <<= (position - 1)) >> 7;
}
void setBit(unsigned char *byte, int position, unsigned int value){
    //'slow but works' temp solution; FIXME
    unsigned char byteFrame[8];
    for (int i = 0; i<8; i++){
        byteFrame[i] = readBit(*byte, i);
    }
    byteFrame[position-1] = value;
    unsigned char newByte = 0;
    for (int i = 0; i<=8; i++){
        newByte += (2 << (7-position))*(byteFrame[i]);  //2^n * (1 or 0)
    }
    *byte = newByte;
}

string byteToString(unsigned char byte){
    string byteStr;
    for(int position = 1; position <= 8; position++){
        byteStr += to_string(readBit(byte, position));
    }
    return byteStr;
}
unsigned char stringToByte(string byteStr){
    unsigned char byte;
    for (int i = 0; i<8; i++){
        if (byteStr.at(i) == '1') {
            byte += 1 << (7-i);
        }
    }
    return byte;
}
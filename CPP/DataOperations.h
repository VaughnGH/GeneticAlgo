//
//  DataOperations.h
//  goofin
//
//  Created by Vaughn GH on 11/29/15.
//  Copyright (c) 2015 Vaughn. All rights reserved.
//

#ifndef __goofin__DataOperations__
#define __goofin__DataOperations__

#include <iostream>
using namespace std;


unsigned char readBit(unsigned char byte, int position);
void setBit(unsigned char *byte, int position, unsigned int value);
string byteToString(unsigned char byte);
unsigned char stringToByte(string byteStr);



#endif /* defined(__goofin__DataOperations__) */

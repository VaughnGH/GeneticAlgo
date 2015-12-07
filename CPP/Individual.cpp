//
//  Individual.cpp
//  goofin
//
//  Created by Vaughn GH on 11/29/15.
//  Copyright (c) 2015 Vaughn. All rights reserved.
//

#include "Individual.h"
#include "DataOperations.h"
Individual::Individual(string geneString){
    for (int i = 0; i < GENE_BYTE_SIZE; i++) {
        genes[i] = stringToByte(geneString.substr((i*8),8));
    }
}
Individual::Individual(unsigned char geneArray[]){
    //genes = geneArray;
    
}
string Individual::getGeneString(){
    string geneString;
    for (int byte = 1; byte <= GENE_BYTE_SIZE; byte++){
        geneString += byteToString(genes[byte-1]);
    }
    return geneString;
}
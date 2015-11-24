//
//  newGenetics.c
//  geneticAlgorithm
//
//  Created by Vaughn GH on 11/24/15.
//  Copyright (c) 2015 Vaughn. All rights reserved.
//

#include "newGenetics.h"


unsigned char readBit(unsigned char byte, int position){
    byte <<= (position - 1);
    return byte >> 7;
}
void setBit(unsigned char *byte, int position, unsigned int value){
//'slow but works' temp solution; FIXME
    unsigned char byteFrame[8];
    for (int i = 0; i<=8; i++){
        byteFrame[i] = readBit(*byte, i);
    }
    byteFrame[position-1] = value;
    unsigned char newByte = 0;
    for (int i = 0; i<=8; i++){
        newByte += (2 << (7-position))*(byteFrame[i]);  //2^n * (1 or 0)
    }
    *byte = newByte;
}
unsigned char readGene(NIndividual indiv, int geneLocation){
    unsigned char byte = (geneLocation-1)/8;  //sub one because geneIndex 1 -> byteIndex 0
    geneLocation = ((geneLocation-1)%8)+ 1;
    return readBit(indiv.genes[byte], geneLocation);
}
void setGene(NIndividual *indiv, int geneLocation, unsigned char value){
    unsigned char byte = (geneLocation-1)/8;
    geneLocation = ((geneLocation-1)%8)+ 1;
    setBit(&indiv->genes[byte], geneLocation, value);
}


const unsigned char NGOAL[GENE_SIZE] = {255, 255, 255, 255};

NIndividual generateNIndividual(){
    NIndividual indiv;
    for (int i = 0; i < (GENE_SIZE*8); i++) {
        unsigned char geneState = (RANDOM() > .5);
        setGene(&indiv, i, geneState);
    }
    return indiv;
}
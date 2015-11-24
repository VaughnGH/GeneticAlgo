//
//  newGenetics.h
//  geneticAlgorithm
//
//  Created by Vaughn GH on 11/24/15.
//  Copyright (c) 2015 Vaughn. All rights reserved.
//

#ifndef __geneticAlgorithm__newGenetics__
#define __geneticAlgorithm__newGenetics__

#include <stdio.h>

#include <stdlib.h>
#define MUTATION_RATE .015  //MutationRate * GeneSize == chance of mutation in individual
#define GENE_SIZE 4
#define UNIFORM_RATE .7
#define POPULATION_SIZE 8
#define RANDOM() ((double)rand() / (double)RAND_MAX)

unsigned char readBit(unsigned char byte, int position);
void setBit(unsigned char *byte, int position, unsigned int value);

struct newIndividual {
    unsigned char genes[GENE_SIZE];
    unsigned char fitness;
};
typedef struct newIndividual NIndividual;

unsigned char readGene(NIndividual indiv, int geneLocation);
void setGene(NIndividual *indiv, int geneLocation, unsigned char value);
NIndividual generateNIndividual();









#endif /* defined(__geneticAlgorithm__newGenetics__) */

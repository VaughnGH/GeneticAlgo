#ifndef __goofin__genetics__
#define __goofin__genetics__

//#include <stdio.h>
#include <iostream>
#include <math.h>

#include <stdlib.h>
#define MUTATION_RATE .015  //MutationRate * GeneSize == chance of mutation in OIndividual
#define GENE_SIZE 32
#define UNIFORM_RATE .7
#define POPULATION_SIZE 8
#define RANDOM() ((double)rand() / (double)RAND_MAX)

struct OIndividual {
    unsigned int genes[GENE_SIZE];
    double fitness;
};
typedef struct OIndividual OIndividual;


int setFitness(OIndividual *indiv);
int getFitness(OIndividual indiv);
OIndividual getFittest();

void mutate(OIndividual *indiv);
OIndividual crossover(OIndividual parentOne, OIndividual parentTwo);
OIndividual generateOIndividual();

void printGenes(OIndividual indiv);

void generatePopulation();
OIndividual tournamentSelection(int tournamentSize);
OIndividual microSelection(int tournamentSize);
void evolvePopulation();
void popTest();



void runTest();






#endif /* defined(__goofin__genetics__) */
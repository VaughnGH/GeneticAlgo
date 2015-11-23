#ifndef __geneticAlgorithm__genetics__
#define __geneticAlgorithm__genetics__

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MUTATION_RATE .015  //MutationRate * GeneSize == chance of mutation in individual
#define GENE_SIZE 32
#define UNIFORM_RATE .5
#define RANDOM() ((double)rand() / (double)RAND_MAX)

struct individual {
    unsigned int genes[GENE_SIZE];
    double fitness;
};
typedef struct individual Individual;


void mutate(Individual *indiv);
int getFitness(Individual *indiv);
Individual crossover(Individual parentOne, Individual parentTwo);
Individual generateIndividual();
void printGenes(Individual indiv);


void runTest();






#endif /* defined(__geneticAlgorithm__genetics__) */

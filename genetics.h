#ifndef __geneticAlgorithm__genetics__
#define __geneticAlgorithm__genetics__

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MUTATION_RATE .017  //MutationRate * GeneSize == chance of mutation in individual
#define GENE_SIZE 32
#define UNIFORM_RATE .8
#define POPULATION_SIZE 8
#define DEFAULT_RANDOM() ((double)rand() / (double)RAND_MAX)
#define RANDOM() ((double) c_lfsr() / (double) 65535)
#define ASSEMB_RANDOM() ((double) assembly_lfsr() / (double) 65535)


struct individual {
    unsigned int genes[GENE_SIZE];
    double fitness;
};
typedef struct individual Individual;


int setFitness(Individual *indiv);
int getFitness(Individual indiv);
Individual getFittest();

void mutate(Individual *indiv);
Individual crossover(Individual parentOne, Individual parentTwo);
Individual generateIndividual();

void printGenes(Individual indiv);

void generatePopulation();
Individual tournamentSelection(int tournamentSize);
Individual microSelection(int tournamentSize);
void evolvePopulation();
void popTest();

int c_lfsr();
int assembly_lfsr();

void runTest();






#endif /* defined(__geneticAlgorithm__genetics__) */

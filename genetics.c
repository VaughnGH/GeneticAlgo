#include "genetics.h"

extern unsigned char lfsr(unsigned char counter);  //import lfst.s file


int randomCounter = 0;

const unsigned int GOAL[GENE_SIZE] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};  //goal genome sequence
Individual population[POPULATION_SIZE];

void generatePopulation(){
    for (int i=0; i<POPULATION_SIZE; i++) {
        population[i] = generateIndividual();
    }
}

Individual generateIndividual(){
    Individual indiv;
    for (int i = 0; i < GENE_SIZE; i++) {
            indiv.genes[i] = round(RANDOM());
    }
    return indiv;
}

void mutate(Individual *indiv){  //chance of gene mutation based on MUTATION_RATE
    for (int i = 0; i < GENE_SIZE; i++) {
        if (RANDOM() <= MUTATION_RATE) {
            indiv->genes[i] = round(RANDOM());
        }
    }
}
Individual crossover(Individual parentOne, Individual parentTwo) {  //combine two parents into offspring
    Individual child;
    for (int i = 0; i < GENE_SIZE; i++) {
        child.genes[i] = (RANDOM() <= UNIFORM_RATE) ? parentOne.genes[i] : parentTwo.genes[i];
    }
    return child;
}
int setFitness(Individual *indiv) {  //Test indiv for fitness
    indiv->fitness = 0;
    for (int i = 0; i < GENE_SIZE; i++) {
        if (indiv->genes[i] == GOAL[i]) {
            indiv->fitness++;
        }
    }
    return indiv->fitness;
}
int getFitness(Individual indiv) {
    return setFitness(&indiv);
}
void printGenes(Individual indiv){
    for (int i = 0; i < GENE_SIZE; i++) {
        printf("%d", indiv.genes[i]);
    }
}

void evolvePopulation(){  //get new, fit, pool of individuals
    Individual fittest = getFittest();
    for (int i=0; i<POPULATION_SIZE; i++) {
        population[i] = crossover(fittest, microSelection(16));
        mutate(&population[i]);
    }
    
}

Individual getFittest() {
    Individual fittest = population[0];
    Individual newest;
    for (int i = 1; i<POPULATION_SIZE; i++) {
        newest = population[i];
        if (setFitness(&newest) >= setFitness(&fittest)) {
            fittest = newest;
        }
    }
    return fittest;
}


Individual tournamentSelection(int tournamentSize){  //deprecated
    return generateIndividual();
}


Individual microSelection(int tournamentSize){  //mini competetion pool of fittest, random, indiv's
    Individual fittest = generateIndividual();
    Individual newest;
    for (int i = 0; i<tournamentSize; i++) {
        newest = generateIndividual();
        if (setFitness(&newest) >= setFitness(&fittest)) {
            fittest = newest;
        }
    }
    return fittest;
}

void runTest(){
    /*for (int i = 0; i < GENE_SIZE; i++) {
     //const unsigned int GOAL[GENE_SIZE] = {1,1,0,0,1,0,1,0};
     printf("%d", GOAL[i]);
     }*/
    Individual indiv;
    for (int i = 0; i<100; i++) {
        indiv = generateIndividual();
        //if (getFitness(&indiv) == GENE_SIZE) {
        //    printf("%d", i);
        //    break;
        //}
        printf("Fitness: %d/%d -- Genes: ", setFitness(&indiv), GENE_SIZE);
        printGenes(indiv);
        printf("\n");
    }
}
void popTest(){
    generatePopulation();
    for (int evolution = 1; evolution <= 100; evolution++ ) {
        if (getFitness(getFittest()) == GENE_SIZE) {
            printf("~~~Genetic Success!~~~\n Evolution: %d \nFinal Gene Sequence: ", evolution);
            printGenes(getFittest());
            break;
        } else {
            printf("Evolution: %d , Max Fitness: %d, Genes: \n",
                   evolution, getFitness(getFittest())
                   );
            printGenes(getFittest());
            printf("\n");
            evolvePopulation();
        }
    }
}

/*
int assembly_lfsr(){  //Get assembly-lfsr rand val
    return lfsr(++randomCounter);
};*/

int c_lfsr() {  //Get c-lfsr rand val
    int count = ++randomCounter;
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

#include "genetics.h"

const unsigned int GOAL[GENE_SIZE] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
OIndividual population[POPULATION_SIZE];

void generatePopulation(){
    for (int i=0; i<POPULATION_SIZE; i++) {
        population[i] = generateOIndividual();
    }
}

OIndividual generateOIndividual(){
    OIndividual indiv;
    for (int i = 0; i < GENE_SIZE; i++) {
        indiv.genes[i] = round(RANDOM());
    }
    return indiv;
}

void mutate(OIndividual *indiv){
    for (int i = 0; i < GENE_SIZE; i++) {
        if (RANDOM() <= MUTATION_RATE) {
            indiv->genes[i] = round(RANDOM());
        }
    }
}
OIndividual crossover(OIndividual parentOne, OIndividual parentTwo) {
    OIndividual child;
    for (int i = 0; i < GENE_SIZE; i++) {
        child.genes[i] = (RANDOM() <= UNIFORM_RATE) ? parentOne.genes[i] : parentTwo.genes[i];
    }
    return child;
}
int setFitness(OIndividual *indiv) {
    indiv->fitness = 0;
    for (int i = 0; i < GENE_SIZE; i++) {
        if (indiv->genes[i] == GOAL[i]) {
            indiv->fitness++;
        }
    }
    return indiv->fitness;
}
int getFitness(OIndividual indiv) {
    return setFitness(&indiv);
}
void printGenes(OIndividual indiv){
    for (int i = 0; i < GENE_SIZE; i++) {
        printf("%d", indiv.genes[i]);
    }
}

void evolvePopulation(){
    OIndividual fittest = getFittest();
    for (int i=0; i<POPULATION_SIZE; i++) {
        population[i] = crossover(fittest, microSelection(16));
        mutate(&population[i]);
    }
    
}

OIndividual getFittest() {
    OIndividual fittest = population[0];
    OIndividual newest;
    for (int i = 1; i<POPULATION_SIZE; i++) {
        newest = population[i];
        if (setFitness(&newest) >= setFitness(&fittest)) {
            fittest = newest;
        }
    }
    return fittest;
}


OIndividual tournamentSelection(int tournamentSize){
    return generateOIndividual();
}


OIndividual microSelection(int tournamentSize){
    OIndividual fittest = generateOIndividual();
    OIndividual newest;
    for (int i = 0; i<tournamentSize; i++) {
        newest = generateOIndividual();
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
    OIndividual indiv;
    for (int i = 0; i<100; i++) {
        indiv = generateOIndividual();
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
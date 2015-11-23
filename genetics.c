#include "genetics.h"

const unsigned int GOAL[GENE_SIZE] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
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

void mutate(Individual *indiv){
    for (int i = 0; i < GENE_SIZE; i++) {
        if (RANDOM() <= MUTATION_RATE) {
            indiv->genes[i] = round(RANDOM());
        }
    }
}
Individual crossover(Individual parentOne, Individual parentTwo) {
    Individual child;
    for (int i = 0; i < GENE_SIZE; i++) {
        child.genes[i] = (RANDOM() <= UNIFORM_RATE) ? parentOne.genes[i] : parentTwo.genes[i];
    }
    return child;
}
int setFitness(Individual *indiv) {
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

void evolvePopulation(){
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


Individual tournamentSelection(int tournamentSize){
    return generateIndividual();
}


Individual microSelection(int tournamentSize){
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
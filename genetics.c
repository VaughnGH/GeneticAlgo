#include "genetics.h"

const unsigned int GOAL[GENE_SIZE] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
Individual population[100];

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
int getFitness(Individual *indiv) {
    int maxFitness = GENE_SIZE;
    indiv->fitness = 0;
    for (int i = 0; i < GENE_SIZE; i++) {
        if (indiv->genes[i] == GOAL[i]) {
            indiv->fitness++;
        }
        if (indiv->fitness == maxFitness){
            printf("\nWe have a winner!\n");
        }
    }
    return indiv->fitness;
}
void printGenes(Individual indiv){
    for (int i = 0; i < GENE_SIZE; i++) {
        printf("%d", indiv.genes[i]);
    }
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
        printf("Fitness: %d/%d -- Genes: ", getFitness(&indiv), GENE_SIZE);
        printGenes(indiv);
        printf("\n");
    }
    
}
//TODO: Make the class capable of having a runtime-decided (or dynamic) gene size, to facilitate genetic corpus growth

#ifndef __goofin__Individual__
#define __goofin__Individual__

#include <iostream>
using namespace std;
class Individual{
    //perhaps make the mutation rate mutable, having it decrease over time, depending on the generation (add a generation trait to class or just uniform decrease with each creation?)
    static const int GENE_BYTE_SIZE = 4;
 private:
    unsigned char genes[GENE_BYTE_SIZE];
    int fitness;
 public:
    Individual(string geneString);
    Individual(unsigned char geneArray[]);
    void setFitness();
    void getFitness();
    string getGeneString();
    
};





#endif /* defined(__goofin__Individual__) */

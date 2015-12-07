// byte organization [1,2,3,4,5,6,7,8] -> 1-index'd because having sequential bytes
//with 1-index counting allows intuitive access of a specific gene #
// e.g [1..8][9..16][17..24] => etc.

#include <iostream>
#include <math.h>
#include "DataOperations.h"
#include "Individual.h"
#include "genetics.h"
using namespace std;
void newTest();
void oldTest();
int main(int argc, const char * argv[]) {
    //oldTest();
    newTest();
}

void oldTest(){
    for (int i = 0; i<100000; i++){
        OIndividual alice = generateOIndividual();
        printGenes(alice);
        cout << endl;
    }
    cout << "Done" << endl;
}

void newTest(){
    /*unsigned char test = 170;
    for (int i=1; i<=8; i++){
        printf("%d",readBit(test, i));
    }
    cout<<endl;
    cout << byteToString(test) << endl;
    printf("%d\n", stringToByte("11111111"));*/
    for (int i = 0; i<100000; i++){
        Individual steve = Individual("11111111000000001111111100000001");
        cout << steve.getGeneString() << endl;
    }
    //cout << byteToString(85) << endl;
    /*cout << hex << 255 << endl;
     string testing = (hex) 255;*/
    
    
    cout << "Done" << endl;
    
}
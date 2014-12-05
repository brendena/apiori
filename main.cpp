#include "source/header.h"

using namespace std;
/*
Memory problem with Linked list
*/
int main()
{
    float percentage[6] = {0.25f, 0.5f, 1.0f, 10.0f, 25.0f, 30.0f};
    int percentageNum = 5;
    
    
    cout << "program started \n\n";
    
    Apriori<int> test;
    test.setCountTransactions(4);// probably should make a constructor for all this data.
    test.fillStartingData("testdata.txt");  
    test.setFrequencyThreshold(percentage[percentageNum]);
    test.cFirstCandList();
    
    test.firstPrune();
    //test.displayEverthing();
    test.print();
    
    test.makeSets();
    test.displayEverthing();
    //after her we can start looping throught he possibilities
    cout << "\n\nprogram ended fixed \n\n";
    
    // to solve error
    // http://stackoverflow.com/questions/2902064/how-to-track-down-a-double-free-or-corruption-error-in-c-with-gdb 
    return 0;
}

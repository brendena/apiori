#include "source/header.h"

using namespace std;
/*
Memory problem with Linked list
*/
int main()
{
    float precentage[6] = {0.25, 0.5, 1.0, 10.0, 25.0, 30.0};
    int percentageNum = 5;
    
    
    cout << "program started \n\n";
    
    Apriori<int> test;
    test.setCountTransactions(4);// probably should make a constructor for all this data.
    test.fillStartingData("testdata.txt");  
    //test.setFrequencyThreshold(precentage[percentageNum]);
    //test.cFirstCandList();
    
    //test.firstPrune();
    //test.displayEverthing();
    //test.print();
    
    //test.makeSets();
    //test.displayEverthing();
    //after her we can start looping throught he possibilities
    //cout << "\n\nprogram ended fixed \n\n";
    return 0;
}

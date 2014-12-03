#include "source/header.h"

using namespace std;

int main()
{
    float precentage = {0.25, 0.5, 1.0, 10.0, 25.0, 30.0};
    float percentageNum = 5;
    
    
    cout << "program started \n\n";
    
    Apriori<int> test;
    test.fillStartingData("testdata.txt");  
    test.setFrequencyThreshold(precentage[percentageNum])

    test.cFirstCandList();
    test.displayEverthing();
    cout << "\n\nprogram ended fixed \n\n";
    return 0;
}
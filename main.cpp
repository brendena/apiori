#include "source/header.h"

using namespace std;

int main()
{
    cout << "program started \n\n";
    
    Apriori<int> test;
    test.fillStartingData("testdata.txt");
    //test.cFirstCandList();
    test.displayEverthing();
    cout << "\n\nprogram ended  fixed \n\n";
    return 0;
}
/*
Error log

So currently there a problem with getDataFileCount it doens't get the last line of data.  It someithng with testing for the -1 part

*/

#ifndef APRIORI
#define APRIORI

#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"

#define blankSpace 32
#define newLine 10

using namespace std;

template <typename T>
class Apriori
{
    private:
        LinkedList<T> startingData;
		LinkedList<T> oldList;
		LinkedList<T> newList;
        int getDataFileCount(ifstream& inputFile);
    public:
        //void findMinFrequ();
        void cFirstCandList(); //create first candidate list

        void fillStartingData(string file);
        void displayEverthing();
		Apriori();
};
template <typename T>
Apriori<T>::Apriori()
{

}

template <typename T>
void Apriori<T>::fillStartingData(string file)
{
    ifstream inputFile;
    inputFile.open("testdata.txt");
    int hello;
    int startingPosition;
    do
    {

        startingPosition = inputFile.tellg(); //tellg get the position of the file input

        hello = getDataFileCount(inputFile);
        cout << hello << "\n";
		if(hello == -1){
    		cout << "hello \n";
    		break;
		}
		else{
		  inputFile.seekg(startingPosition,inputFile.beg);
		  startingData.createArray(hello);
		  string input;
		  for(int i = 0; i <= hello; i++){
			inputFile >> input;
			cout << endl << input << " " << i << "  \n";
			startingData.setArrayData(i,stoi(input));
			inputFile.get(); // get the black space and new line characters
		  }
		}//end of else statment
	
    }while(hello != -1 && !inputFile.eof());

    inputFile.close();
}

/*
pre:
post: return the number of items per line
1 item = return of 0
purpose: is to get the total amount of items so we can make a static array
 */
template <typename T>
int Apriori<T>::getDataFileCount(ifstream& inputFile)
{
    int count;
    char check = 0;
    string junk;
    if(inputFile.eof())
    {
        count = -1;
    }
    else
    {
        for(count = 0 ;check != newLine && !inputFile.eof();)
        {
            inputFile >> junk;
            check = inputFile.get();
            if(check == blankSpace)
            {
                count++;
            }
			if((int)check == -1){
			  count = -1;
			  break;
			}
        }
    }
    return count;
}



/*
void Apriori::findMinFrequ()
{
    
    
}
*/
template <typename T>
void Apriori<T>::cFirstCandList()
{
    
    startingData.clearIterator();
    do{
        T* data = startingData.getIteratorValue();
        for(int i = 0; i < startingData.getIteratorSize()+ 1; i++)
        {
            if(!startingData.search(data[i])) //not found
            {
                Node<T>* newNode = new Node<T>(0, data[0]);
                startingData.appendToTheEnd(newNode);
            }
        }
    }while(startingData++);
}
template <typename T>
void Apriori<T>::displayEverthing()
{
    startingData.display();
}

#endif
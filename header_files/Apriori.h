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
        
        int mFrequencyThreshold;  //s on the paper
        int mCountTransactions;
        
        //makes new item sets
        void makeSets();
        Node<T>* makeNewNode(Node<T>* temp1, Node<T>* temp2);
        bool isSame(Node<T>* temp1, Node<T>* temp2);
    public:
        //void findMinFrequ();
        void cFirstCandList(); //create first candidate list
        void fillStartingData(string file);
        void displayEverthing();
        
        void setFrequencyThreshold(float percentage);
        void setCountTransactions(int count);
        void prune();
		Apriori();
		Apriori(int frequencyThreshold);
};
template <typename T>
Apriori<T>::Apriori()
{
    mFrequencyThreshold = 5;
}

template <typename T>
Apriori<T>::Apriori(int frequencyThreshold)
{
    mFrequencyThreshold = frequencyThreshold;
}


template <typename T>
void Apriori<T>::fillStartingData(string file)
{
    ifstream inputFile;
    inputFile.open("testdata.txt");
    int hello;
    int startingPosition;
    
        /*
        http://mathbits.com/MathBits/CompSci/APstrings/APgetline.htm/
        
        good website to figure out getline  cin >> asdfasdf*/
    /*
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
	    
    }while()(hello != -1 && !inputFile.eof());
    */
    getDataFileCount(inputFile);
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
    
    
    
    
    
    /*
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
    */
    else
    {
        getline(inputFile, junk);
        for(count = 0; count < 5; count++)
        {
            cout << junk[count] << endl;
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
        //cout << startingData.getIteratorSize() << endl << endl;
        for(int i = 0; i < startingData.getIteratorSize() + 1; i++)
        {
            cout << !startingData.search(1231) << "if its found \n";
            if(!newList.search(data[i])) //not found
            {
                Node<T>* newNode = new Node<T>(0, data[i]);
                newList.appendToTheEnd(newNode);
            }
        }
    }while(startingData++);
}
template <typename T>
void Apriori<T>::displayEverthing()
{
    startingData.display();
    //oldList.display();
    //newList.display();
}



//adds new nodes to new list
/*
doesn't check for doob's but i don't think it needs to
*/
template <class T>
void Apriori<T>::makeSets() //uses the new and old linked list
{
    //copy newList to oldLink to free up newList for the new sets with overloaded operator
    oldList = newList;
    //clear newList
    newList.clear();
    
    int setCount;
    int nodeCount = 0;
    Node<T>* temp1 = oldList.getHead();;
    Node<T>* temp2 = temp1->mNext;
    Node<T>* newListTemp = newList.getHead();
   
   //sets starting node and proceeding node to start traversal
   while(temp2->mNext != NULL)
   {
        setCount = nodeCount;
        //compares one node with all other nodes
        while(setCount != oldList.getCount())
        {
            if(isSame(temp1, temp2))  //check to see if compatible
            {
                if(newList.getHead() == NULL)
                    newList.getHead() = makeNewNode(temp1, temp2);
                else
                {
                    newListTemp = newListTemp->mNext;
                    newListTemp = makeNewNode(temp1, temp2);
                }
            }
            setCount++;
            temp2 = temp2->mNext;
        }
        nodeCount++;
        
        temp1 = temp1->mNext;
        temp2 = temp1->mNext;
   }
}

//adds data to the new node
template <class T>
Node<T>* Apriori<T>::makeNewNode(Node<T>* temp1, Node<T>* temp2)
{
   Node<T>* newNode = new Node<T>;
   newNode->mSize = newNode->size + 1;

   for(int i = 0; i < temp1->mSize; i++)
   {
      newNode->mData[i] = temp1->mData[i];
   }
   newNode->mData[newNode->mSize - 1] = temp2->mData[temp2->mSize - 1];
   
}

//checks to see if all elements in sets are the same except for last element
template <class T>
bool Apriori<T>::isSame(Node<T>* temp1, Node<T>* temp2)
{
   bool theSame = true;
   
   for(int i = 0; i < temp1->mSize; i++)
   {
      if(temp1->mData[i] != temp2->mData[i] && i < temp1->mSize - 1)
         theSame = false;
   }
   
   return theSame;
}

template <class T>
void Apriori<T>::setFrequencyThreshold(float percentage)
{
    mFrequencyThreshold = (mCountTransactions * percentage) / 100;
}
template <class T>
void Apriori<T>::prune()
{
    
    
}
template <class T>
void Apriori<T>::setCountTransactions(int count)
{
    mCountTransactions = count;
}

#endif
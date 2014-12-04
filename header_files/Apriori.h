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

/*
it shoots one to many
*/
template <typename T>
void Apriori<T>::fillStartingData(string file)
{
    ifstream inputFile;
    inputFile.open("testdata.txt");
    int itemsInTransactions = 0; //number of items bought per transaction
    int startingPosition;
    int numberOfTransactions = 0; //total amount of transactions
  
    while(numberOfTransactions <= mCountTransactions && !inputFile.eof() && itemsInTransactions != -1)
    {
        startingPosition = inputFile.tellg(); //tellg get the position of the file input
        itemsInTransactions = getDataFileCount(inputFile);
        if(itemsInTransactions == -1){ // error saying didn't take in any numbers
    		cout << "error error \n"
    		     << "broke with less then wanted number of transaction \n" 
    		     << "endded with "  << numberOfTransactions << "\n\n\n"  ;
    		break;
        }
	else
	{
            inputFile.seekg(startingPosition,inputFile.beg);
            startingData.createArray(itemsInTransactions);
            string junk;
            string input;
            for(int i = 0; i < itemsInTransactions; i++)
            {
    			inputFile >> junk; //gettint the transactional number
    			inputFile.get(); //getting the space
    			inputFile >> input; //gets the input number
			inputFile.get();// gets the newline character
    			cout << endl << input << " " << i << "  \n";
    			startingData.setArrayData(i,stoi(input));
	     }
	     
	 }
	numberOfTransactions++;
    }
    cout << "\n its done \n";
    inputFile.close();
}

/*
pre:
post: return the number of items per line
1 item = return of 1
purpose: is to get the total amount of items so we can make a static array
 */
template <typename T>
int Apriori<T>::getDataFileCount(ifstream& inputFile)
{
    int count = 0;
    
    if(inputFile.eof())
    {
        count = -1;
    }
    else
    {
        string getLineString;
        getline(inputFile, getLineString);
        char transactionNumber = getLineString[0];
        cout << "transactionNumber << " << transactionNumber << endl;  
        do
        {
            count++; // it add plus plus for the item before this
            getline(inputFile, getLineString);
        }while(transactionNumber == getLineString[0]); //so ifthe transaction number don't match
    }
    return count;
}



/*
void Apriori::findMinFrequ()
{
    
    
}
*/

/*
have not tested with search works
*/
template <typename T>
void Apriori<T>::cFirstCandList()
{
    
    startingData.clearIterator();
    do{
        T* data = startingData.getIteratorValue();
        //cout << startingData.getIteratorSize() << endl << endl;
        for(int i = 0; i < startingData.getIteratorSize(); i++)
        {
            if(!newList.search(data[i])) //not found
            {
                cout << "this is data" << data[i] << endl;
                Node<T>* newNode = new Node<T>(1, data[i]);
                newList.appendToTheEnd(newNode);
            }
        }
    }while(startingData++);
}
template <typename T>
void Apriori<T>::displayEverthing()
{
    //startingData.display();
    //oldList.display();
    newList.display();
}



//adds new nodes to new list
/*
doesn't check for doub's but i don't think it needs to
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
void Apriori<T>::setCountTransactions(int count)
{
    mCountTransactions = count;
}
template <class T>
void Apriori<T>::prune()
{
	Node<T>* currNode = newList.getHead();
	Node<T>* lastNode;  //previous node
	while(currNode != NULL)
	{
    	for(int i = 0; i < oldList.getCount(); i++)
    	{
    		for(int j = 0; j < currNode->mSize; j++)
    		{
				T* subset = new T[currNode->mSize - 1];  //one less than current node's size
				for(int k = 0; k < currNode->mSize - 1; k++)
				{
					if(k < j)
					{
						subset[k] = currNode->mData[k];
					}				
                        if(k > j)
					{
						subset[k] = currNode->mData[k + 1];
					}
				} //end of for K < currNode->size
				Node<T>* subsetNode = new Node<T>(subset->mSize,subset);
				if(!oldList.searchForNode(currNode->mSize - 1, subsetNode)) //checkListForNode?
				{
					Node<T>* tmp = currNode;
					currNode = currNode->mNext;
					if(i == 0) newList.setHead(currNode);
					else lastNode->mNext = currNode;
					delete tmp;
			    }
			    delete subsetNode;
    		} // end of for J < CurrNode->mSize
    	} //end of I < old.mCount
    	lastNode = currNode;
    	currNode = currNode->mNext;;
	}//end of the while(cNode != NULL)
}


#endif

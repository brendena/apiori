/*
errorlog
possible error with bool Operator++

*/
#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>
#include <stdlib.h> //atio
#include "Node.h"
using namespace std;

template <class T>
class LinkedList
{
    private:
        Node<T> *mHead, *mTail, *iterator;
        int     mCount;
    public:
    
    //getters
    	int  getCount();  //works
    	T    getData(int index);
    	
    //setters
    	void setData(int index, T data);
		void createArray(int size);
    	void setArrayData(int index, int data);
    	
 	//utilities
    	void clear();
    	void display();
    	bool isEmpty();
    	bool dealWithAddingValuesToBeginning(Node<T>* value);
    	void appendToTheEnd(Node<T>* value);
    	bool search(int value);
    //dealing with iterator
    	void clearIterator();
		int getIteratorSize();
		T* getIteratorValue();
		
    //operttor//constructors
    	T operator[](int index);
    	bool operator++(int value); /************ added the int value and it compiled May not work *********************/
    	LinkedList();
    	~LinkedList();
};

template <class T>
LinkedList<T>::LinkedList()
{
	mHead = NULL;
	mTail = NULL;
	iterator = NULL;
	mCount = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
   // clear();
}

template <class T>
int LinkedList<T>::getCount()
{
	return mCount;
}

template <class T>
T LinkedList<T>::getData(int index)
{
	Node<T>* ptrIterator = mHead;
	for (int i = 0; i < index; i++)
	{
		ptrIterator = ptrIterator->mNext;
	}
	return ptrIterator->mData;
}

template <class T>
void LinkedList<T>::setData(int index, T data)  ///really bad implementation
{
	if (mCount < index)
	{ 
		cout << "this is a no no " << endl; 
	}
	else if (mHead == NULL)
	{
		mHead = new Node<T>(data);
		mTail = mHead;
	}
	else{
		Node<T>* tmp = mHead;
		for (int i = 0; tmp->mNext != NULL && index == i; i++)//get the node right before the index
		{
			tmp = tmp->mNext;
		}
	}
}


template <class T>
void LinkedList<T>::clear()  //doesn't work
{
	Node<T>* ptrIterator = mHead->mNext;
	while (ptrIterator != NULL) // get it down to the only value left is mHead
	{
		delete mHead;
		mHead = ptrIterator;
		ptrIterator = ptrIterator->mNext; 
	}
	delete mHead;
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}


template <class T>
T LinkedList<T>::operator[](int index)
{
	Node<T>* ptrIterator = mHead;
	for (int i = 0; i < index && ptrIterator->mNext != NULL; i++)
	{
		ptrIterator = ptrIterator->mNext;
	}
	return ptrIterator->mData;
}


/*
pre:
Post:
Purpose: is to keep a position
*/
template <class T>
bool LinkedList<T>::operator++(int value)
{
	
	if(isEmpty())
	{
		cout << "empty \n";
		return 0;
	}
	else
	{
		cout << "iterator value " << iterator->mData[0] << "\n"; 
		iterator = iterator->mNext;
	}
	if(iterator == NULL)
	{
		cout << "null\n";
		return 0;
	}
	else
	{
		return 1;
	}
	
	//return false;  this works
}

template <class T>
bool LinkedList<T>::isEmpty()
{
	return mHead == NULL;
}

/*
pre:size of the array
Post: is to then add the items to the array
purpose:
the purpose is to make the tail ready to add the elements to.  
We want the tail to be ready because where allways going to be adding onto the tail.
*/
template <class T>
void LinkedList<T>::createArray(int size)
{
	Node<T>* newNode = new Node<T>(size);
	appendToTheEnd(newNode);
}
template <class T>
void LinkedList<T>::setArrayData(int index, int data)
{
	mTail->mData[index] = data;
}


template <class T>
void LinkedList<T>::clearIterator()
{
	iterator = mHead;
}

template <class T>
int LinkedList<T>::getIteratorSize()
{
	return iterator->mSize;	
}

template <class T>
T* LinkedList<T>::getIteratorValue()
{
	return iterator->mData;
}

/*
pre: just a value
post:  return a true if its been added else returns false
purpose:  is to create the first 2 values of the linked list

// might be a problem if the number come up twice first go////////
*/
template <class T>
bool LinkedList<T>::dealWithAddingValuesToBeginning(Node<T>* value)
{
	if(mHead == NULL)
	{
		mHead = value;
		mTail = mHead;
		mCount++;
		return true;
	}
	else if(mHead == mTail)
	{
		mHead->mNext = value;
		mTail = mHead->mNext;
		mCount++;
		return true;
	}
	return false;
}

template <class T>
void LinkedList<T>::appendToTheEnd(Node<T>* value)
{
	if(!dealWithAddingValuesToBeginning(value))
	{
		mTail->mNext = value;
		mTail = mTail->mNext;
	}
}

template <class T>
bool LinkedList<T>::search(int value)
{
	Node<T>* ptr = mHead;

	while(ptr != NULL)
	{
		for(int i = 0; i < ptr->mSize + 1; i++)
		{
			if(value == ptr->mData[i])
			{
				return true;
			}
		}
		ptr = ptr->mNext;
	}
	return false;
}


template <class T>
void LinkedList<T>::display()
{
	Node<T>* ptr = mHead;
	int sizeArray;
	cout << "\ndisplay\n";
	for (int i = 0; ptr != NULL; i++)
	{
		cout << "\n\n\nobjects number " << i;
		for(int i = 0; i <= ptr->mSize; i++)
		{
			cout << "data " << ptr->mData[i] << endl;
		}
		ptr = ptr->mNext;
	}
}
#endif
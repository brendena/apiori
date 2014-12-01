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
        Node<T> *mHead, *mTail;
        int     mCount;
    public:
    	int  getCount();  //works
    	T    getData(int index);  
    	void setData(int index, T data);
		void createArray(int size);
    	void setArrayData(int index, int data);

    	void clear();
    	void display();
    	bool isEmpty();
    	
    	T operator[](int index);
		LinkedList(int coun);
    	LinkedList();
    	~LinkedList();
};

template <class T>
LinkedList<T>::LinkedList()
{
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}

template <class T>
LinkedList<T>::LinkedList(int count)
{
	mCount = count;
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
void LinkedList<T>::display()
{
	Node<T>* ptrIterator = mHead;
	if (isEmpty())
	{
		cout << "sorry nothing in here";
	}
	else
	{
		while (ptrIterator != NULL)
		{
			cout << ptrIterator->mData << "\n";
			ptrIterator = ptrIterator->mNext;
		}
	}
	
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

template <class T>
bool LinkedList<T>::isEmpty()
{
	bool isEmpty = false;
	if (mHead == NULL){ isEmpty = true; }
	return isEmpty;
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
//*

	if(mHead == NULL)
	{
		cout << "0\n";
		mHead = new Node<T>();
		mTail = mHead;
	}
	else if(mHead == mTail)
	{
		cout << "1\n";
		mHead->mNext = new Node<T>();
		mTail = mHead->mNext;
	}
	else
	{
		cout << "2\n";
		mTail->mNext = new Node<T>();
		mTail = mTail->mNext;	
	}
	mTail->mSize = size;
	mTail->mData = new int[size+1];
//*/
}
template <class T>
void LinkedList<T>::setArrayData(int index, int data)
{
	mTail->mData[index] = data;
}


#endif

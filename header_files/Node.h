#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;


template <typename T>
struct Node
{
//data
   T*  mData; //going to a thing
   int mSize;  // no aaaaaaaaaaaaaaaaaaa
   Node<T> *mNext;
//functions
   bool shittyOperatorComparison(Node<T>* right);
//constructors and de
   Node();
   Node(int size);
   Node(int size, T data);
   Node(int size, T* data);
   ~Node();
   
   //template <typename T>
   //friend bool operator<T>==(Node<T>& left, Node<T>& right); compare mData with other mData


};

template <typename T>
Node<T>::~Node()
{
    delete [] mData;
}

template <typename T>
Node<T>::Node()
{
    mData = NULL;
	mNext = NULL;
}

template <typename T>
Node<T>::Node(int size)
{
	mSize = size;
	mData = new T[size+1];
	mNext = NULL;	
}
template <typename T>
Node<T>::Node(int size, T value)
{
    mSize = size;
    mData = new T[size + 1];
    mData[0] = value;
    mNext = NULL;
}
template <typename T>
Node<T>::Node(int size, T* value) //going to point  the same information
{
    mData = value;
    mSize = size;
}

/*
template <typename T>
bool operator==(Node<T>& left, Node<T>& right)
{
}
*/
template <typename T>
bool Node<T>::shittyOperatorComparison(Node<T>* right) //if there exactly the same
{
    for(int i = 0; i < mSize; i++)
    {
        if(mData[i] != right->mData[i])
        {
            return false;
        }
    }
    return true;
}


#endif


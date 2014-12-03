#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;


template <typename T>
struct Node
{
   T*  mData; //going to a thing
   int mSize;  // no aaaaaaaaaaaaaaaaaaa
   
   Node<T> *mNext;

   Node();
   Node(int size);
   Node(int size, T data);
   
   //template <typename T>
   //friend bool operator<T>==(Node<T>& left, Node<T>& right); compare mData with other mData
   bool shittyOperatorComparison(Node<T>* right);
   ~Node();
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
/*
template <typename T>
Node<T>::Node(T size, T* value)
{
    for(int i = 0; i <= size; i++)
    {
        
    }
}
*/
/*
template <typename T>
bool operator==(Node<T>& left, Node<T>& right)
{
}
*/
template <typename T>
bool Node<T>::shittyOperatorComparison(Node<T>* right)
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


#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;


template <typename T>
struct Node
{
   T*  mData; //going to a thing
   int mSize;  // 0 size is one array uptop
   
   Node<T> *mNext;

   Node();
   Node(T data);
   
   //template <typename T>
   //friend bool operator<T>==(Node<T>& left, Node<T>& right); compare mData with other mData
   bool shittyOperatorComparison(Node<T>* right);
};

template <typename T>
Node<T>::Node()
{
    mData = NULL;
	mNext = NULL;
}

template <typename T>
Node<T>::Node(T data)
{
	int mSize = data;
	mData = NULL;
	mNext = NULL;	
}
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


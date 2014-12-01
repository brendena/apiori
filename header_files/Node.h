#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;


template <typename T>
struct Node
{
   T       mData; //going to a pointer int
   int mSize;
   
   Node<T> *mNext;

   Node();
   Node(T data);
};

template <typename T>
Node<T>::Node()
{
	mSize = 0;
	mNext = NULL;
}

template <typename T>
Node<T>::Node(T data)
{
	int mSize = data;
	mNext = NULL;	
}

#endif
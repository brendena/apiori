{"filter":false,"title":"LinkedList.h","tooltip":"/header_files/LinkedList.h","undoManager":{"mark":0,"position":0,"stack":[[{"group":"doc","deltas":[{"start":{"row":0,"column":0},"end":{"row":135,"column":6},"action":"remove","lines":["#ifndef LINKED_LIST","#define LINKED_LIST","","#include <iostream>","#include \"Node.h\"","using namespace std;","","template <class T>","class LinkedList","{","    private:","        Node<T> *mHead, *mTail;","        int     mCount;","    public:","    \tint  getCount();  //works","    \tT    getData(int index);  ","    \tvoid setData(int index, T data);","    ","    \tvoid clear();","    \tvoid display();","    \tbool isEmpty();","    \t","    \tT operator[](int index);","    \tLinkedList();","    \t~LinkedList();","};","","template <class T>","LinkedList<T>::LinkedList()","{","\tmHead = NULL;","\tmTail = NULL;","\tmCount = 0;","}","","template <class T>","LinkedList<T>::~LinkedList()","{","    clear();","}","","template <class T>","int LinkedList<T>::getCount()","{","\treturn mCount;","}","","template <class T>","T LinkedList<T>::getData(int index)","{","\tNode<T>* ptrIterator = mHead;","\tfor (int i = 0; i < index; i++)","\t{","\t\tptrIterator = ptrIterator->mNext;","\t}","\treturn ptrIterator->mData;","}","","template <class T>","void LinkedList<T>::setData(int index, T data)  ///really bad implementation","{","\tif (mCount < index)","\t{ ","\t\tcout << \"this is a no no \" << endl; ","\t}","\telse if (mHead == NULL)","\t{","\t\tmHead = new Node<T>(data);","\t\tmTail = mHead;","\t}","\telse{","\t\tNode<T>* tmp = mHead;","\t\tfor (int i = 0; tmp->mNext != NULL && index == i; i++)//get the node right before the index","\t\t{","\t\t\ttmp = tmp->mNext;","\t\t}","\t}","}","","","template <class T>","void LinkedList<T>::clear()  //doesn't work","{","\tNode<T>* ptrIterator = mHead->mNext;","\twhile (ptrIterator != NULL) // get it down to the only value left is mHead","\t{","\t\tdelete mHead;","\t\tmHead = ptrIterator;","\t\tptrIterator = ptrIterator->mNext; ","\t}","\tdelete mHead;","\tmHead = NULL;","\tmTail = NULL;","\tmCount = 0;","}","","template <class T>","void LinkedList<T>::display()","{","\tNode<T>* ptrIterator = mHead;","\tif (isEmpty())","\t{","\t\tcout << \"sorry nothing in here\";","\t}","\telse","\t{","\t\twhile (ptrIterator != NULL)","\t\t{","\t\t\tcout << ptrIterator->mData << \"\\n\";","\t\t\tptrIterator = ptrIterator->mNext;","\t\t}","\t}","\t","}","","template <class T>","T LinkedList<T>::operator[](int index)","{","\tNode<T>* ptrIterator = mHead;","\tfor (int i = 0; i < index && ptrIterator->mNext != NULL; i++)","\t{","\t\tptrIterator = ptrIterator->mNext;","\t}","\treturn ptrIterator->mData;","}","","template <class T>","bool LinkedList<T>::isEmpty()","{","\tbool isEmpty = false;","\tif (mHead == NULL){ isEmpty = true; }","\treturn isEmpty;","}","","","#endif"]},{"start":{"row":0,"column":0},"end":{"row":186,"column":0},"action":"insert","lines":["#ifndef LINKED_LIST","#define LINKED_LIST","","#include <iostream>","#include <stdlib.h> //atio","#include \"Node.h\"","using namespace std;","","template <class T>","class LinkedList","{","    private:","        Node<T> *mHead, *mTail;","        int     mCount;","    public:","    \tint  getCount();  //works","    \tT    getData(int index);  ","    \tvoid setData(int index, T data);","\t\tvoid createArray(int size);","    \tvoid setArrayData(int index, int data);","","    \tvoid clear();","    \tvoid display();","    \tbool isEmpty();","    \t","    \tT operator[](int index);","\t\tLinkedList(int coun);","    \tLinkedList();","    \t~LinkedList();","};","","template <class T>","LinkedList<T>::LinkedList()","{","\tmHead = NULL;","\tmTail = NULL;","\tmCount = 0;","}","","template <class T>","LinkedList<T>::LinkedList(int count)","{","\tmCount = count;","}","","template <class T>","LinkedList<T>::~LinkedList()","{","   // clear();","}","","template <class T>","int LinkedList<T>::getCount()","{","\treturn mCount;","}","","template <class T>","T LinkedList<T>::getData(int index)","{","\tNode<T>* ptrIterator = mHead;","\tfor (int i = 0; i < index; i++)","\t{","\t\tptrIterator = ptrIterator->mNext;","\t}","\treturn ptrIterator->mData;","}","","template <class T>","void LinkedList<T>::setData(int index, T data)  ///really bad implementation","{","\tif (mCount < index)","\t{ ","\t\tcout << \"this is a no no \" << endl; ","\t}","\telse if (mHead == NULL)","\t{","\t\tmHead = new Node<T>(data);","\t\tmTail = mHead;","\t}","\telse{","\t\tNode<T>* tmp = mHead;","\t\tfor (int i = 0; tmp->mNext != NULL && index == i; i++)//get the node right before the index","\t\t{","\t\t\ttmp = tmp->mNext;","\t\t}","\t}","}","","","template <class T>","void LinkedList<T>::clear()  //doesn't work","{","\tNode<T>* ptrIterator = mHead->mNext;","\twhile (ptrIterator != NULL) // get it down to the only value left is mHead","\t{","\t\tdelete mHead;","\t\tmHead = ptrIterator;","\t\tptrIterator = ptrIterator->mNext; ","\t}","\tdelete mHead;","\tmHead = NULL;","\tmTail = NULL;","\tmCount = 0;","}","","template <class T>","void LinkedList<T>::display()","{","\tNode<T>* ptrIterator = mHead;","\tif (isEmpty())","\t{","\t\tcout << \"sorry nothing in here\";","\t}","\telse","\t{","\t\twhile (ptrIterator != NULL)","\t\t{","\t\t\tcout << ptrIterator->mData << \"\\n\";","\t\t\tptrIterator = ptrIterator->mNext;","\t\t}","\t}","\t","}","","template <class T>","T LinkedList<T>::operator[](int index)","{","\tNode<T>* ptrIterator = mHead;","\tfor (int i = 0; i < index && ptrIterator->mNext != NULL; i++)","\t{","\t\tptrIterator = ptrIterator->mNext;","\t}","\treturn ptrIterator->mData;","}","","template <class T>","bool LinkedList<T>::isEmpty()","{","\tbool isEmpty = false;","\tif (mHead == NULL){ isEmpty = true; }","\treturn isEmpty;","}","","/*","pre:size of the array","Post: is to then add the items to the array","purpose:","the purpose is to make the tail ready to add the elements to.  ","We want the tail to be ready because where allways going to be adding onto the tail.","*/","template <class T>","void LinkedList<T>::createArray(int size)","{","//*","","\tif(mHead == NULL)","\t{","\t\tcout << \"0\\n\";","\t\tmHead = new Node<T>();","\t\tmTail = mHead;","\t}","\telse if(mHead == mTail)","\t{","\t\tcout << \"1\\n\";","\t\tmHead->mNext = new Node<T>();","\t\tmTail = mHead->mNext;","\t}","\telse","\t{","\t\tcout << \"2\\n\";","\t\tmTail->mNext = new Node<T>();","\t\tmTail = mTail->mNext;\t","\t}","\tmTail->mSize = size;","\tmTail->mData = new int[size+1];","//*/","}","template <class T>","void LinkedList<T>::setArrayData(int index, int data)","{","\tmTail->mData[index] = data;","}","","","#endif",""]}]}]]},"ace":{"folds":[],"scrolltop":1804.1111507415771,"scrollleft":0,"selection":{"start":{"row":186,"column":0},"end":{"row":186,"column":0},"isBackwards":false},"options":{"guessTabSize":true,"useWrapMode":false,"wrapToView":true},"firstLineState":{"row":3,"state":"start","mode":"ace/mode/c_cpp"}},"timestamp":1417382792565,"hash":"640312a5d07a50f069cfe5842f75b240c8749818"}
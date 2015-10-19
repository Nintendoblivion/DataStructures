/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/15/15
* Last Modification Date:	10/15/15
* Lab Number:			CST 211 Assignment 3
* Filename:				LinkedList.h
*
*
*			Overview: A Linked List used to store data
*
*			Input: none
*
*			Output: none
****************************************************************/

#include "Node.h"
#include "Iterator.h"

#ifndef LinkedList_h
#define LinkedList_h

template<class T>
class LinkedList
{

public:

	LinkedList(); // constructor
	~LinkedList(); //deconstructor

	bool isEmpty() const; //return if list is empty
	const Node<T> &First(); // gets the first node
	const Node<T> &Last(); // gets the last node
	void Prepend(T *in); // add an item to the beginning of the list
	void Append(T *in); // add to the end of the list
	void Purge(); // remove all items
	Node<T> &extract(T in); // removie items with in from the list
	void InsertAfter(T in, T *thing); // insert an item after another
	void InsertBefore(T in, T *thing); // iinsert an item before another
	Iterator<T> begin(); // iterator to the start of the list
	Iterator<T> end(); // iterator to the end of the list


private:
	Node<T> *m_tail; //pointer to end of the list
	Node<T> *m_head; //pointer to the start of the list
};
#include "LinkedList.inc"

#endif
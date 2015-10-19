/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/15/15
* Last Modification Date:	10/15/15
* Lab Number:			CST 211 Assignment 3
* Filename:				Iterator.h
*
*
*			Overview: A way of accessing nods by incrmenting and
*						decermnting this type
*
*			Input: none
*
*			Output: none
****************************************************************/

#include "Node.h"
#include <iostream>

using namespace std;

#ifndef Iterator_h
#define Iterator_h

template<class T>
class Iterator
{
public:

	template<class T> friend ostream &operator<<(ostream &os, const Iterator<T> &rhs);

	Iterator(Node<T> *in); // constructor
	~Iterator(); //deconstructor

	bool operator==(const Iterator &other); //override the == comparison
	bool operator!=(const Iterator &other); //override the != comparison

	Iterator operator++(); //override the ++ operator to change nodes
	Iterator operator++(int in); //override the ++ operator to change nodes

	Iterator operator--(); //override the -- operator to change nodes
	Iterator operator--(int in); //override the -- operator to change nodes

	T node_data() const;

	

private:
	Node<T> *m_node; //current node of the iterator

};

#include "Iterator.inc"

#endif
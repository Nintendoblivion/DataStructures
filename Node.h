/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/15/15
* Last Modification Date:	10/15/15
* Lab Number:			CST 211 Assignment 3
* Filename:				Node.h
*
*
*			Overview: A node containing a data and two pointer 
*						to the previous and next node
*
*			Input: none
*
*			Output: none
****************************************************************/

#ifndef Node_h
#define Node_h


template<class T>
class Node
{
public:

	Node(); //class constructor
	~Node(); // class destructor

	void data(T *in); //m_data mutator
	T data() ; // m_data accessor 

	void next(Node *in); //m_prev mutator
	Node *next() ; //m_next accessor

	void prev(Node *in); //m_prev mutator
	Node *prev() ; //m_prev accessor

private:
	T m_data;

	Node *m_next; // a pointer to the next node, if null then it is the tail
	Node *m_prev; // a pointer to the previous node, if null then it is the head

}; 

#include "Node.inc"

#endif
/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/15/15
* Last Modification Date:	10/15/15
* Lab Number:			CST 211 Assignment 3
* Filename:				Node.inc
*
*
*			Overview: A node containing a data and two pointer
*						to the previous and next node
*
*			Input: none
*
*			Output: none
****************************************************************/

/**************************************************************
*	  Purpose: Node object contstructor
*
*		 Entry: none
*
*			Exit: none
****************************************************************/
template<class T>
Node<T>::Node()
{
	
}

/**************************************************************
*	  Purpose: To delete anything remaining of the Node object
*
*		 Entry: none
*
*			Exit: none
****************************************************************/
template<class T>
Node<T>::~Node()
{
	
}

/**************************************************************
*	  Purpose: Mutator for the data of the node
*
*		 Entry: none
*
*			Exit: The data of contained by the node
****************************************************************/
template<class T>
void Node<T>::data(T *in)
{
	m_next = new Node < T > ;
	m_prev = new Node < T >;
	m_data = *in;
}

/**************************************************************
*	  Purpose: Accessor for the data of the node
*
*		 Entry: none
*
*			Exit: The data of contained by the node
****************************************************************/
template<class T>
T Node<T>::data() 
{
	return m_data;
}


/**************************************************************
*	  Purpose: Mutator for the data of the next node
*
*		 Entry: none
*
*			Exit: A pointer to the next node
****************************************************************/
template<class T>
void Node<T>::next(Node *in)
{
	m_next = in;
}

/**************************************************************
*	  Purpose: Accessor for the data of the next node
*
*		 Entry: none
*
*			Exit: A pointer to the next node
****************************************************************/
template<class T>
Node<T> *Node<T>::next() 
{
	return m_next;
}


/**************************************************************
*	  Purpose: Mutator for the data of the prev node
*
*		 Entry: none
*
*			Exit: A pointer to the previous node
****************************************************************/
template<class T>
void Node<T>::prev(Node *in)
{
	m_prev = in;
}

/**************************************************************
*	  Purpose: Accessor for the data of the prev node
*
*		 Entry: none
*
*			Exit: A pointer for the the previous node
****************************************************************/
template<class T>
Node<T> *Node<T>::prev()
{
	return m_prev;
}
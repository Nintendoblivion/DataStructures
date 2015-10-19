/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/15/15
* Last Modification Date:	10/15/15
* Lab Number:			CST 211 Assignment 3
* Filename:				LinkedList.inc
*
*
*			Overview: A Linked List used to store data
*
*			Input: none
*
*			Output: none
****************************************************************/

/**************************************************************
*	  Purpose:  Constructor for the Linked List Object
*
*		 Entry: none
*
*			Exit: none
****************************************************************/
template<class T>
LinkedList<T>::LinkedList()
{

}


/**************************************************************
*	  Purpose: To delete anything remaining of the LinkedList object
*
*		 Entry: none
*
*			Exit: none
****************************************************************/
template<class T>
LinkedList<T>::~LinkedList()
{
}



/**************************************************************
*	  Purpose: To return if the Linked List contains anything
*
*		 Entry: none
*
*			Exit: A bool telling if the Linked List contains anything
****************************************************************/
template<class T>
bool LinkedList<T>::isEmpty() const
{
	return !(m_tail || m_head);
}


/**************************************************************
*	  Purpose: return a node of the first data
*
*		 Entry: none
*
*			Exit: return a node of the first data
****************************************************************/
template<class T>
const Node<T> &LinkedList<T>::First()
{
	return m_head;
}


/**************************************************************
*	  Purpose: return a node of the last data
*
*		 Entry: none
*
*			Exit: return a node of the last data
****************************************************************/
template<class T>
const Node<T> &LinkedList<T>::Last()
{
	return m_tail;
}


/**************************************************************
*	  Purpose: Add an item to the beginning of the Linked List
*
*		 Entry: Data for the new starting node
*
*			Exit: none
****************************************************************/
template<class T>
void LinkedList<T>::Prepend(T *in)
{
	if (isEmpty()){
		m_tail = new Node < T >;
		m_head = new Node < T >;
		m_tail->data(in);
		m_head->data(in);
		m_tail->prev(m_head);
		m_head->next(m_tail);
	}
	else{
		m_tail->prev()->data(in);
		m_tail->prev()->next(m_tail);
		m_tail = m_tail->prev();
	}
}


/**************************************************************
*	  Purpose: Add an item to the end of the Linked List
*
*		 Entry: Data for the new ending node
*
*			Exit: none
****************************************************************/
template<class T>
void LinkedList<T>::Append(T *in)
{
	
	if (isEmpty()){
		m_tail = new Node < T >;
		m_head = new Node < T >;
		m_tail->data(in);
		m_head->data(in);
		m_tail->prev(m_head);
		m_head->next(m_tail);
	}
	else{
		m_tail->next()->data(in);
		m_tail->next()->prev(m_tail);
		m_tail = m_tail->next();
	}
}


/**************************************************************
*	  Purpose: Remove all items
*
*		 Entry: none
*
*			Exit: none
****************************************************************/
template<class T>
void LinkedList<T>::Purge()
{
	
}


/**************************************************************
*	  Purpose: To remove data from the list
*
*		 Entry: data used to locate the node
*
*			Exit: A node containing the data passed in
****************************************************************/
template<class T>
Node<T> &LinkedList<T>::extract(T in)
{

}


/**************************************************************
*	  Purpose: Insert a node object after a node containing data 
*				of the same passed in
*
*		 Entry: New data to be put in
*				The comparison data
*
*			Exit: none
****************************************************************/
template<class T>
void LinkedList<T>::InsertAfter(T in, T *thing)
{

}


/**************************************************************
*	  Purpose: Insert a node object before a node containing data
*				of the same passed in
*
*		 Entry: New data to be put in
*				The comparison data
*
*			Exit: none
****************************************************************/
template<class T>
void LinkedList<T>::InsertBefore(T in, T *thing)
{

}


/**************************************************************
*	  Purpose: starting iterator to know where the beginning
*				of the Linked List is
*
*		 Entry: none
*
*			Exit: An Iterator of the first node
****************************************************************/
template<class T>
Iterator<T> LinkedList<T>::begin()
{
	Iterator<T> fill(m_head);
	return fill;
}


/**************************************************************
*	  Purpose: ending iterator to know where the end
*				of the Linked List is
*
*		 Entry: none
*
*			Exit: An Iterator of the last node
****************************************************************/
template<class T>
Iterator<T> LinkedList<T>::end()
{
	Iterator<T> fill(m_tail);
	return fill;
}
/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/15/15
* Last Modification Date:	10/15/15
* Lab Number:			CST 211 Assignment 3
* Filename:				Iterator.inc
*
*
*			Overview: A way of accessing nods by incrmenting and
*						decermnting this type
*
*			Input: none
*
*			Output: none
****************************************************************/

/**************************************************************
*	  Purpose: Constructor for a new Iterator
*
*		 Entry: none
*
*			Exit: none
****************************************************************/
template<class T>
Iterator<T>::Iterator(Node<T> *in) : m_node(in)
{

}

/**************************************************************
*	  Purpose: To delete anything remaining of the Iterator object
*
*		 Entry: none
*
*			Exit: none
****************************************************************/
template<class T>
Iterator<T>::~Iterator()
{
}


/**************************************************************
*	  Purpose: override the == comparison
*
*		 Entry: none
*
*			Exit: none
****************************************************************/
template<class T>
bool Iterator<T>::operator==(const Iterator& other){
	return node_data() == other.node_data();
}

/**************************************************************
*	  Purpose: override the != comparison
*
*		 Entry: none
*
*			Exit: none
****************************************************************/
template<class T>
bool Iterator<T>::operator!=(const Iterator& other){
	return node_data() != other.node_data();
}

/**************************************************************
*	  Purpose: Override the ++ operation to be able iterate
*				through a list
*
*		 Entry: none
*
*			Exit: An iterator for the next node
****************************************************************/
template<class T>
Iterator<T> Iterator<T>::operator++()
{
	m_node = m_node->next();
	return *this;
}

/**************************************************************
*	  Purpose: Override the ++ operation to be able iterate
*				through a list
*
*		 Entry: none
*
*			Exit: An iterator for the next node
****************************************************************/
template<class T>
Iterator<T> Iterator<T>::operator++(int in)
{
	m_node = m_node->next();
	return *this;
}


/**************************************************************
*	  Purpose: Override the -- operation to be able iterate
*				through a list
*
*		 Entry: none
*
*			Exit: An iterator for the next node
****************************************************************/
template<class T>
Iterator<T> Iterator<T>::operator--()
{
	m_node = m_node->prev();
	return *this;
}

/**************************************************************
*	  Purpose: Override the -- operation to be able iterate
*				through a list
*
*		 Entry: none
*
*			Exit: An iterator for the prev node
****************************************************************/
template<class T>
Iterator<T> Iterator<T>::operator--(int in)
{
	m_node = m_node->prev();
	return *this;
}


/**************************************************************
*	  Purpose: Override the -- operation to be able iterate
*				through a list
*
*		 Entry: none
*
*			Exit: An iterator for the prev node
****************************************************************/
template<class T>
T Iterator<T>::node_data() const{
	return m_node->data();
}

/**************************************************************
*	  Purpose: Override the -- operation to be able iterate
*				through a list
*
*		 Entry: none
*
*			Exit: An iterator for the prev node
****************************************************************/
template<class T>
ostream &operator<<(ostream &os, const Iterator<T> &rhs)
{
	
	return os << rhs.m_node->data();
}
/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/10/15
* Last Modification Date:	10/10/15
* Lab Number:			CST 211 Assignment 1
* Filename:				array.inc
*
*
*			Overview: To properly allocate data for an array
*
*			Input: A starting index and size for the array
*
*			Output: An array
****************************************************************/

#include  <iostream>
using  namespace  std;

/**************************************************************
*	  Purpose:  Construcotr for the Exception class
*
*		 Entry: The Array starting index
*				The Array size
*
*			Exit: none
****************************************************************/
template<class TYPE>
Array<TYPE>::Array(int start_index, int length)
: m_upperbound(start_index + length), m_lowerbound(start_index), m_length(length){

	m_array = new TYPE[m_upperbound - m_lowerbound + 1];
	if (!m_array){
		Exception fail("Failed memory allocation");
		throw(fail);
	}
}


/**************************************************************
*	  Purpose:  Arrayy Class deconstructor to clean up the class
*
*		 Entry: none
*
*			Exit: none
****************************************************************/
template<class TYPE>
Array<TYPE>::~Array(){
	clear();
}


/**************************************************************
*	  Purpose:  To override the assignment operator
*
*		 Entry: An array to set the array = to
*
*			Exit: An array of the same kind
****************************************************************/
template<class TYPE>
Array<TYPE> &Array<TYPE>::operator=(const Array<TYPE> &rhs){

	if (this != &rhs){
		clear();
		copy(rhs);
	}

	return *this;

}


/**************************************************************
*	  Purpose:  delete if the data is the last remaining
*
*		 Entry: none
*
*			Exit: none
****************************************************************/
template<class TYPE>
void Array<TYPE>::clear(){

	if (m_refCounter.onlyInstance()){
		delete[]m_array;
	}

}


/**************************************************************
*	  Purpose:  Copy constructor for the Array template class
*
*		 Entry: An array that will be copied
*
*			Exit: none
****************************************************************/
template<class TYPE>
void Array<TYPE>::copy(const Array<TYPE> &rhs){

	m_upperbound = rhs.m_upperbound;
	m_lowerbound = rhs.m_lowerbound;
	m_refCounter = rhs.m_refCounter;
	m_length = rhs.m_length;
	m_array = new TYPE[m_upperbound - m_lowerbound + 1];
	for (int i = m_upperbound-m_lowerbound; i >= 0; i--){
		m_array[i] = rhs.m_array[i];
	}
	

}


/**************************************************************
*	  Purpose:  To override the [] operator for easy array access
*
*		 Entry: the value of the array
*
*			Exit: An element of the array
****************************************************************/
template<class TYPE>
TYPE &Array<TYPE>::operator[](int idx) const 
{
	if (idx <lowerBound() || upperBound() < idx){
		fail.setMessage("Out of Bounds");
		throw(fail);
	}
	return m_array[idx - m_lowerbound];
}


/**************************************************************
*	  Purpose:  To override the [] operator for easy array access
*
*		 Entry: the value of the array
*
*			Exit: An element of the array
****************************************************************/
template<class TYPE>
TYPE &Array<TYPE>::operator[](int idx)
{
	if (idx <lowerBound() || upperBound() < idx){
		Exception fail("Out_of_Bounds");
		throw(fail);
	}
	return m_array[idx - m_lowerbound];
}


/**************************************************************
*	  Purpose:  To reset the length of the array
*
*		 Entry: the new array length
*
*			Exit: none
****************************************************************/
template<class TYPE>
void Array<TYPE>::setLength(int length)
{
	m_length = length;
	TYPE *temp_array;
	temp_array = new TYPE[length];
	for (int i = 0; i < length; i++)
	{
		temp_array[i] = m_array[i];
	}
	delete[]m_array;
	
	m_array = new TYPE[length];
	if (!m_array){
		throw(ERR_MEM_ALLOC);
	}
	m_upperbound = m_lowerbound + length;
	for (int i = 0; i < length; i++)
	{
		m_array[i] = temp_array[i];
	}
	delete temp_array;
}


/**************************************************************
*	  Purpose:  To reset the lower bound of the array
*
*		 Entry: The new start for the array
*
*			Exit: none
****************************************************************/
template<class TYPE>
void Array<TYPE>::setStartIndex(int start_index)
{
	int change = m_lowerbound - start_index;
	m_lowerbound = start_index;
	m_upperbound = m_upperbound - change;
}



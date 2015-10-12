/*
Author: Andrew Arizala

Description: File to store the template code


*/

#include  <iostream>
using  namespace  std;

/*
	Array<>
*/

template<class TYPE>
Array<TYPE>::Array(int start_index, int length)
: m_upperbound(start_index + length), m_lowerbound(start_index), m_length(length){

	m_array = new TYPE[m_upperbound - m_lowerbound + 1];
	if (!m_array){
		Exception fail("Failed memory allocation");
		throw(fail);
	}
}

template<class TYPE>
Array<TYPE>::~Array(){
	clear();
}

template<class TYPE>
Array<TYPE> &Array<TYPE>::operator=(const Array<TYPE> &rhs){

	if (this != &rhs){
		clear();
		copy(rhs);
	}

	return *this;

}

template<class TYPE>
void Array<TYPE>::clear(){

	if (m_refCounter.onlyInstance()){
		delete[]m_array;
	}

}

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

template<class TYPE>
TYPE &Array<TYPE>::operator[](int idx) const 
{
	if (idx <lowerBound() || upperBound() < idx){
		fail.setMessage("Out of Bounds");
		throw(fail);
	}
	return m_array[idx - m_lowerbound];
}

template<class TYPE>
TYPE &Array<TYPE>::operator[](int idx)
{
	if (idx <lowerBound() || upperBound() < idx){
		Exception fail("Out_of_Bounds");
		throw(fail);
	}
	return m_array[idx - m_lowerbound];
}


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

template<class TYPE>
void Array<TYPE>::setStartIndex(int start_index)
{
	int change = m_lowerbound - start_index;
	m_lowerbound = start_index;
	m_upperbound = m_upperbound - change;
}



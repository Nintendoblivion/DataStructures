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
: m_upperbound(start_index + length), m_lowerbound(start_index), m_length(length), fail("default"){

	m_array = new TYPE[m_upperbound - m_lowerbound + 1];
	if (!m_array){
		throw(ERR_MEM_ALLOC);
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
		cout << fail;
		abort();
	}
	return m_array[idx - m_lowerbound];
}

template<class TYPE>
TYPE &Array<TYPE>::operator[](int idx)
{
	if (idx <lowerBound() || upperBound() < idx){
		fail.setMessage("Out of Bounds");
		abort();
	}
	return m_array[idx - m_lowerbound];
}


template<class TYPE>
void Array<TYPE>::setLength(int length)
{
	m_upperbound = m_lowerbound + length;
	m_length = length;
}

template<class TYPE>
void Array<TYPE>::setStartIndex(int start_index)
{
	int change = m_lowerbound - start_index;
	m_lowerbound = start_index;
	m_upperbound = m_upperbound - change;
}



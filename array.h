/*
Author: Andrew Arizala

Description: Header for Array class and Safe Array Template Class


*/
#include "refCounter.h"
#include "exception.h"

#ifndef array_h
#define array_h

#define  ERR_BAD_BOUNDS     1
#define  ERR_MEM_ALLOC      2
#define  ERR_OUT_OF_BOUNDS  3

/*
* Constraints for the TYPE datatype for the Array<> template class:
*
*   TYPE must support assignment (=)
*   TYPE must support default construction
*   TYPE must support copying
*
*/

template<class  TYPE>
class Array 
{

public:
	Array();
	
	Array(int start_index, int length);
	~Array();

	int upperBound() const { return m_upperbound; }
	int lowerBound() const { return m_lowerbound; }
	int numElements() const { return m_upperbound - m_lowerbound + 1; }
	int size() const { return sizeof(TYPE)*(m_upperbound - m_lowerbound + 1); }
	TYPE &operator[](int idx);
	TYPE &operator[](int idx) const;
	Array &operator=(const Array<TYPE> &rhs);

	int getStartIndex() const { return m_lowerbound; }

	int getLength() const { return m_length; }

	void setLength(int length);

	void setStartIndex(int start_index);

protected :
	void errorOutput(int errorType);

private :
	int m_upperbound, m_lowerbound, m_length;
	TYPE *m_array;
	RefCounter m_refCounter;
	void clear();
	void copy(const Array<TYPE> &rhs);

		
};


/*
* Constraints for the TYPE datatype for the SafeArray<> template class:
*
*    Same as Array<>
*
*
*/

#include "array.inc"

#endif

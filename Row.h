

/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/10/15
* Last Modification Date:	10/10/15
* Lab Number:			CST 211 Assignment 2
* Filename:				row.h
*
*
*			Overview: A thing to read the row
*
*			Input: An Array2D object and a row number
*
*			Output: none
****************************************************************/

#ifndef Row_h
#define Row_h


template <class T>
class Array2D;

class Exception;

template <class T>
class Row
{
public:
	//constructor
	Row(const Array2D<T> &array, int row);

	T &operator[](int column);
	T &operator[](int column) const;

private:
	Array2D &m_array2D;
	int m_row;
};

#include "Row.inc"

#endif
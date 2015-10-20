/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/10/15
* Last Modification Date:	10/10/15
* Lab Number:			CST 211 Assignment 2
* Filename:				Array2D.h
*
*
*			Overview: A tempmlated 2D array
*
*			Input: A number of rows and columns
*
*			Output: none
****************************************************************/


#include "exception.h"
#include "Row.h"

using  namespace  std;


#ifndef Array2D_h
#define Array2D_h



template <class T>
class Array2D
{
public:
	Array2D(); // default constructor
	Array2D(int row, int col);  // constructor for the 
	Array2D(const Array2D &copy); //copy constructor
	~Array2D(); //deconstructor

	Array2D &operator=(const Array2D &rhs); //override Assignment operator
	Row<T> operator[](int index); //override "[]" operator
	Row<T> operator[](int index) const; //override "[]" operator const

	int getRow() const; //return number of rows
	void setRow(int rows); //change number of rows
	int getColumn() const; //return number of columns
	void setColumn(int columns); //change number of columns
	T &Select(int row, int column) const; //to select an element of the Array2D object

private:

	T **m_array; // pointer to an array of the data type that will be allocated
	int m_rows;  // number of rows in array
	int m_cols; // number of columns in array

	void create_array(T **&new_array, int rows, int cols); //to allocate data for new arrays
	void array_transfer(T **new_array, int rows, int cols, bool conserve); //to conserve and transfer data between 2D arrays
};

#include "Array2D.inc"

#endif
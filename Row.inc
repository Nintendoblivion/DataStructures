

/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/10/15
* Last Modification Date:	10/10/15
* Lab Number:			CST 211 Assignment 2
* Filename:				row.cpp
*
*
*			Overview: A thing to read the row
*
*			Input: An Array2D object and a row number
*
*			Output: none
****************************************************************/





/**************************************************************
*	  Purpose:  Construction of the Row object
*
*		 Entry: array is the 2D array object used
*
*			Exit: none
****************************************************************/
template <class T>
Row<T>::Row(const Array2D<T> &Array, int row) 
	: m_array2D(Array), m_row(row)
{
	
}

/**************************************************************
*	  Purpose:  to override the "[]" operator of the Row object
*				it allow you to be able to select specific elements in they array
*
*		 Entry: column of the Array2D object
*
*			Exit: an element of the Row object
****************************************************************/
template <class T>
T &Row<T>::operator[](int column)
{
	if (0 < column && column < m_array2D.getColumn()){
		return m_array2D.select(m_row, column);
	}
	Exception fail("Out of bounds");
	throw(fail);
}

/**************************************************************
*	  Purpose:  to override the "[]" operator of the Row object
*				it allow you to be able to select specific elements in they array
*
*		 Entry: column of the Array2D object
*
*			Exit: an element of the Row object
****************************************************************/
template <class T>
T &Row<T>::operator[](int column) const
{
	if (0 < column && column < m_array2D.getRow()){
		return m_array2D.select(m_row, column);
	}
	Exception fail("Out of bounds");
	throw(fail);
}


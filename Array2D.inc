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

/**************************************************************
*	  Purpose:  to create an Array2D object
*
*		Entry:  row is the number of rows
*				col is the number of columns
*
*			Exit:	none
****************************************************************/
template <class T>
Array2D<T>::Array2D(int row, int col)
	: m_cols(col), m_rows(row)
{
	m_dataAllocation(m_array, m_rows, m_cols);

}

/**************************************************************
*	  Purpose:  the copy constructor to copy Array2D objects
*
*		Entry:  the new array you want to copy into
*
*			Exit:  a copied array
****************************************************************/
template <class T> 
Array2D<T>::Array2D(const Array2D &arrayC)
{
	m_rows = arrayC.m_rows;
	m_cols = arrayC.m_cols;
	m_dataAllocation(m_array, m_rows, m_cols);
	m_dataTransfer(arrayC.m_array, m_rows, true, false);
}

/**************************************************************
*	  Purpose:  To delete anything remaining of the Array2D object
*
*		 Entry: none
*
*			Exit: none
****************************************************************/
template <class T>
Array2D<T>::~Array2D()
{
	delete[]m_array;
}

/**************************************************************
*	  Purpose:  to override the "=" operation of the Array2D object
*
*		 Entry: an Array2D object to set = to the current Array2D object
*
*			Exit: an Array2D object = to the current Array2D object
****************************************************************/
template <class T>
Array2D<T> &Array2D<T>::operator=(const Array2D<T> &rhs)
{
	if (this != &rhs)
	{ 
		delete[]m_array;
		m_dataAllocation(m_array, rhs.m_rows, rhs.m_cols);
		m_dataTransfer(rhs.m_array, rhs.m_rows, rhs.cols, false);
	}

	return this;
}

/**************************************************************
*	  Purpose:  to override the "[]" operator of the Array2D object
*				it allow you to be able to select specific elements in they array
*
*		 Entry: row - an int to get the row you want from the object
*
*			Exit: A row object containing the array of data they are trying to access
****************************************************************/
template <class T>
Row<T> &Array2D<T>::operator[](int row)
{
	if (0 <= row && row < getRow()){
		Row<T> rowObj(this, row);
		return rowObj;
	}
	Exception fail("Out of bounds");
	throw(fail);
}

/**************************************************************
*	  Purpose:  to override the "[]" operator of the Array2D object
*				it allow you to be able to select specific elements in they array
*
*		 Entry: row - an int to get the row you want from the object
*
*			Exit: A row object containing the array of data they are trying to access
****************************************************************/
template <class T>
Row<T> &Array2D<T>::operator[](int index) const
{
	if (0 <= row && row < getRow()){
		Row<T> rowObj(this, row);
		return rowObj;
	}
	Exception fail("Out of bounds");
	throw(fail);
}

/**************************************************************
*	  Purpose:  to return the number of rows in the array
*
*		Entry:  none
*
*			Exit:  return the number of rows in the array
****************************************************************/
template <class T>
int Array2D<T>::getRow() const
{
	return m_rows;
}

/**************************************************************
*	  Purpose:  to reset the number of rows in the array
*
*		Entry:  the number rows you want
*
*			Exit:  none
****************************************************************/
template <class T>
void Array2D<T>::setRow(int rows) 
{
	T **temp_array;

	m_dataAllocation(temp_array, rows, m_cols);
	m_dataTransfer(temp_array, rows, m_cols, true);

	delete[]m_array;

	m_dataAllocation(m_array, rows, m_cols);
	m_dataTransfer(temp_array, rows, m_cols, false);

	delete[]temp_array;
}

/**************************************************************
*	  Purpose:  to return the number of columns in the array
*
*		Entry:  none
*
*			Exit:  return the number of columns in the array
****************************************************************/
template <class T>
int Array2D<T>::getColumn() const
{
	return m_cols;
}

/**************************************************************
*	  Purpose:  to reset the number of columns in the array
*
*		Entry:  the number columns you want
*
*			Exit:  none
****************************************************************/
template <class T>
void Array2D<T>::setColumn(int columns)
{
	T **temp_array;

	m_dataAllocation(temp_array, m_rows, columns);
	m_dataTransfer(temp_array, m_rows, columns, true);
	
	delete []m_array;

	m_dataAllocation(m_array, m_rows, columns);
	m_dataTransfer(temp_array, m_rows, columns, false);

	delete[]temp_array;
	
}

/**************************************************************
*	  Purpose:  to select an element of the Array2D object
*
*		 Entry: row of the element
*				column of the element
*
*			Exit: an element of the array in that location
****************************************************************/
template <class T>
T Array2D<T>::Select(int row, int col)
{
	T *element = m_array[row];
	return element[col];
}

/**************************************************************
*	  Purpose:  to select an element of the Array2D object
*
*		 Entry: row of the element
*				column of the element
*
*			Exit: an element of the array in that location
****************************************************************/
template <class T>
void Array2D<T>::m_dataAllocation(T **&new_array, int rows, int cols)
{
	new_array = new T*[rows];
	if (!m_array)
	{
		Exception fail("Failed Memory Allocation");
		throw(fail);
	}
	for (int i = 0; i < rows; i++)
	{
		m_array[i] = new T[cols];
		if (!m_array[i])
		{
			Exception fail("Failed Memory Allocation");
			throw(fail);
		}

	}
}

/**************************************************************
*	  Purpose:  to convserve data when changing the size of an array
*
*		 Entry: The temp array to to convserve the data for the member array
*
*			Exit: none
****************************************************************/
template <class T>
void Array2D<T>::m_dataTransfer(T **&new_array, int size, bool row, bool conserve)
{
	if (row)
	{
		newRow = size;
		newCol = m_cols;
	}
	else
	{
		newRow = m_rows;
		newCol = size;
	}
	for (int idx = 0; idx < newRow; idx++)
	{
		T *memberElement = m_array[idx];
		T *tempElement = new_array[idx];
		for (int id = 0; id < newCol; id++)
		{
			if (conserve)
			{
				tempElement[id] = memberElement[id];
			}
			else
			{
				memberElement[id] = tempElement[id];
			}
		}
	}

}
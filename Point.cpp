/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/17/15
* Last Modification Date:	10/19/15
* Lab Number:			CST 211 Lab 1
* Filename:				Point.cpp
*
*
*			Overview: A point object consisting of two values
*
*			Input: Two ints
*
*			Output: none
****************************************************************/


#include"Point.h"

/**************************************************************
*	  Purpose:  Constructor for Point object
*
*		Entry:  X coordinate
*				Y coordinate
*
*			Exit:	none
****************************************************************/
Point::Point(int x, int y) : m_x(x), m_y(y)
{

}

/**************************************************************
*	  Purpose:  Override == operator 
*				to see if two points are equal
*
*		Entry:  A point to compare
*
*			Exit: If the points are equal
****************************************************************/
bool Point::operator==(const Point &rhs)
{
	if (m_x == rhs.x() && m_y == rhs.y())
	{
		return true;
	}
	return false;
}
/**************************************************************
*	  Purpose:  Override != operator
*				to see if two points aren't equal
*
*		Entry:  A point to compare
*
*			Exit: If the points aren't equal
****************************************************************/
bool Point::operator!=(const Point &rhs)
{
	return !(*this == rhs);
}

/**************************************************************
*	  Purpose:  mutator for m_x
*
*		Entry:  none
*
*			Exit: return x coordinate
****************************************************************/
int Point::x()
{
	return m_x;
}
/**************************************************************
*	  Purpose:  accessor for m_x
*
*		Entry:  none
*
*			Exit: return x coordinate
****************************************************************/
int Point::x() const
{
	return m_x;
}
/**************************************************************
*	  Purpose:  mutator for m_y
*
*		Entry:  none
*
*			Exit: return y coordinate
****************************************************************/
int Point::y()
{
	return m_y;
}
/**************************************************************
*	  Purpose:  Accessor for m_y
*
*		Entry:  none
*
*			Exit: return y coordinate
****************************************************************/
int Point::y() const
{
	return m_y;
}

/**************************************************************
*	  Purpose:  Override the insertion operator
*				To be able to display a point
*
*		Entry:  An Ostream
*				The point being displayed
*
*			Exit: The point in "X,Y" format
****************************************************************/
ostream &operator<<(ostream &os, const Point &rhs)
{
	return os << rhs.x() << "," << rhs.y();
}

/**************************************************************
*	  Purpose:  Override the insertion operator
*				To be able to read in points
*
*		Entry:  An Ostream
*				The point being made
*
*			Exit: An istream having read in "X,Y" point
****************************************************************/
istream &operator>>(istream &is, Point &rhs)
{
	char d;
	int x;
	int y;
	is >> x >> d >> y;
	rhs.m_x = x;
	rhs.m_y = y;
	return is;
}
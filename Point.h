/**************************************************************
*	Author: Andrew Arizala
* Date Created:			10/17/15
* Last Modification Date:	10/19/15
* Lab Number:			CST 211 Lab 1
* Filename:				Point.h
*
*
*			Overview: A point object consisting of two values
*
*			Input: two ints
*
*			Output: none
****************************************************************/


#include <iostream>

using namespace std;
class Point
{
public:
	Point(int x = 0, int y = 0); // constructor

	bool operator==(const Point &rhs); // returns if the points are equal
	bool operator!=(const Point &rhs); // returns if the points aren't equal

	int x(); // returns x value
	int x() const; //return x value
	int y(); //return y value;
	int y() const; // return y value

	friend ostream &operator<<(ostream &os, const Point &rhs); // output for a point object
	friend istream &operator>>(istream &is, Point &rhs); //input for a point object

private:
	int m_x; // x value
	int m_y; // y value
};
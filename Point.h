#include <iostream>

using namespace std;
class Point
{
public:
	Point(int x = 0, int y = 0);

	bool operator==(const Point &rhs);
	bool operator!=(const Point &rhs);

	int x();
	int x() const;
	int y();
	int y() const;

	friend ostream &operator<<(ostream &os, const Point &rhs);
	friend istream &operator>>(istream &is, Point &rhs);

private:
	int m_x;
	int m_y;
};
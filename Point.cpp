#include"Point.h"

Point::Point(int x, int y) : m_x(x), m_y(y)
{

}

bool Point::operator==(const Point &rhs)
{
	if (m_x == rhs.x() && m_y == rhs.y())
	{
		return true;
	}
	return false;
}
bool Point::operator!=(const Point &rhs)
{
	return !(*this == rhs);
}

int Point::x()
{
	return m_x;
}
int Point::x() const
{
	return m_x;
}
int Point::y()
{
	return m_y;
}
int Point::y() const
{
	return m_y;
}

ostream &operator<<(ostream &os, const Point &rhs)
{
	return os << rhs.x() << "," << rhs.y();
}

//causiung errors
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
#include "Point.hpp"

Point::Point(void) : _x(Fixed()), _y(Fixed())
{
	std::cout << "Default constructor Called!" << std::endl;
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
}

Point::~Point(void)
{
}

Point::Point( const Point &C) : _x(C._x), _y(C._y)
{
}

Point	&Point::operator=(const Point &C)
{
	(void)C;
	// Can only use non const members!
	return (*this);
}

const Fixed	&Point::getFixedx(void) const
{
	return(this->_x);
}

const Fixed	&Point::getFixedy(void) const
{
	return(this->_y);
}

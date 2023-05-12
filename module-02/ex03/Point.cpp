#include "Point.hpp"

Point::Point(void) : _x(Fixed()), _y(Fixed())
{
	std::cout << "Default constructor Called!" << std::endl;
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
	std::cout << "Init Constructor Called!" << std::endl;
}

Point::~Point(void)
{
	std::cout << "Destructor Called!" << std::endl;
}

Point::Point( const Point &C) : _x(C._x), _y(C._y)
{
	std::cout << "Copy Constructor Called!" << std::endl;
}

Point	&Point::operator=(const Point &C)
{
	(void)C;
	// Can only use non const members!
	std::cout << "Copy assigment overload Called!" << std::endl;
	return (*this);
}

const Fixed &Point::getFixedx(void)
{
	return(this->_x);
}

const Fixed	&Point::getFixedy(void)
{
	return(this->_y);
}

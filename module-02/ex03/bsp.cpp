#include "Point.hpp"

Fixed	area(const Fixed &x1, const Fixed &y1, const Fixed &x2, const Fixed &y2, const Fixed &x3, const Fixed &y3)
{
	/*  distance b - c   distance c - a   distance a - c 	**
	**	times x axis of the opposite side					**
	**	add all the values up and devide the result by 2	**
	**	return the area of the given triangle.. 			*/
	return ((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed Area(area(a.getFixedx(), a.getFixedy(), b.getFixedx(), b.getFixedy(), c.getFixedx(), c.getFixedy()));
	Fixed Area1(area(point.getFixedx(), point.getFixedy(), b.getFixedx(), b.getFixedy(), c.getFixedx(), c.getFixedy()));
	Fixed Area2(area(a.getFixedx(), a.getFixedy(), point.getFixedx(), point.getFixedy(), c.getFixedx(), c.getFixedy()));
	Fixed Area3(area(a.getFixedx(), a.getFixedy(), b.getFixedx(), b.getFixedy(), point.getFixedx(), point.getFixedy()));

	// If all the small triangles areas add up to the total triangle area then we know the point is inisde the triangle.
	int f_Area = std::abs(Area.toInt());

	int f_Area1 = std::abs(Area1.toInt());
	int f_Area2 = std::abs(Area2.toInt());
	int f_Area3 = std::abs(Area3.toInt());

	if (f_Area1 == 0 || f_Area2 == 0 || f_Area3 == 0)
		return (false);

	return ((f_Area == (f_Area1 + f_Area2 + f_Area3)) ? true : false);
	
}

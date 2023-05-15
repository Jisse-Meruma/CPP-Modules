#include "Point.hpp"

int	main(void)
{

	if(bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 15)))
	{
		std::cout << "The Point is inside the Triangle!" << std::endl;
	}
	else
		std::cout << "The Point is outside the Triangle!" << std::endl;
	if(bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(40, 45)))
	{
		std::cout << "The Point is inside the Triangle!" << std::endl;
	}
	else
		std::cout << "The Point is outside the Triangle!" << std::endl;
	if(bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(-2, -6)))
	{
		std::cout << "The Point is inside the Triangle!" << std::endl;
	}
	else
		std::cout << "The Point is outside the Triangle!" << std::endl;
	if(bsp(Point(0, 0), Point(10, 30), Point(20, 0), Point(3, 8)))
	{
		std::cout << "The Point is inside the Triangle!" << std::endl;
	}
	else
		std::cout << "The Point is outside the Triangle!" << std::endl;
}
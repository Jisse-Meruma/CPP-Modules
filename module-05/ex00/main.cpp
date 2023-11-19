#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat jack("Jack");
	try
	{
		jack.setGrade(100);
		std::cout << jack << std::endl;
		std::cout << jack.getGrade() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	jack.setGrade(1);
	std::cout << jack << std::endl;
	try
	{
		jack.increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		jack.setGrade(250);
		std::cout << jack << std::endl;
		jack.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
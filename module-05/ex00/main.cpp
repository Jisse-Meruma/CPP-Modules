#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat jack("Jack");
	try
	{
		jack.setGrade(-500);
		std::cout << jack.getGrade() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}
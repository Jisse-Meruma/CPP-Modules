#include "Form.hpp"

int main(void)
{
	Bureaucrat 	jack("Jack");

	try
	{
		jack.setGrade(150);
		Form	special("crazy", 100, 20);
		jack.signForm(special);	
		std::cout << special << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}



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
}
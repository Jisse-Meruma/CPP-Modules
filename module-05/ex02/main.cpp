#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
 	Bureaucrat 				jack("Jack");
	PresidentialPardonForm	president("President");
	RobotomyRequestForm 	robot("Beep");
	ShrubberyCreationForm 	rubber("Rubber");

	try
	{
		jack.setGrade(1);
		std::cout << jack << std::endl;
		// jack.signForm(president);
		// jack.signForm(robot);
		jack.executeForm(president);
		jack.executeForm(robot);	
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
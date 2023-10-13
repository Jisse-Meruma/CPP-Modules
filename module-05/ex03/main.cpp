#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	AForm* rrf;

	try
	{
		Bureaucrat jack("jack");
 		Intern someRandomIntern;
		rrf = someRandomIntern.makeForm("Robomtomy Request", "Bender");
		jack.signForm(*rrf);
		jack.executeForm(*rrf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	
}
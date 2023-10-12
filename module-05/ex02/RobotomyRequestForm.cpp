#include "RobotomyRequestForm.hpp"
#include <cstdlib>

// Constructors and Destructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("No_Name", 145, 137){
    std::cout << "RobotomyRequestForm default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 145, 137){
    std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

// Canonical form
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
    this->_target = obj.getTarget();
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) {
    *this = obj;
}

std::string RobotomyRequestForm::getTarget(void)
{
    return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    int random;

    try
    {
        this->beExecuted(executor);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    random = rand() % 100;
    random =- 50;
    std::cout << this->_target; << " ";
    if (random <= 0)
        std::cout << "robotomy failed." << std::endl;
    else
        std::cout << "has been robotomized :)" << std::endl;
}
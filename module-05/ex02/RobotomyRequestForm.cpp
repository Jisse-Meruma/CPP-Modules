#include "RobotomyRequestForm.hpp"
#include <cstdlib>

// Constructors and Destructor
RobotomyRequestForm::RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm default Constructor called" << std::endl;
    this->name = "RobotomyRequestForm";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target){
    std::cout << "RobotomyRequestForm Constructor called" << std::endl;
    this->_target = target;
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
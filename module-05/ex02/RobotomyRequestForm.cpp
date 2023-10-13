#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

// Constructors and Destructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("No_Name", 72, 45){
    std::cout << "RobotomyRequestForm default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45){
    std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

// Canonical form
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj) {
    if (this != &obj)
    {
        this->setSigned(obj.getSigned());
    }
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj.getName(), 72, 45) {
    *this = obj;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    int random;
    std::srand(static_cast<unsigned>(std::time(0)));

    try
    {
        this->beExecuted(executor);
        random = 1 + (std::rand() % 100);
        random = random - 50;
        std::cout << this->getName() << " ";
        if (random <= 0)
            std::cout << "robotomy failed." << std::endl;
        else
            std::cout << "has been robotomized :)" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
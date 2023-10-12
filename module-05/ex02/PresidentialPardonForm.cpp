#include "PresidentialPardonForm.hpp"

// Constructors and Destructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("No_Name", 145, 137){
    std::cout << "PresidentialPardonForm default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 145, 137){
    std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

// Canonical form
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
    if (this != &obj)
    {
        // No Vars Needed
    }
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) {
    *this = obj;
}

std::string PresidentialPardonForm::getTarget(void)
{
    return this->getName();
}

PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    try
    {
        this->beExecuted(executor);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl; 
}

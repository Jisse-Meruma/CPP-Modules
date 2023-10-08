#include "PresidentialPardonForm.hpp"

// Constructors and Destructor
PresidentialPardonForm::PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm default Constructor called" << std::endl;
    this->name = "PresidentialPardonForm";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form(target){
    std::cout << "PresidentialPardonForm Constructor called" << std::endl;
    this->_target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

// Canonical form
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
    this->_target = obj.getTarget();
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) {
    *this = obj;
}

std::string PresidentialPardonForm::getTarget(void)
{
    return this->_target;
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

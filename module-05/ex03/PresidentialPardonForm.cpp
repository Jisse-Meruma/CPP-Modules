#include "PresidentialPardonForm.hpp"

// Constructors and Destructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("No_Name", 25, 5){
    std::cout << "PresidentialPardonForm default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5){
    std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

// Canonical form
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj) {
    if (this != &obj)
    {
        this->setSigned(obj.getSigned());
    }
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj.getName(), 25, 5) {
    *this = obj;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    try
    {
        this->beExecuted(executor);
        std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

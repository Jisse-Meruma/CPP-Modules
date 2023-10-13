#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

const char *Intern::UnknowFormPassedException::what() const throw()
{
    return ("EXCEPTION! Unknown Form passed as a parameter!");
}

// Constructors and Destructor
Intern::Intern() {
    std::cout << "Intern default Constructor called" << std::endl;
}

Intern::~Intern() {
    std::cout << "Intern Destructor called" << std::endl;
}

// Canonical form
Intern &Intern::operator=(const Intern &obj) {
    if (this != &obj)
    {
        // No attributes
    }
    return *this;
}

Intern::Intern(const Intern &obj) {
    *this = obj;
}

AForm   *Intern::Shrubbery(const std::string &Target)
{
    return (new ShrubberyCreationForm(Target));
}

AForm   *Intern::Robotomy(const std::string &Target)
{
    return (new RobotomyRequestForm(Target));
}

AForm   *Intern::Presidential(const std::string &Target)
{
    return (new PresidentialPardonForm(Target));
}

AForm   *Intern::makeForm(const std::string &FormName, const std::string &Target)
{
    std::string Forms[3] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};
    AForm *(Intern::*creation[3])(const std::string&) = {&Intern::Shrubbery, &Intern::Robotomy, &Intern::Presidential};
    for (int i = 0; i < 4; i++)
    {
        if (Forms[i] == FormName)
        {
            std::cout << "Intern created a " << Forms[i] << std::endl; 
            return ((this->*creation[i])(Target));
        }
    }
    throw UnknowFormPassedException();

}


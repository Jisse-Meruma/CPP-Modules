#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm {

public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();

    // Copy constructor
    PresidentialPardonForm(const PresidentialPardonForm &obj);
    // Operator overload
    PresidentialPardonForm &operator=(const PresidentialPardonForm &obj);

    std::string getTarget(void);
    void execute(Bureaucrat const & executor) const;
};

#endif

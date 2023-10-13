#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm {

public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();

    // Copy constructor
    RobotomyRequestForm(const RobotomyRequestForm &obj);
    // Operator overload
    RobotomyRequestForm &operator=(const RobotomyRequestForm &obj);

    std::string getTarget(void);
    void execute(Bureaucrat const & executor) const;
};

#endif

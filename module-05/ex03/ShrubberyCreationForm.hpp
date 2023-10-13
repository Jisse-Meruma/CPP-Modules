#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {

    class UnableToOpenFileException : public std::exception {
        virtual const char *what() const throw();
    };

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();

    // Copy constructor
    ShrubberyCreationForm(const ShrubberyCreationForm &obj);
    // Operator overload
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &obj);

    std::string getTarget(void);
    void execute(Bureaucrat const & executor) const;
};

#endif

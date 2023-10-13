#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern {
public:

    class UnknowFormPassedException : public std::exception {
        virtual const char *what() const throw();
    };

    Intern();
    ~Intern();

    // Copy constructor
    Intern(const Intern &obj);
    // Operator overload
    Intern &operator=(const Intern &obj);
    AForm *makeForm(const std::string &FormName, const std::string &Target);


private:
    AForm   *Shrubbery(const std::string &Target);
    AForm   *Presidential(const std::string &Target);
    AForm   *Robotomy(const std::string &Target);

};

#endif

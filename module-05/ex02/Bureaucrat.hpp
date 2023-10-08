#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include <stdexcept>

class AForm;

class Bureaucrat {

    class GradeTooHighException : public std::exception {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        virtual const char *what() const throw();
    };

    public:
        Bureaucrat();
        Bureaucrat(std::string _name);
        ~Bureaucrat();

        // Copy constructor
        Bureaucrat(const Bureaucrat &obj);
        // Operator overload
        Bureaucrat &operator=(const Bureaucrat &obj);
        // Subject Methods
        int                 getGrade(void) const;
        const std::string   getName(void) const;
        void                setGrade(int n);
        void    increment(void);
        void    decrement(void);  

        void    signForm(AForm &obj);      

    private:
        int         _grade;
        std::string _name;
};
std::ostream&   operator<<(std::ostream &out, const Bureaucrat &obj);


#endif


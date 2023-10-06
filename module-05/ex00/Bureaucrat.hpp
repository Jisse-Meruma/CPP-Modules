#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {

    // Class Exceptions
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

    private:
        int         _grade;
        std::string _name;
};

std::ostream&   operator<<(std::ostream &out, const Bureaucrat &obj);

#endif


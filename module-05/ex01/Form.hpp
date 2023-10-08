#ifndef Form_HPP
#define Form_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	class GradeTooHighException : public std::exception {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        virtual const char *what() const throw();
    };

	public:
		Form();
		Form(const std::string _name, const int signed_grade, const int exec_grade);
		~Form();

		Form(const Form &obj);
		Form	&operator=(const Form &obj);

	void 		beSigned(const Bureaucrat &obj);
	bool 		getSigned(void) const;
	int			getSignedGrade(void) const;
	int			getExecGrade(void) const;
	std::string	getName(void) const;

	private:
		bool 				_signed;
		const int			_signed_grade;
		const int			_exec_grade;
		const std::string 	_name;
};

std::ostream&   operator<<(std::ostream &out, const Form &obj);

#endif

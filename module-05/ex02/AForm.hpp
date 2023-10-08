#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	class GradeTooHighException : public std::exception {
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        virtual const char *what() const throw();
    };
	class FormNotSignedException : public std::exception {
		virtual const char *what() const throw();
	};

	public:
		AForm();
		AForm(const std::string _name, const int signed_grade, const int exec_grade);
		~AForm();

		AForm(const AForm &obj);
		AForm	&operator=(const AForm &obj);

	void		beSigned(const Bureaucrat &obj);
	void		beExecuted(const Bureaucrat &obj);
	bool 		getSigned(void) const;
	int			getSignedGrade(void) const;
	int			getExecGrade(void) const;
	std::string	getName(void) const;

	virtual void		execute(Bureaucrat const & executor) const = 0;

	private:
		bool 				_signed;
		const int			_signed_grade;
		const int			_exec_grade;
		const std::string 	_name;
};

std::ostream&   operator<<(std::ostream &out, const AForm &obj)

#endif

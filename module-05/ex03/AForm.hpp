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
		AForm(const std::string name, const int signed_grade, const int exec_grade);
		virtual ~AForm();

		AForm(const AForm &obj);
		AForm	&operator=(const AForm &obj);

	void		beSigned(const Bureaucrat &obj);
	void		beExecuted(const Bureaucrat &obj) const;
	bool 		getSigned(void) const;
	int			getSignedGrade(void) const;
	int			getExecGrade(void) const;

	void		setSigned(bool value);
	std::string	getName(void) const;

	virtual void		execute(Bureaucrat const & executor) const = 0;

	private:
		AForm();

		bool 				_signed;
		const int			_signed_grade;
		const int			_exec_grade;
		const std::string 	_name;
};

std::ostream&   operator<<(std::ostream &out, const AForm &obj);

#endif

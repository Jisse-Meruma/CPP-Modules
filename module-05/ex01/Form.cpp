#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form, GradeTooHigh Wrong Input [1-150]");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form, GradeTooLow Wrong Input [1-150]");
}

bool Form::getSigned(void) const
{
	return this->_signed;
}

int Form::getSignedGrade(void) const
{
	return this->_signed_grade;
}

int Form::getExecGrade(void) const
{
	return this->_exec_grade;
}

std::string Form::getName(void) const
{
	return this->_name;
}

void Form::beSigned(const Bureaucrat &obj)
{	
	if (obj.getGrade() > this->_signed_grade)
		throw GradeTooLowException();
	this->_signed = true;
}


Form::Form() : _signed_grade(50), _exec_grade(50), _name("NO_NAME")
{
	std::cout << "Form default Constructor called" << std::endl;
	this->_signed = false;
}

Form::Form(const std::string name, const int signed_grade, const int exec_grade) : _signed_grade(signed_grade), _exec_grade(exec_grade), _name(name)
{
	std::cout << "Form Constructor called" << std::endl;
	if (signed_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (signed_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	this->_signed = false;
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

Form::Form(const Form &obj) :	_signed_grade(obj.getSignedGrade()),\
								_exec_grade(obj.getExecGrade()), \
								_name(obj.getName())
{
	this->_signed = obj.getSigned();
}

Form	&Form::operator=(const Form &obj)
{
	this->_signed = obj.getSigned();
	return *this;
}

std::ostream&   operator<<(std::ostream &out, const Form &obj)
{
    out << "Form " << obj.getName();
	if (obj.getSigned())
		out << " | is Signed -> YES";
	else
		out << " | is Signed -> NO";
	out << " | Grade needed to sign " << obj.getSignedGrade(); 
	out << " | Grade needed to execute " << obj.getExecGrade();
    return (out);
}

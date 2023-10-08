#include "AForm.hpp"

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Form, GradeTooHigh Wrong Input [1-150]");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Form, GradeTooLow Wrong Input [1-150]");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("AForm, FormNotSigned Please Make Sure To Have It Sign When Executed");
}

bool AForm::getSigned(void) const
{
	return this->_signed;
}

int AForm::getSignedGrade(void) const
{
	return this->_signed_grade;
}

int AForm::getExecGrade(void) const
{
	return this->_exec_grade;
}

std::string AForm::getName(void) const
{
	return this->_name;
}

void AForm::beSigned(const Bureaucrat &obj)
{	
	if (obj.getGrade() > this->_signed_grade)
		throw GradeTooLowException();
	this->_signed = true;
}

void AForm::beExecuted(const Bureaucrat &obj)
{
	if (this->_signed == false)
		throw FormNotSignedException();
	if (this->_exec_grade > obj.getGrade())
		throw GradeTooLowException();
}

AForm::AForm(const std::string name, const int signed_grade, const int exec_grade) : _signed_grade(signed_grade), _exec_grade(exec_grade), _name(name)
{
	std::cout << "AForm Constructor called" << std::endl;
	if (signed_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
	if (signed_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	this->_signed = false;
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called" << std::endl;
}

AForm::AForm(const AForm &obj) :	_signed_grade(obj.getSignedGrade()),\
								_exec_grade(obj.getExecGrade()), \
								_name(obj.getName())
{
	this->_signed = obj.getSigned();
}

AForm	&AForm::operator=(const AForm &obj)
{
	this->_signed = obj.getSigned();
	return *this;
}

std::ostream&   operator<<(std::ostream &out, const AForm &obj)
{
    out << ", Name " << obj.getName();
	out << ", is Signed " << obj.getSigned();
	out << ", Signed grade " << obj.getSignedGrade(); 
	out << ", Execute grade " << obj.getExecGrade();
    return (out);
}
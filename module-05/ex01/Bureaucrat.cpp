#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("GradeTooHighException -- Grade Too High uwu");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("GradeTooLowException -- Grade Too Low :(");
}
// Constructors and Destructor
Bureaucrat::Bureaucrat() {
    std::cout << "Bureaucrat default Constructor called" << std::endl;
    this->_name = "Bureaucrat";
    this->_grade = 1;
}

Bureaucrat::Bureaucrat(std::string n) {
    std::cout << "Bureaucrat Constructor called" << std::endl;
    this->_name = n;
    this->_grade = 1;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj) {
    this->_name = obj.getName();
    this->_grade = obj.getGrade();
    return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) {
    *this = obj;
}

const std::string Bureaucrat::getName(void) const
{
    return (this->_name);
}

void    Bureaucrat::increment(void)
{
    this->_grade -= 1;
        if (this->_grade < 1)
            throw GradeTooHighException();
}

void    Bureaucrat::decrement(void)
{
    this->_grade += 1;
        if (this->_grade > 150)
            throw GradeTooLowException();
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void    Bureaucrat::setGrade(int n)
{
    if (n > 150)
        throw GradeTooLowException();
    if (n < 1)
        throw GradeTooHighException();
    this->_grade = n;
}

void    Bureaucrat::signAForm(Form &obj)
{
    try
    {
        obj.beSigned(*this);
        std::cout << *this << " " << obj << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << *this << " couldn't sign " << obj << " Because " << e.what() << std::endl;
    }
    
}

std::ostream&   operator<<(std::ostream &out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return (out);
}

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

const char *ShrubberyCreationForm::UnableToOpenFileException::what() throw()
{
    return ("Shrubbery: Unable To Open File For Uknown Reasons!");
}

ShrubberyCreationForm::ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm default Constructor called" << std::endl;
    this->name = "ShrubberyCreationForm";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target){
    std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
    this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
    this->_target = obj.getTarget();
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) {
    *this = obj;
}

std::string ShrubberyCreationForm::getTarget(void)
{
    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::string line;

    try
    {
        this->beExecuted(executor);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::ifstream infile("tree.txt");
    std::ofstream outfile(this->_target + "_shrubbery");
    if (!outfile || !infile)
        throw UnableToOpenFileException();
    while (std::getline(infile, line))
    {
        outfile << line;  
    }
}

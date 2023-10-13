#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

const char *ShrubberyCreationForm::UnableToOpenFileException::what() const throw()
{
    return ("Shrubbery: Unable To Open File For Uknown Reasons!");
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("No_Name", 145, 137){
    std::cout << "ShrubberyCreationForm default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137){
    std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj) {
    if (this != &obj)
    {
        this->setSigned(obj.getSigned());
    }
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj.getName(), 145, 137){
    *this = obj;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::string line;
    std::string filename(this->getName() + "_shrubbery");

    try
    {
        this->beExecuted(executor);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::ifstream infile("tree.txt");
    std::ofstream outfile(filename.c_str());
    if (!outfile || !infile)
        throw UnableToOpenFileException();
    while (std::getline(infile, line))
    {
        outfile << line << std::endl;  
    }
    infile.close();
    outfile.close();
}

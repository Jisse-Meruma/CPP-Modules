#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void)
{
    std::cout << "AAnimal created with an empty construcor" << std::endl;

    this->_type = "NULL AAnimal";

    return;
}

AAnimal::~AAnimal(void)
{
    std::cout << "AAnimal " << this->_type << " deconstructed" << std::endl;
    return;
}

AAnimal::AAnimal(const AAnimal& C)
{
    std::cout << "AAnimal created by copy" << std::endl;
    *this = C;
    return;
}

AAnimal& AAnimal::operator=(const AAnimal& C)
{
    std::cout << "AAnimal created by assertion" << std::endl;

    if (this != &C)
    {
        this->_type = C._type;
    }

    return (*this);
}

void    AAnimal::makeSound( void ) const
{
    std::cout << this->_type << "...." << std::endl;
}

const std::string &AAnimal::getType( void ) const
{
    return (this->_type);
}

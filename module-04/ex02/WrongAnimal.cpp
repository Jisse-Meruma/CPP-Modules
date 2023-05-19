#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void)
{
    std::cout << "WrongAnimal created with an empty construcor" << std::endl;

    this->_type = "WrongAnimal";

    return;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal " << this->_type << " deconstructed" << std::endl;
    return;
}

WrongAnimal::WrongAnimal(const WrongAnimal& C)
{
    std::cout << "WrongAnimal created by copy" << std::endl;
    *this = C;
    return;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& C)
{
    std::cout << "WrongAnimal created by assertion" << std::endl;

    if (this != &C)
    {
        this->_type = C._type;
    }

    return (*this);
}

void    WrongAnimal::makeSound( void ) const
{
    std::cout << this->_type << " AAnimal...." << std::endl;
}

const std::string &WrongAnimal::getType( void ) const
{
    return (this->_type);
}

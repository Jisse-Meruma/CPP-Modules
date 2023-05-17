#include "Animal.hpp"
#include <iostream>

Animal::Animal(void)
{
    std::cout << "Animal created with an empty construcor" << std::endl;

    this->_type = "NULL Animal";

    return;
}

Animal::~Animal(void)
{
    std::cout << "Animal " << this->_type << " deconstructed" << std::endl;
    return;
}

Animal::Animal(const Animal& C)
{
    std::cout << "Animal created by copy" << std::endl;
    *this = C;
    return;
}

Animal& Animal::operator=(const Animal& C)
{
    std::cout << "Animal created by assertion" << std::endl;

    if (this != &C)
    {
        this->_type = C._type;
    }

    return (*this);
}

void    Animal::makeSound( void ) const
{
    std::cout << this->_type << "...." << std::endl;
}

const std::string &Animal::getType( void ) const
{
    return (this->_type);
}

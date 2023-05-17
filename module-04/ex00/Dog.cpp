#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
{
    std::cout << "Dog created with an empty construcor" << std::endl;

    this->_type = "Dog";

    return;
}

Dog::~Dog(void)
{
    std::cout << "Dog " << this->_type << " deconstructed" << std::endl;
    return;
}

Dog::Dog(const Dog& C)
{
    std::cout << "Dog created by copy" << std::endl;
    *this = C;
    return;
}

Dog& Dog::operator=(const Dog& C)
{
    std::cout << "Dog created by assertion" << std::endl;

    if (this != &C)
    {
        this->_type = C._type;
    }

    return (*this);
}

void    Dog::makeSound( void ) const
{
    std::cout << "WOEF WOEF!" << std::endl;
}

const std::string &Dog::getType( void ) const
{
    return (this->_type);
}

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
{
    std::cout << "Cat created with an empty constructor" << std::endl;

    this->_type = "Cat";

    return;
}

Cat::~Cat(void)
{
    std::cout << "Cat " << this->_type << " deconstructed" << std::endl;
    return;
}

Cat::Cat(const Cat& C)
{
    std::cout << "Cat created by copy" << std::endl;
    *this = C;
    return;
}

Cat& Cat::operator=(const Cat& C)
{
    std::cout << "Cat created by assertion" << std::endl;

    if (this != &C)
    {
        this->_type = C._type;
    }

    return (*this);
}

void    Cat::makeSound( void ) const
{
    std::cout << "MEEEEEOOWWWWW" << std::endl;
}

const std::string &Cat::getType( void ) const
{
    return (this->_type);
}

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
{
    std::cout << "WrongCat created with an empty construcor" << std::endl;

    this->_type = "WrongCat";

    return;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat " << this->_type << " deconstructed" << std::endl;
    return;
}

WrongCat::WrongCat(const WrongCat& C)
{
    std::cout << "WrongCat created by copy" << std::endl;
    *this = C;
    return;
}

WrongCat& WrongCat::operator=(const WrongCat& C)
{
    std::cout << "WrongCat created by assertion" << std::endl;

    if (this != &C)
    {
        this->_type = C._type;
    }

    return (*this);
}

void    WrongCat::makeSound( void ) const
{
    std::cout << " WRONG MEEEEEOOWWWWW" << std::endl;
}

const std::string &WrongCat::getType( void ) const
{
    return (this->_type);
}

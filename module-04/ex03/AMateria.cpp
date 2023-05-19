#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void)
{
    std::cout << "AMateria created with an empty construcor" << std::endl;

    this->_type = "AMateria";

    return;
}

AMateria::~AMateria(void)
{
    std::cout << "AMateria " << this->_type << " deconstructed" << std::endl;
    return;
}

AMateria::AMateria(const AMateria& C)
{
    std::cout << "AMateria created by copy" << std::endl;
    *this = C;
    return;
}

AMateria& AMateria::operator=(const AMateria& C)
{
    std::cout << "AMateria created by assertion" << std::endl;

    if (this != &C)
    {
        this->_type = C._type;
    }

    return (*this);
}

#include "Cure.hpp"
#include <iostream>

Cure::Cure(void)
{
    std::cout << "Cure created with an empty construcor" << std::endl;

    this->_type = "cure";

    return;
}

Cure::~Cure(void)
{
    std::cout << "Cure " << this->_type << " deconstructed" << std::endl;
    return;
}

Cure::Cure(const Cure& C)
{
    std::cout << "Cure created by copy" << std::endl;
    *this = C;
    return;
}

Cure& Cure::operator=(const Cure& C)
{
    std::cout << "Cure created by assertion" << std::endl;

    if (this != &C)
    {
        this->_type = C._type;
    }

    return (*this);
}

AMateria    *Cure::clone( void ) const
{
    return (new Cure(*this));
}

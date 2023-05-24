#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(void)
{
    std::cout << "AMateria created with an empty construcor" << std::endl;
    this->_type = "No name!";
    return;
}

AMateria::AMateria( const std::string &type)
{
    std::cout << "AMateria created with an type construcor" << std::endl;
    this->_type = type;
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

const std::string &AMateria::getType( void ) const
{
    return (this->_type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "Bare Hand: Uppercut to " << target.getName() << std::endl;
}

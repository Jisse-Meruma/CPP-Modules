#include "Ice.hpp"
#include <iostream>

Ice::Ice(void)
{
    std::cout << "Ice created with an empty construcor" << std::endl;

    this->_type = "ice";

    return;
}

Ice::~Ice(void)
{
    std::cout << "ice " << this->_type << " deconstructed" << std::endl;
    return;
}

Ice::Ice(const Ice& C)
{
    std::cout << "Ice created by copy" << std::endl;
    *this = C;
    return;
}

Ice& Ice::operator=(const Ice& C)
{
    std::cout << "Ice created by assertion" << std::endl;

    if (this != &C)
    {
        this->_type = C._type;
    }

    return (*this);
}

AMateria    *Ice::clone( void ) const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "Ice: * shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

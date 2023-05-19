#include "Ice.hpp"
#include <iostream>

Ice::Ice(void)
{
    std::cout << "Ice created with an empty construcor" << std::endl;

    this->_type = "Ice";

    return;
}

Ice::~Ice(void)
{
    std::cout << "Ice " << this->_type << " deconstructed" << std::endl;
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

#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
    std::cout << "Brain created with an empty construcor" << std::endl;
    return;
}

Brain::~Brain(void)
{
    std::cout << "Brain " << " deconstructed" << std::endl;
    return;
}

Brain::Brain(const Brain& C)
{
    std::cout << "Brain created by copy" << std::endl;
    *this = C;
    return;
}

Brain& Brain::operator=(const Brain& C)
{
    std::cout << "Brain created by assertion" << std::endl;

    if (this != &C)
    {
        std::copy(C._ideas, C._ideas + _ideas->length(), this->_ideas);
    }

    return (*this);
}

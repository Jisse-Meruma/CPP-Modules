#include "MateriaSource.hpp"
#include <iostream>
#define EMPTY NULL

MateriaSource::MateriaSource(void)
{
    std::cout << "MateriaSource created with an empty construcor" << std::endl;
    for(int i = 0; i < 4; i++)
		this->_Mlist[i] = EMPTY;
    return;
}

MateriaSource::~MateriaSource(void)
{
    std::cout << "MateriaSource deconstructed" << std::endl;
    return;
}

MateriaSource::MateriaSource(const MateriaSource& C)
{
    std::cout << "MateriaSource created by copy" << std::endl;
   	for(int i = 0; i < 4; i++)
    {
        if (C._Mlist[i] != EMPTY)
		    this->_Mlist[i] = C._Mlist[i]->clone();
    }
    return;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& C)
{
    std::cout << "MateriaSource created by assertion" << std::endl;

    if (this == &C)
        return (*this);
    for(int i = 0; i < 4; i++) 
    {   
        if (C._Mlist[i] != EMPTY)
            this->_Mlist[i] = C._Mlist[i]->clone();
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++) {
        if (this->_Mlist[i] == EMPTY) {
            this->_Mlist[i] = m;
            return ;
        }
    }
    std::cout << " Max Amount of materia's reached!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++) {
        if (this->_Mlist[i] != EMPTY && this->_Mlist[i]->getType() == type)
            return (this->_Mlist[i]);
    }
    std::cout << "Cannot Find type ur looking for!" << std::endl;
    return (NULL);
}

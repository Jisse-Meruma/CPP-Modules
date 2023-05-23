#include "Character.hpp"

Character::Character( void )
{
	for(int i = 0; i < 4; i++)
		this->_invetory[i] = NULL;
}

Character::Character( const Character &C)
{
	for(int i = 0; i < 4; i++)
		this->_invetory[i] = new AMateria(C.inver)
}
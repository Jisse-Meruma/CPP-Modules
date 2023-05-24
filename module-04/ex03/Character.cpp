#include "Character.hpp"
#define EMPTY NULL

Character::Character( void )
{
	for(int i = 0; i < 4; i++)
		this->_invetory[i] = NULL;
	for(int i = 0; i < 100; i++)
		this->_floor[i] = NULL;
	this->_name = "No Name :(";
}

Character::Character( const std::string &name )
{
	for(int i = 0; i < 4; i++)
		this->_invetory[i] = NULL;
	for(int i = 0; i < 100; i++)
		this->_floor[i] = NULL;
	this->_name = name;
}

Character::~Character( void )
{
	for(int i = 0; i < 4; i++)
		delete this->_invetory[i];
	for(int i = 0; i < 100; i++)
		delete this->_floor[i];
}

Character::Character( const Character &C)
{
	for(int i = 0; i < 4; i++)
		this->_invetory[i] = C._invetory[i]->clone();
	for(int i = 0; i < 100 && C._floor[i] != EMPTY; i++)
		this->_floor[i] = C._floor[i]->clone();
}

Character	&Character::operator=( const Character &C)
{

	if (this == &C)
		return (*this);
	for(int i = 0; i < 4; i++) {
		delete this->_invetory[i];
		this->_invetory[i] = C._invetory[i]->clone();
	}
	for(int i = 0; i < 100 && C._floor[i] != EMPTY; i++) {
		delete this->_floor[i];
		this->_floor[i] = C._floor[i]->clone();
	}
	return (*this);
}

const std::string	&Character::getName( void ) const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	for (int i=0; i<4; i++)
	{
		if (this->_invetory[i] == EMPTY) {
			this->_invetory[i] = m;
			return;
		}
	}
	std::cout << "Cant add anymore Materia's, Invertory is FULL try (Unequip!)" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx < 3)
		return ;
	for(int i = 0; i < 100; i++) {
		if (this->_floor[i] == EMPTY) {
			this->_floor[i] = this->_invetory[idx];
			break;
		}
	}
	this->_invetory[idx] = EMPTY;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3 && this->_invetory[idx] != EMPTY) {
		this->_invetory[idx]->use(target);
	}
	else
		std::cout << "Index is Not Valid!" << std::endl;
}

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name)
{
	std::cout << "(FragTrap) With Name " << name << " constructor is called!" << std::endl;
	this->_name = name;
	this->_attackdamage = 30;
	this->_energypoints = 100;
	this->_hitpoints = 100;
	this->_maxhitpoints = this->_hitpoints;

}

FragTrap::FragTrap( void ) : ClapTrap()
{
	std::cout << "(FragTrap) Default constructor is called!" << std::endl;
	this->_name = "NO NAME";
	this->_attackdamage = 30;
	this->_energypoints = 100;
	this->_hitpoints = 100;
	this->_maxhitpoints = this->_hitpoints;
}

FragTrap::~FragTrap( void )
{
	std::cout << "(FragTrap) Default deconstructor is called!" << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "(FragTrap) Hey fellow trappers can i get a HIGH FIVE :D" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (this->CanDoAction())
		return ;
	std::cout << "FragTrap " << this->_name << " Attacks " << target << ", " << "causing " << this->_attackdamage << " points of damage!" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &C)
{
	this->_name = C._name;
	this->_attackdamage = C._attackdamage;
	this->_energypoints = C._energypoints;
	this->_hitpoints = C._hitpoints;
	this->_maxhitpoints = C._maxhitpoints;

	return (*this);
}
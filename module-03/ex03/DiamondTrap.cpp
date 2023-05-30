#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name)
{
	std::cout << "(DiamondTrap) With Name " << name << " constructor is called!" << std::endl;
	ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energypoints = ScavTrap::_energypoints;
	this->_attackdamage = FragTrap::_attackdamage;
	this->_maxhitpoints = this->_hitpoints;

}

DiamondTrap::DiamondTrap( void ) : ClapTrap()
{
	std::cout << "(DiamondTrap) Default No-Name constructor is called!" << std::endl;
	this->_name = "NO NAME";
	this->_name = ClapTrap::_name;
	this->_hitpoints = FragTrap::_hitpoints;
	this->_energypoints = ScavTrap::_energypoints;
	this->_attackdamage = FragTrap::_attackdamage;
	this->_maxhitpoints = this->_hitpoints;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "(DiamondTrap) Default deconstructor is called!" << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void )
{
	std::cout << "Name of DiamondTrap [" << this->_name << "]" << std::endl;
	std::cout << "Name of ClapTrap [" << ClapTrap::_name << "]" <<  std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &C)
{
	this->_name = C._name;
	this->_attackdamage = C._attackdamage;
	this->_energypoints = C._energypoints;
	this->_hitpoints = C._hitpoints;
	this->_maxhitpoints = C._maxhitpoints;
	ClapTrap::_name = C.ClapTrap::_name;

	return (*this);
}
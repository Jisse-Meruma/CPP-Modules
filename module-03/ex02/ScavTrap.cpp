#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name)
{
	std::cout << "(ScavTrap) With Name " << name << " constructor is called!" << std::endl;
	this->_name = name;
	this->_attackdamage = 20;
	this->_energypoints = 50;
	this->_hitpoints = 100;
	this->_maxhitpoints = this->_hitpoints;
	this->_gatekeeper = false;
}

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	std::cout << "(ScavTrap) Default constructor is called!" << std::endl;
	this->_name = "NO NAME";
	this->_attackdamage = 20;
	this->_energypoints = 50;
	this->_hitpoints = 100;
	this->_maxhitpoints = this->_hitpoints;
	this->_gatekeeper = false;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "(ScavTrap) Default deconstructor is called!" << std::endl;
	this->_gatekeeper = false;
}

void	ScavTrap::guardGate( void )
{
	this->_gatekeeper = (this->_gatekeeper == false) ? true : false;
	if (this->_gatekeeper)
		std::cout << "(ScavTrap) GateKeeper Mode! Enabled" << std::endl;
	else
		std::cout << "(ScavTrap) GateKeeper Mode! Disabled" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->CanDoAction())
		return ;
	std::cout << "ScavTrap " << this->_name << " Attacks " << target << ", " << "causing " << this->_attackdamage << " points of damage!" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &C)
{
	this->_name = C._name;
	this->_attackdamage = C._attackdamage;
	this->_energypoints = C._energypoints;
	this->_hitpoints = C._hitpoints;
	this->_maxhitpoints = C._maxhitpoints;
	this->_gatekeeper = C._gatekeeper;

	return (*this);
}
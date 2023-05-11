#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name) : _name(name)
{
	std::cout << "Name constructor is called!" << std::endl;
	this->_attackdamage = 0;
	this->_energypoints = 10;
	this->_hitpoints = 10;
	this->_maxhitpoints = this->_hitpoints;
}

ClapTrap::ClapTrap(void)
{
	std::cout << "Default constructor is called!" << std::endl;
	this->_name = "NO NAME";
	this->_attackdamage = 0;
	this->_energypoints = 10;
	this->_hitpoints = 10;
	this->_maxhitpoints = this->_hitpoints;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << " Deconstructor called!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energypoints > 0 && this->_hitpoints > 0)
	{
		std::cout << "Health regenerated " << amount << std::endl;
		if (this->_hitpoints + amount > (unsigned int)this->_maxhitpoints)
			this->_hitpoints = this->_maxhitpoints;
		else
			this->_hitpoints += amount;
		return ;
	}
	std::cout << "Cannot be Repaired!!!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->_name << " Took " << amount << " Damage" << std::endl;
	this->_hitpoints -= amount;

}

void	ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << this->_name << " Attacks " << target << ", " << "causing " << this->_attackdamage << " points of damage!" << std::endl;
}
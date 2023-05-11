#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Trap("Jack");

	Trap.attack("Cheese");
	Trap.takeDamage(3);
	Trap.beRepaired(10);
}
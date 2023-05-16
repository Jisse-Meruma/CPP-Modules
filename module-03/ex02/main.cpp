#include "FragTrap.hpp"

int main(void)
{
	ClapTrap Clap("Jack");

	ScavTrap Scav("Jones!");

	FragTrap Frag("Jeffery");

	Clap.attack("Cheese");
	Clap.takeDamage(3);
	Clap.beRepaired(10);

	Scav.attack("MIEP");
	Scav.takeDamage(3);
	Scav.beRepaired(10);
	Scav.guardGate();
	Scav.guardGate();
	Scav.guardGate();

	Frag.attack("LOL");
	Frag.takeDamage(12);
	Frag.highFivesGuys();
	Frag.beRepaired(23);
}
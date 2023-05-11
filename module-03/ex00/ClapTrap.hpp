#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(const std::string &name);
		ClapTrap(void);
		~ClapTrap(void);

		void attack(const std::string& target);
	 	void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string _name;
		int _maxhitpoints;
		int _hitpoints;
		int _energypoints;
		int _attackdamage;

};


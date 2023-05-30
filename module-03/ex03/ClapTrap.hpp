#include <iostream>

// Base Class (Parent)
class ClapTrap
{
	public:
		ClapTrap(const std::string &name);
		ClapTrap(void);
		~ClapTrap(void);

		ClapTrap	&operator=(const ClapTrap &C);
		
		void attack(const std::string& target);
	 	void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		bool CanDoAction( void );

	protected:
		std::string _name;
		int _maxhitpoints;
		int _hitpoints;
		int _energypoints;
		int _attackdamage;

};


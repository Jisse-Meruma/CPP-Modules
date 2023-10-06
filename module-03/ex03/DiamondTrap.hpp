#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap( void );
		DiamondTrap( const std::string &name );

		~DiamondTrap( void );

		DiamondTrap	&operator=(const DiamondTrap &C);

		void	attack(const std::string &target);
		void	whoAmI( void );

	private:
		std::string _name;
};
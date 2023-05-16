#include "ScavTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap( void );
		FragTrap( const std::string &name );

		~FragTrap( void );

		FragTrap	&operator=(const FragTrap &C);

		int		getHitpoints( void );
		int		getAttackDamage( void );
		void	attack( const std::string &target );

		void	highFivesGuys( void );
};
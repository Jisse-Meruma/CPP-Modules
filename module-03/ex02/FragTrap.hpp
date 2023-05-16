#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap( void );
		FragTrap( const std::string &name );

		~FragTrap( void );

		FragTrap	&operator=(const FragTrap &C);

		void	attack( const std::string &target );


		void	highFivesGuys( void );
};
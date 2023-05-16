#include "ClapTrap.hpp"

//Derived class (child)
class ScavTrap : public ClapTrap
{
	public:
		ScavTrap( void );
		ScavTrap( const std::string &name );

		~ScavTrap( void );

		ScavTrap	&operator=(const ScavTrap &C);
		
		void	attack( const std::string &target );

		void	guardGate( void );
	private:
		bool _gatekeeper;
};
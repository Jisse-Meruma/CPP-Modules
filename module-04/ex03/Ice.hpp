#ifndef ICE_HPP
# define ICE_HPP
# include <iostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice& C);
		~Ice(void);

		Ice &operator=(const Ice& C);
		AMateria *clone( void ) const;
};

#endif
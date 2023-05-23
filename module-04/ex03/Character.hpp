#ifndef CHARACTAR_HPP
# define CHARACTAR_HPP
# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character: public ICharacter
{
	public:
		Character( void );
		Character( const Character &C);
		~Character( void );

	private:
		AMateria *_invetory[4];
};

#endif
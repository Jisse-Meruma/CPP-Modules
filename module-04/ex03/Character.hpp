#ifndef CHARACTAR_HPP
# define CHARACTAR_HPP
# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
	public:
		Character( void );
		Character( const Character &C);
		Character( const std::string &name);
		~Character( void );

		Character &operator=(const Character& C);

		std::string const & getName( void ) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);


	protected:
		std::string _name;
		AMateria *_invetory[4];
		AMateria *_floor[100];
};

#endif
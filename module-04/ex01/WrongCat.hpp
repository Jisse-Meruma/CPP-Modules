#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include <iostream>
# include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat& C);
		~WrongCat(void);

		WrongCat &operator=(const WrongCat& C);

		void makeSound( void ) const;
		const std::string	&getType(void) const;
};

#endif
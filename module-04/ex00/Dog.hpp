#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
class Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog& C);
		~Dog(void);

		Dog &operator=(const Dog& C);

		void makeSound( void ) const;
		const std::string	&getType(void) const;
};

#endif
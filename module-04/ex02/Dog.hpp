#ifndef DOG_HPP
# define DOG_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"
class Dog : public AAnimal
{
	public:
		Dog(void);
		Dog(const Dog& C);
		~Dog(void);

		Dog &operator=(const Dog& C);

		void makeSound( void ) const;
		const std::string	&getType(void) const;

	private:
		Brain	*_brain;
};

#endif
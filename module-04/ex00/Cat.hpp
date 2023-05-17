#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat& C);
		~Cat(void);

		Cat &operator=(const Cat& C);

		void makeSound( void ) const;
		const std::string	&getType(void) const;
};

#endif
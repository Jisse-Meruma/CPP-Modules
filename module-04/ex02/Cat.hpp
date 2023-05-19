#ifndef CAT_HPP
# define CAT_HPP
# include "AAnimal.hpp"
# include "Brain.hpp"
class Cat : public AAnimal
{
	public:
		Cat(void);
		Cat(const Cat& C);
		~Cat(void);

		Cat &operator=(const Cat& C);

		void makeSound( void ) const;
		const std::string	&getType(void) const;

	private:
		Brain	*_brain;
};

#endif
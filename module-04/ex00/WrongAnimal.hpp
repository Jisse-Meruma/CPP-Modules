#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP
# include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal& C);
		~WrongAnimal(void);

		WrongAnimal &operator=(const WrongAnimal& C);

		void makeSound(void) const;
		const std::string	&getType(void) const;

	protected:
		std::string _type;
};

#endif
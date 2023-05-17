#ifndef Animal_HPP
# define Animal_HPP
# include <iostream>

class Animal
{
	protected:
		Animal(void);
		Animal(const Animal& C);

	public:
		virtual ~Animal(void);
		Animal &operator=(const Animal& C);

		virtual void makeSound(void) const;
		const std::string	&getType(void) const;
	protected:
		std::string _type;
};

#endif
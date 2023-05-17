#ifndef Animal_HPP
# define Animal_HPP
# include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(const Animal& C);
		~Animal(void);

		Animal &operator=(const Animal& C);

		virtual void makeSound(void) const;
		const std::string	&getType(void) const;
	protected:
		std::string _type;
};

#endif
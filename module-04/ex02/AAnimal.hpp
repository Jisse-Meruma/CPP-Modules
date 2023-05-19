#ifndef AAnimal_HPP
# define AAnimal_HPP
# include <iostream>

class AAnimal
{
	protected:
		AAnimal(void);
		AAnimal(const AAnimal& C);

	public:
		virtual ~AAnimal(void);
		AAnimal &operator=(const AAnimal& C);

		virtual void makeSound(void) const;
		const std::string	&getType(void) const;
	protected:
		std::string _type;
};

#endif
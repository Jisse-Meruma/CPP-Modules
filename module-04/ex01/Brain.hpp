#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain& C);
		~Brain(void);

		Brain &operator=(const Brain& C);

	protected:
		std::string _ideas[100];
};

#endif
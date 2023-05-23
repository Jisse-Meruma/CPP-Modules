#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(const Cure& C);
		~Cure(void);

		Cure &operator=(const Cure& C);

		AMateria *clone( void ) const;
};

#endif
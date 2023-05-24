#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <iostream>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& C);
		~MateriaSource(void);

		MateriaSource &operator=(const MateriaSource& C);

		AMateria* createMateria(std::string const & type);
		void learnMateria(AMateria* m);

	private:
		AMateria *_Mlist[4];
};

#endif
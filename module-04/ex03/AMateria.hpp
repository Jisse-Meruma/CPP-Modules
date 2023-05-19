#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>

class AMateria
{
	protected:
		AMateria(void);
		AMateria(const AMateria& C);

		std::string _type;

	public:
		virtual ~AMateria(void);
		AMateria(std::string const & type);

		std::string const & getType( void ) const; //Returns the materia type

		virtual AMateria* clone( void ) const = 0;
		virtual void use(ICharacter& target);

		AMateria &operator=(const AMateria& C); 


};

#endif
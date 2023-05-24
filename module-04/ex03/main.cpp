#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	MateriaSource* test1 = new MateriaSource();
	MateriaSource* test2 = new MateriaSource();

	test1->learnMateria(new Ice());
	std::cout << "Ice ice !!!" << std::endl;

	*test2 = *test1;

	test1->createMateria("fsfdsf");
	test1->createMateria("ice");

	test2->createMateria("fsdfdsf");
	test2->createMateria("ice");

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	system("leaks Materia");
	return 0;
}
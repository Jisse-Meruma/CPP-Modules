#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	// const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	const Animal* copy = new Cat(*((Cat *)j));

	delete j;
	delete i;
	delete copy;
	system("leaks dog");

	Animal *Animals[100];

	for (int i = 0; i < 50; i++)
		Animals[i] = new Dog();
	for (int i = 50; i < 100; i++)
		Animals[i] = new Cat();
	for (int i = 0; i < 100; i++)
		delete Animals[i];
	system("leaks dog");

	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_i = new WrongCat();

	std::cout << wrong_i->getType() << " " << std::endl;
	wrong_i->makeSound(); //will output the Animal sound!
	wrong_meta->makeSound(); //will output the Animal sound!
	return (0);
}
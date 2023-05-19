#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	// const AAnimal* meta = new AAnimal();
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	const AAnimal* copy = new Cat(*((Cat *)j));

	delete j;
	delete i;
	delete copy;
	system("leaks dog");

	AAnimal *AAnimals[100];

	for (int i = 0; i < 50; i++)
		AAnimals[i] = new Dog();
	for (int i = 50; i < 100; i++)
		AAnimals[i] = new Cat();
	for (int i = 0; i < 100; i++)
		delete AAnimals[i];
	system("leaks dog");

	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_i = new WrongCat();

	std::cout << wrong_i->getType() << " " << std::endl;
	wrong_i->makeSound(); //will output the AAnimal sound!
	wrong_meta->makeSound(); //will output the AAnimal sound!
	return (0);
}
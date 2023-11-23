#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <stdlib.h>

Base	*generate(void)
{
	int numb;

	std::srand(time(0));
	numb = 1 + (std::rand() % 3);

	if (numb == 1)
	{
		std::cout << "Created A!" << std::endl;
		return (new A);
	}
	if (numb == 2)
	{
		std::cout << "Created B!" << std::endl;
		return (new B);
	}
	if (numb == 3)
	{
		std::cout << "Created C!" << std::endl;
		return (new C);
	}
	std::cout << "Created A!" << std::endl;
	return (new A);
}

void	identify(Base* p)
{
	A *a;
	B *b;
	C *c;

	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);

	if (a != NULL)
		std::cout << "The Type === A" << std::endl;
	else if (b != NULL)
		std::cout << "The Type === B" << std::endl;
	else if (c != NULL)
		std::cout << "The Type === C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A a;
		a = dynamic_cast<A&>(p);
		std::cout << "The Type === A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		B b;
		b = dynamic_cast<B&>(p);
		std::cout << "The Type === B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		C c;
		c = dynamic_cast<C&>(p);
		std::cout << "The Type === C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main()
{	
	Base * point;

	point = generate();

	identify(point);
	identify(*point);

	delete point;
}
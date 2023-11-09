#include "whatever.hpp"

int	main()
{
	int int_one = 1;
	int int_two = 100;

	std::cout << "smallest object = (" << min(int_one, int_two) << ')' << std::endl; 
	std::cout << "biggest object = (" << max(int_one, int_two) << ')' << std::endl << std::endl;

	swap<int>(int_one, int_two);
	std::cout << int_one << " " << int_two << std::endl << std::endl;

	char char_one = 'a';
	char char_two = '@';

	std::cout << "smallest object = (" << min(char_one, char_two) << ')' << std::endl; 
	std::cout << "biggest object = (" << max(char_one, char_two) << ')' << std::endl << std::endl;

	std::cout << "smallest object(int) = (" << min<int>(char_one, char_two) << ')' << std::endl; 
	std::cout << "biggest object(int) = (" << max<int>(char_one, char_two) << ')' << std::endl << std::endl;

	swap<char>(char_one, char_two);
	std::cout << char_one << " " << char_two << std::endl << std::endl;


	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	//The dots are nessesary to make sure you overload the function correctly!!!!
	//For example,,,, string already has a min/max function.. so by adding the ::min/::max before your function make sure you wnat your defined function!
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

}
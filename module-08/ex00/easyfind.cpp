#include "easyfind.hpp"

const char *NotFoundException::what(void) const throw()
{
	return ("Integer Not Found in Container :(");
}
#include <algorithm>

class NotFoundException : public std::exception 
{
	virtual const char * what() const throw();
};

template <typename T>
typename T::iterator easyfind(T obj, int integer)
{
	
	typename T::iterator it;

	it = std::find(obj.begin(), obj.end(), integer);

	if (it == obj.end())
		throw NotFoundException();
	return (it);
}
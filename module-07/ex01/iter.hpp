#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
# include <string>

template <typename T>
void print(T &obj)
{
	std::cout << obj << std::endl;
}

template <typename T, typename F>
void iter(T *array, size_t size, F f)
{
	for (size_t i=0; i < size; i++)
		f(array[i]);
}

#endif
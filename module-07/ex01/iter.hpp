#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>
# include <string>

template <typename T>
void iter(T *array, size_t size, void (*t_func)(T&))
{
	for (size_t i=0; i < size; i++)
		t_func(array[i]);

}

template <typename T>
void print(T &obj)
{
	std::cout << obj << std::endl;
}

#endif
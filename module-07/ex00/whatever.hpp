#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>
# include <string>

template <typename T>
void swap(T &obj_one, T &obj_two)
{
	T temp = obj_one;

	obj_one = obj_two;
	obj_two = temp;
}

template <typename T>
T min(T obj_one, T obj_two)
{
	return ( (obj_one < obj_two) ? obj_one : obj_two );;
}

template <typename T>
T max(T obj_one, T obj_two)
{
	return ( (obj_one > obj_two) ? obj_one : obj_two );
}

#endif
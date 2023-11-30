#include "Span.hpp"
#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> vec;
	vec.push_back(100);
	vec.push_back(1);
	vec.push_back(88);
	vec.push_back(1111111);
	vec.push_back(55);
	vec.push_back(-2147483647);
	vec.push_back(-2147483648);
	Span s(vec.size());
	s.AddRange(vec.begin(), vec.end());
	std::cout << "short " << s.shortestSpan() << std::endl;
	std::cout << "long " << s.longestSpan() << std::endl;
}
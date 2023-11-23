#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};

    try
    {
      std::cout << *easyfind(vec, 2) << std::endl;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }

}
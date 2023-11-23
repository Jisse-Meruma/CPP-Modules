#include "iter.hpp"

void    add(int &a)
{
    a += 1;
}

void    subtract(float &a)
{
    a += 1;
}

int main( void ) {
    
    {
        int arr[3] = {5, -1, 10};
        std::cout << "Int array:" << std::endl;
        iter(arr, 3, print<int &>);
        iter(arr, 3, add);
        std::cout << "Int array after iter():" << std::endl;
        iter(arr, 3, print<int &>);
    }
    {
        float arr[3] = {5.4, -1, 10};
        std::cout << "Float array:" << std::endl;
        iter(arr, 3, print<float &>);
        iter(arr, 3, subtract);
        std::cout << "Int array after iter():" << std::endl;
        iter(arr, 3, print<float &>);
    }
    {
        std::string arr[4] = {"hallo", "everyone", "Template", "confused"};
        std::cout << "String array printed with iter:" << std::endl;
        iter(arr, 4, print<std::string &>);
    }
    return 0;
}
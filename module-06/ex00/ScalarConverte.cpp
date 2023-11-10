#include "ScalarConverte.hpp"
#include <string>
#include <sstream>
#include <limits>
#include <cstdio>
#include <iostream>
#include <iomanip>
 
#define INT 0
#define DOUBLE 1
#define FLOAT 2

// Constructors and Destructor
// ScalarConverte::ScalarConverte() {
//     std::cout << "ScalarConverte default Constructor called" << std::endl;
//     this->name = "ScalarConverte";
// }

// ScalarConverte::ScalarConverte(std::string n) {
//     std::cout << "ScalarConverte Constructor called" << std::endl;
//     this->name = n;
// }

// ScalarConverte::~ScalarConverte() {
//     std::cout << "ScalarConverte Destructor called" << std::endl;
// }

// Canonical form
// ScalarConverte &ScalarConverte::operator=(const ScalarConverte &obj) {
//     //copy depending on vars;
//     return *this;
// }

// ScalarConverte::ScalarConverte(const ScalarConverte &obj) {
//     *this = obj;
// }

int     is_valid_digit(const std::string &input, const char *str, int *type)
{
    size_t i = 0;

    while(isdigit(str[i]) && str[i])
        i++;
    if (str[i] == '.' && isdigit(str[i + 1]))
    {
        i++;
        *type = DOUBLE;
    }
    while(isdigit(str[i]) && str[i])
        i++;
    if (str[i] == 'f')
    {
        i++;
        *type = FLOAT;
    }
    if (input.length() == i)
        return (1);
    std::cerr << "Not a Valid Digit!" << std::endl;
    return (0);
}

bool    int_overflow(long double number)
{
    if (number < std::numeric_limits<int>::max() && number > std::numeric_limits<int>::min())
        return (true);
    return (false);
}

bool    float_overflow(long double number)
{
    if (number < std::numeric_limits<double>::max() && number > std::numeric_limits<double>::min())
        return (true);
    return (false);
}

bool    double_overflow(long double number)
{
    if (number < std::numeric_limits<float>::max() && number > std::numeric_limits<float>::min())
        return (true);
    return (false);
}

void    ft_print_char(char charactar)
{
    std::cout << "Char: " << charactar << std::endl;
    std::cout << "Int: " << static_cast<int>(charactar) << std::endl;
    std::cout << "Float: " << static_cast<float>(charactar) << std::endl;
    std::cout << "Double: " << static_cast<double>(charactar) << std::endl;
}

void    ft_print_int(long double number)
{
    if (int_overflow(number))
    {
        if (!isprint(number))
            std::cout << "Char: " << static_cast<char>(number) << std::endl;
        else
            std::cout << "Non Displayable" << std::endl;
        std::cout << "Int: " << static_cast<int>(number) << std::endl;
    }
    else
    {
        std::cout << "Char: Impossible" << std::endl;
        std::cout << "Int: Impossible" << std::endl;
    }
    if (float_overflow(number))
        std::cout << "Float: " << static_cast<float>(number) << 'f' << std::endl;
    else
        std::cout << "Float Impossible" << std::endl;
    if (double_overflow(number))
        std::cout << "Double: " << static_cast<double>(number) << std::endl;
    else
        std::cout << "Double Impossible" << std::endl;
}


void    ScalarConverte::convert(const std::string &input)
{
    long double number;
    int         type = INT;
    const char  *str = input.c_str();

    if (input.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
    {
        ft_print_char(str[0]);
    }
    if (!is_valid_digit(input, str, &type))
    {
        return ;
    }
    sscanf(str, "%Lf", &number);
    ft_print_int(number);

}

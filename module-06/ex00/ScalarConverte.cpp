#include "ScalarConverte.hpp"
#include <string>
#include <sstream>
#include <limits>
#include <cstdio>
#include <iostream>
#include <iomanip>

ScalarConverte::ScalarConverte() {
    std::cout << "ScalarConverte default Constructor called" << std::endl;
}

ScalarConverte::ScalarConverte(std::string n) {
    (void)n;
    std::cout << "ScalarConverte Constructor called" << std::endl;
}

ScalarConverte::~ScalarConverte() {
    std::cout << "ScalarConverte Destructor called" << std::endl;
}


ScalarConverte &ScalarConverte::operator=(const ScalarConverte &obj) {
    (void)obj;
    return *this;
}

ScalarConverte::ScalarConverte(const ScalarConverte &obj) {
    *this = obj;
}



t_type    is_valid_digit(const std::string &input, const char *str)
{
    t_type type = NO_TYPE;
    size_t i = 0;

    if (input.length() == 1 && !isdigit(str[0]))
        return (CHAR);
    if ()
    while(isdigit(str[i]) && str[i])
        i++;
    if (str[i] == '.' && isdigit(str[i + 1]))
    {
        i++; 
        type = DOUBLE;
    }
    while(isdigit(str[i]) && str[i])
        i++;
    if (str[i] == 'f')
    {
        i++;
        type = FLOAT;
    }
    if (input.length() == i)
    {
        if (type == NO_TYPE)
            return (INT);
        return (type);
    }
    std::cerr << "Not a Valid Digit!" << std::endl;
    return (NO_TYPE);
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

void    convert_int(const std::string &input)
{
    int number;

    try
    {
        number = std::stoi(input);
    }
    catch(const std::out_of_range & e)
    {
        std::cerr << e.what() << '\n';
    }
    
    (void)number;


}

void    convert_float(const std::string &input)
{
    (void)input;
}

void    convert_double(const std::string &input)
{
    (void)input;
}


void    ScalarConverte::convert(const std::string &input)
{
    t_type type;
    const char  *str = input.c_str();
    
    type = is_valid_digit(input, str);
    convert_int(input);
    (void)type;

}

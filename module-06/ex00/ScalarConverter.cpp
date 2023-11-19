#include "ScalarConverter.hpp"
#include <string>
#include <sstream>
#include <limits>
#include <cstdio>
#include <iostream>
#include <iomanip>


void    impossible(const char *type)
{
    std::cout << type << " Impossible" << std::endl;
}

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverte default Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(std::string n) {
    (void)n;
    std::cout << "ScalarConverte Constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverte Destructor called" << std::endl;
}


ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj) {
    (void)obj;
    return *this;
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) {
    *this = obj;
}



t_type    is_valid_digit(const std::string &input, const char *str)
{
    t_type type = NO_TYPE;
    size_t i = 0;

    if (input.length() == 1 && !isdigit(str[0]))
        return (CHAR);
    if (str[i] == '-' || str[i] == '+')
        i++;
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

void    convert_char(char charactar)
{
    std::cout << "Char: " << charactar << std::endl;
    std::cout << "Int: " << static_cast<int>(charactar) << std::endl;
    std::cout << "Double: "<< std::fixed << std::setprecision(1) << static_cast<double>(charactar) << std::endl;
    std::cout << "Float: " << static_cast<float>(charactar) << "f" << std::endl;
}

void    convert_int(const std::string &input)
{
    t_type type = SUCCESs;
    int number = 0;

    try
    {
       number = std::stoi(input);
    }
    catch(const std::out_of_range & e)
    {
        type = FAIL;   
    }
    if(type == SUCCESs)
    {
        if (number <= 126 && number >= 32)
            std::cout << "Char: " << static_cast<char>(number) << std::endl;
        else
            std::cout << "Char: Non displayable" << std::endl;
        std::cout << "Int: " << number << std::endl;
        std::cout << "Double: " << std::fixed << std::setprecision(1) << static_cast<double>(number) << std::endl;
        std::cout << "Float: " << static_cast<float>(number) << "f" << std::endl; 
    }
    else
    {
        impossible("Char:");
        impossible("Int:");
        impossible("Double:");
        impossible("Float:");
    }

}

void    convert_float(const std::string &input)
{
    t_type type = SUCCESs;
    float number = 0;

    try
    {
       number = std::stof(input);
    }
    catch(const std::out_of_range & e)
    {
        type = FAIL;   
    }
    if(type == SUCCESs)
    {
        if (number <= 126 && number >= 32)
            std::cout << "Char: " << static_cast<char>(number) << std::endl;
        else
            std::cout << "Char: Non displayable" << std::endl;
		if (number < std::numeric_limits<int>::max() && static_cast<int>(number) > std::numeric_limits<int>::min())
       		std::cout << "Int: " << static_cast<int>(number) << std::endl;
		else
			impossible("Int:");
		if (number < std::numeric_limits<double>::max() && static_cast<int>(number) > std::numeric_limits<double>::min())
        	std::cout << "Double: " << static_cast<double>(number) << std::endl;
		else
			impossible("Double:");
        std::cout << "Float: " << number << "f" << std::endl; 
    }
    else
    {
        impossible("Char:");
        impossible("Int:");
        impossible("Double:");
        impossible("Float:");
    }
}

void    convert_double(const std::string &input)
{
    t_type type = SUCCESs;
    double number = 0;

    try
    {
       number = std::stod(input);
    }
    catch(const std::out_of_range & e)
    {
        type = FAIL;   
    }
    if(type == SUCCESs)
    {
        if (number <= 126 && number >= 32)
            std::cout << "Char: " << static_cast<char>(number) << std::endl;
        else
            std::cout << "Char: Non displayable" << std::endl;
		if (number < std::numeric_limits<int>::max() && static_cast<int>(number) > std::numeric_limits<int>::min())
       		std::cout << "Int: " << static_cast<int>(number) << std::endl;
		else
			impossible("Int:");
        std::cout << "Double: " << number << std::endl;
		if  (number < std::numeric_limits<float>::max() && static_cast<int>(number) > std::numeric_limits<float>::min())
        	std::cout << "Float: " << static_cast<float>(number) << "f" << std::endl;
		else
			impossible("Float:");
    }
    else
    {
        impossible("Char:");
        impossible("Int:");
        impossible("Double:");
        impossible("Float:");
    }
}


void    ScalarConverter::convert(const std::string &input)
{
    t_type type;
    const char  *str = input.c_str();
    
    type = is_valid_digit(input, str);
    switch (type) 
    {
        case CHAR:
        convert_char(str[0]);
        break;

        case INT:
        convert_int(input);
        break;

        case FLOAT:
		convert_float(input);
        break;

        case DOUBLE:
		convert_double(input);
        break;

        default:
        std::cout << "Invalid Literal Has beeg given!!" << std::endl;
    }
}

#ifndef SCALARCONVERTE_HPP
#define SCALARCONVERTE_HPP

#include <iostream>
#include <string>

typedef enum
{
    NO_TYPE,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SUCCESs,
    FAIL,
}   t_type;

class ScalarConverter {
    public:
        static void convert(const std::string &input);
    private:
        ScalarConverter();
        ScalarConverter(std::string n);
        ScalarConverter(const ScalarConverter &obj);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &obj);
};

typedef void (*t_func)(const std::string &);

#endif

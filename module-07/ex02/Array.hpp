#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array {
public:

    class IndexOutOfBoundsException : public std::exception {
        public:
            virtual const char *what() const throw();
    };


    Array();
    Array(unsigned int num);
    ~Array();

    // Copy constructor
    Array(const Array &obj);
    // Operator overload
    Array &operator=(const Array &obj);
    T     &operator[](unsigned int index);

    unsigned int size(void) const;

private:
    T               *_arr;
    unsigned int    _size;
};

# include "Array.tpp"

#endif

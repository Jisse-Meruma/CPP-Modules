#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>
#include <deque>


template <typename T, class Container = std::deque<T>>
class MutantStack: public std::stack<T, Container> 
{
    public:
        MutantStack() 
        {
            std::cout << "Mutantstack default Constructor called" << std::endl;
        };
        ~MutantStack() {};

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    iterator begin(void)
    {
        return  this->c.begin();
    }

    iterator end(void)
    {
        return this->c.end();
    }

    reverse_iterator rbegin(void)
    {
        return this->c.rbegin();
    }

    reverse_iterator rend(void)
    {
        return this->c.rend();
    }

    const const_iterator cbegin(void) const
    {
        return this->c.cbegin();
    }

    const const_iterator cend(void) const
    {
        return this->c.cend();
    }

    const const_reverse_iterator crend(void) const
    {
        return this->c.crend();
    }

    const const_reverse_iterator crbegin(void) const
    {
        return this->c.crbegin();
    }
};

#endif

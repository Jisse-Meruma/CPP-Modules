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

    const const_iterator begin(void) const
    {
        return this->c.begin();
    }

    const const_iterator end(void) const
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

    const const_reverse_iterator rend(void)
    {
        return this->rend();
    }

    const const_reverse_iterator rbegin(void)
    {
        return this->rbegin();
    }


};

#endif

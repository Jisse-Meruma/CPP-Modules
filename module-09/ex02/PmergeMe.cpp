#include "PmergeMe.hpp"

// Constructors and Destructor
PmergeMe::PmergeMe() {
    std::cout << "PmergeMe default Constructor called" << std::endl;
}

PmergeMe::PmergeMe(char *argv[]) 
{    
    std::string numb;
    int integer;
    std::cout << "PmergeMe Constructor called" << std::endl;
    for (int i=0; argv[i] != NULL; i++)
    {
        if (!this->IsValidNumber(argv[i]))
            throw std::logic_error("Invalid Number Error");
        numb = argv[i];
        try
        {
            integer = std::stoi(numb);
            this->_vec.push_back(integer);
            this->_deq.push_back(integer);
        }
        catch(const std::exception& e)
        {
            throw std::overflow_error("Overflow Error");
        }
    }
    this->PrintArray(this->_vec);
}

PmergeMe::~PmergeMe() {
    std::cout << "PmergeMe Destructor called" << std::endl;
}

// Canonical form
PmergeMe &PmergeMe::operator=(const PmergeMe &obj) {
    this->_deq = obj._deq;
    this->_vec = obj._vec;
    return *this;
}

PmergeMe::PmergeMe(const PmergeMe &obj) {
    *this = obj;
}

bool PmergeMe::IsValidNumber(char *numb)
{
    int i;

    i = 0;
    if (numb[0] == '+')
        i++;
    while (numb[i] != '\0')
    {
        if (!std::isdigit(numb[i]))
            return (false);
        i++;
    }
    return (true);
}

template<typename T>
void PmergeMe::PrintArray(T array)
{
    int counter;

    counter = 0;
    for (auto it = array.begin(); it != array.end(); it++)
    {
        if (counter == 5)
        {
            std::cout << "[...]";
            break;
        }
        std::cout << *it << " ";
        counter++;
    }
    std::cout << std::endl;
}

void PmergeMe::sort(void)
{
    std::cout << "Before:\t";
    PrintArray(this->_vec);


}

void PmergeMe::sort_vector(void)
{
    std::vector<std::pair<int, int>> pair_array;
}

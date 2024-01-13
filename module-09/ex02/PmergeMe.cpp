#include "PmergeMe.hpp"

// Constructors and Destructor
PmergeMe::PmergeMe()
{
    std::cout << "PmergeMe default Constructor called" << std::endl;
}

PmergeMe::PmergeMe(char *argv[])
{
    std::string numb;
    int integer;
    for (int i = 0; argv[i] != NULL; i++)
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
        catch (const std::exception &e)
        {
            throw std::overflow_error("Overflow Error");
        }
    }
    // this->checkForDuplicates();
}

PmergeMe::~PmergeMe()
{
}

// Canonical form
PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
    this->_deq = obj._deq;
    this->_vec = obj._vec;
    return *this;
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
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

template <typename T>
void PmergeMe::PrintArray(T array)
{
    int counter;

    counter = 0;
    for (auto it = array.begin(); it != array.end(); it++)
    {
        // if (counter == 5)
        // {
        //     std::cout << "[...]";
        //     break;
        // }
        std::cout << *it << " ";
        counter++;
    }
    std::cout << std::endl;
}

template <typename T>
T PmergeMe::JacobBuilder(int size)
{
    int temp;
    int current = 1;
    int previous = 1;
    T jacob_sequence;

    jacob_sequence.push_back(0);
    while (current < size)
    {
        jacob_sequence.push_back(current);
        temp = previous;
        previous = current;
        current = (2 * temp) + previous;
    }
    return (jacob_sequence);
}

void PmergeMe::sort(void)
{
    std::cout << "Before:\t";
    PrintArray(this->_vec);
    this->sort_vector();
    this->sort_deque();
    std::cout << "After:\t";
    PrintArray(this->_deq);
    std::cout << "Time to process a range of " << this->_vec.size() << " elements with std::vector : " << (this->_vectime / 10000) << " us\n";
    std::cout << "Time to process a range of " << this->_deq.size() << " elements with std::deque  : " << (this->_dequetime / 10000) << " us\n";
}

template <typename T, typename T2>
int PmergeMe::ParsePairArray(T array, T2 &pair_array)
{
    auto arr_it = array.begin();

    for (auto pair_it = pair_array.begin(); pair_it != pair_array.end(); pair_it++)
    {
        pair_it->first = *arr_it;
        arr_it++;
        pair_it->second = *arr_it;
        if (pair_it->first < pair_it->second)
            std::swap(pair_it->first, pair_it->second);
        arr_it++;
    }
    if (arr_it != array.end())
        return (*arr_it);
    return (-1);
}

template <typename T>
void PmergeMe::MergeSort(T it_begin, T it_end, std::ptrdiff_t distance)
{
    std::vector<std::pair<int, int>> pair_array;
    auto left_begin = it_begin;
    auto left_end = it_end - ((distance / 2));
    T right_begin;
    auto right_end = it_end;

    right_begin = it_begin + ((distance / 2));
    if (distance % 2 != 0)
        left_end--;
    while (left_begin != left_end + 1 && right_begin != right_end + 1)
    {
        if (left_begin->first <= right_begin->first)
        {
            pair_array.push_back(std::make_pair(left_begin->first, left_begin->second));
            left_begin++;
        }
        else
        {
            pair_array.push_back(std::make_pair(right_begin->first, right_begin->second));
            right_begin++;
        }
    }
    for (auto left = left_begin; left != left_end + 1; left++)
        pair_array.push_back(std::make_pair(left->first, left->second));
    for (auto right = right_begin; right != right_end + 1; right++)
        pair_array.push_back(std::make_pair(right->first, right->second));
    std::copy(pair_array.begin(), pair_array.end(), it_begin);
}

template <typename T>
void PmergeMe::BigSort(T it_begin, T it_end)
{
    std::ptrdiff_t distance;

    distance = std::distance(it_begin, it_end) + 1;
    if (it_begin == it_end)
        return;
    BigSort(it_begin, it_end - (distance / 2));
    BigSort(it_begin + ((distance / 2)), it_end);
    return (this->MergeSort(it_begin, it_end, distance));
}

template <typename T, typename T2>
void PmergeMe::SmallSort(T pair_array, T2 &array, int struggler)
{
    T2 sorted_array;
    T2 jacob_array;

    auto p_it = pair_array.begin();
    jacob_array = this->JacobBuilder<T2>(pair_array.size());
    for (auto pair_it = pair_array.begin(); pair_it != pair_array.end(); pair_it++)
        sorted_array.push_back(pair_it->first);
    for (auto jacob_it = jacob_array.begin(); jacob_it != jacob_array.end(); jacob_it++)
    {
        auto it = std::lower_bound(sorted_array.begin(), sorted_array.end(), (p_it + *(jacob_it))->second);
        sorted_array.insert(it, (p_it + *(jacob_it))->second);
        pair_array.erase(p_it + *(jacob_it));
    }
    for (auto pair_it = pair_array.rbegin(); pair_it != pair_array.rend(); pair_it++)
    {
        auto it = std::lower_bound(sorted_array.begin(), sorted_array.end(), pair_it->second);
        sorted_array.insert(it, pair_it->second);
    }
    
    if (struggler != -1)
    {
        auto it = std::lower_bound(sorted_array.begin(), sorted_array.end(), struggler);
        sorted_array.insert(it, struggler);
    }
    std::copy(sorted_array.begin(), sorted_array.end(), array.begin());
}

void PmergeMe::sort_vector(void)
{
    int struggler;
    std::vector<std::pair<int, int>> pair_array;
    std::chrono::high_resolution_clock::time_point start_timer = std::chrono::high_resolution_clock::now();

    pair_array.resize(this->_vec.size() / 2);
    struggler = this->ParsePairArray(this->_vec, pair_array);
    this->BigSort(pair_array.begin(), pair_array.end() - 1);
    this->SmallSort(pair_array, this->_vec, struggler);
    std::chrono::high_resolution_clock::time_point end_timer = std::chrono::high_resolution_clock::now();
    this->_vectime = std::chrono::duration_cast<std::chrono::nanoseconds>(end_timer - start_timer).count();
}

void PmergeMe::sort_deque(void)
{
    int struggler;
    std::deque<std::pair<int, int>> pair_array;
    std::chrono::high_resolution_clock::time_point start_timer = std::chrono::high_resolution_clock::now();

    pair_array.resize(this->_vec.size() / 2);
    struggler = this->ParsePairArray(this->_deq, pair_array);
    this->BigSort(pair_array.begin(), pair_array.end() - 1);
    this->SmallSort(pair_array, this->_deq, struggler);
    std::chrono::high_resolution_clock::time_point end_timer = std::chrono::high_resolution_clock::now();
    this->_dequetime = std::chrono::duration_cast<std::chrono::nanoseconds>(end_timer - start_timer).count();
}
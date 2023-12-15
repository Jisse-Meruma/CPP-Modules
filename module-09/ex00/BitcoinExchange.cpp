#include "BitcoinExchange.hpp"

#define DATABASE_IDENTIFIER "Error Wrong CSV Identifiers! Please Make Sure They Are (date,exchange_rate)"
#define INPUT_IDENTIFIER "Error Wrong INPUT Identifiers! Please Make Sure They Are (date | value)"
#define MIN 0
#define MAX 1000

void BitCoinExchange::CalculateCourse(float exchange_date, float exchange_number)
{
	std::map<long, double>::iterator it;

	it = this->_map.find(exchange_date);
	if (it == this->_map.end())
	{
		it = this->_map.lower_bound(exchange_date);
		it--;
	}
	std::cout << (exchange_number * it->second) << std::endl;
}

bool BitCoinExchange::CheckDate(const std::string &line)
{
	for (int i=0; i != 10; i++)
	{
		if (i != 4 && i != 7)
		{
			if (!std::isdigit(line[i]))
				return (false);
		}
		else if (line[i] != '-')
			return (false);
	}
	return (true);
}

bool BitCoinExchange::CheckNegative(const std::string &line, int location)
{
	return (line[location] != '-');
}

bool BitCoinExchange::CheckNumber(const std::string &line, int location)
{
	int size = line.size();
	if (line[location] == '+')
		location++;
	while (std::isdigit(line[location]) && line[location])
		location++;
	if (line[location] == '.' && std::isdigit(line[location + 1]))
		location++;
	while (std::isdigit(line[location]) && line[location])
		location++;
	if (location != size)
		return (false);
	return (true);	
}

bool BitCoinExchange::CheckDelimiter(const std::string &line, int location, char delimiter)
{
	return (line[location] != delimiter);	
}

void BitCoinExchange::CheckDataBase(const std::string &line)
{
	if (line.size() < 12)
		throw std::logic_error("DataBase Error Bad Size!" + line);
	if (!this->CheckDelimiter(line, 11, ','))
		throw std::logic_error("DataBase Error Bad Delimiter" + line);
	if (!this->CheckDate(line))
		throw std::logic_error("DataBase Error Bad Date" + line);
	if (!this->CheckNegative(line, 11))
		throw std::logic_error("DataBase Error Bad Negative" + line);
	if (!this->CheckNumber(line, 11))
		throw std::logic_error("DataBase Error Bad Exchange_Number" + line);
}

static bool PrintBadError(const std::string &line, const char *reason, bool print_line)
{
	if (print_line)
		std::cout << "Error: " << reason << " => " << line << std::endl;
	else
		std::cout << "Error: " << reason << std::endl;
	return (false);
}

bool BitCoinExchange::CheckInputFile(const std::string &line)
{
	if (line.size() < 14)
		return (PrintBadError(line, "Bad Input", true));
	if (line[10] != ' ' && line[12] != ' ')
		return (PrintBadError(line, "Need Spaces", true));
	if (!this->CheckDelimiter(line, 12, '|'))
		return (PrintBadError(line, "input Error Bad Delimiter", true));
	if (!this->CheckDate(line))
		return (PrintBadError(line, "input Error Bad Date", true));
	if (!this->CheckNegative(line, 13))
		return (PrintBadError(line, "Not a positive number", false));
	if (!this->CheckNumber(line, 13))
		return (PrintBadError(line, "input Error Bad Exchange_Number ", false));
	return (true);
}



BitCoinExchange::BitCoinExchange(void)
{
	std::ifstream infile;
	infile.open("./data.csv", std::ifstream::in);
	if (infile.fail())
		throw std::runtime_error("Could not open data.csv");
	this->LoadDataBase(infile);
}



void BitCoinExchange::LoadDataBase(std::ifstream &infile)
{
	std::string	line;	
	std::string date_string;
	std::string exchange_string;

	std::getline(infile, line);
	if (line != "date,exchange_rate")
		throw std::logic_error(DATABASE_IDENTIFIER);
	while(std::getline(infile, line))
	{
		this->CheckDataBase(line);
		std::string date_string = line.substr(0, line.find_first_of(','));
		std::string exchange_string = line.substr(line.find_first_of(',') + 1);
		date_string.erase(4, 1);
		date_string.erase(6, 1);
		this->_map.insert(std::make_pair<long, double>(std::stol(date_string), std::stod(exchange_string)));
	}
}

void BitCoinExchange::LoadInputFile(const std::string &input)
{
	float exchange_number;
	std::string	line;
	std::string date_string;
	std::string exchange_string;
	std::ifstream infile;

	infile.open(input, std::ifstream::in);
	if (infile.fail())
		throw std::runtime_error("Could not open file");
	std::getline(infile, line);
	if (line != "date | value")
		throw std::logic_error(INPUT_IDENTIFIER);
	while(std::getline(infile, line))
	{
		if (!this->CheckInputFile(line))
			continue;
		std::string date_string = line.substr(0, line.find_first_of('|') - 1);
		std::string exchange_string = line.substr(line.find_first_of('|') + 2);
		exchange_number = std::stof(exchange_string);
		if (MIN < exchange_number && MAX < exchange_number)
		{
			PrintBadError(line, "too large a number", false);
			continue;
		}
		std::cout << date_string << " => " << exchange_number << " = ";
		date_string.erase(4, 1);
		date_string.erase(6, 1);
		CalculateCourse(std::stol(date_string), exchange_number);
	}
}

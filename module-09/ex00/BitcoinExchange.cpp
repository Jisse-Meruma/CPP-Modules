#include <iostream>
#include <map>
#include <fstream>

void ParseData(std::map<long, float> &map)
{
	std::string	line;
	std::ifstream infile;
	std::string date_string;
	std::string exchange_string;

	infile.open("./data.csv", std::ifstream::in);
	if (infile.fail())
		throw std::runtime_error("Could not open data.csv");
	while(std::getline(infile, line))
	{
		if (line == "date,exchange_rate")
			continue;
		std::string date_string = line.substr(0, line.find_first_of(','));
		std::string exchange_string = line.substr(line.find_first_of(',') + 1);
		date_string.erase(4, 1);
		date_string.erase(6, 1);
		map.insert(std::make_pair<long, float>(std::stol(date_string), std::stof(exchange_string)));
	}
}


void BitcoinExchagne(const std::string &input)
{
	(void)input;
	std::map<long, float> map;

	ParseData(map);
}
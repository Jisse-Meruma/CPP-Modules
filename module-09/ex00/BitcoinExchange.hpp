#ifndef BITCOINEXCHANGE_HPP
 #define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <limits>


class BitCoinExchange
{
	public:
		BitCoinExchange();
		~BitCoinExchange() {};

		void CheckDataBase(const std::string &line);
		void LoadDataBase(std::ifstream &infile);
		bool CheckDelimiter(const std::string &line, int location, char delimiter);
		bool CheckDate(const std::string &line);
		bool CheckNumber(const std::string &line, int location);
		bool CheckNegative(const std::string &line, int location);

		void LoadInputFile(const std::string &input);
		bool CheckInputFile(const std::string &line);

		void CalculateCourse(float exchange_date, float exchange);



	private:
		std::map<long, double> _map;

};



#endif
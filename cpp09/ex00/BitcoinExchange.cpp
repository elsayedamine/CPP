/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:36:02 by aelsayed          #+#    #+#             */
/*   Updated: 2025/12/31 21:44:25 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { this->database = other.database; }
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other)
		this->database = other.database;
	return *this;
}
BitcoinExchange::BitcoinExchange(const char *file)
{
	std::ifstream infile(file);
	std::string line;
	int i = 2;

	if (!infile.is_open())
		throw std::runtime_error("Error: could not open data file.\n");
	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		try {
			Data date(line, ',');
			database[date] = date.getValue();
		}
		catch (const std::exception &e) {
			std::cerr << "Error in line " << i << " : " << e.what() << std::endl; }
		i++;
	}
	infile.close();
}

std::string	strtrim(const std::string &s)
{
	size_t start = 0;
	while (start < s.size() && std::isspace((unsigned char)(s[start])))
		++start;
	size_t end = s.size();
	while (end > start && std::isspace((unsigned char)(s[end - 1])))
		--end;
	return s.substr(start, end - start);
}

void	BitcoinExchange::processInput(const char *file) const
{
	std::ifstream input(file);
	std::string line;

	if (!input.is_open())
		throw std::runtime_error("Error: could not open data file.\n");
	std::getline(input, line);
	while (std::getline(input, line))
	{
		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue; }

		try
		{
			Data queryDate(line, '|'); 

			double inputVal = queryDate.getValue();
			if (inputVal < 0) throw std::runtime_error("not a positive number.");
			if (inputVal > 1000) throw std::runtime_error("too large a number.");

			std::map<Data, double>::const_iterator it = database.lower_bound(queryDate);
			double rate = 0;

			if (it != database.end() && !(queryDate < it->first))
				{ rate = it->second; }
			else if (it != database.begin())
				{ --it; rate = it->second; }
			else
				{ throw std::runtime_error("no preceding date found in database."); }
			std::cout << strtrim(line.substr(0, pipePos)) << " => " << inputVal 
				<< " = " << (inputVal * rate) << std::endl;
		}
		catch (const std::exception &e)
			{ std::cerr << "Error: " << e.what() << std::endl; }
	}
}

// ---------------------Data Class-----------------------//
Data::Data() {}
Data::~Data() {}
Data::Data(const Data &other) {
	this->year = other.year;
	this->month = other.month;
	this->day = other.day;
	this->value = other.value;
}
Data &Data::operator=(const Data &other) {
	if (this != &other) {
		this->year = other.year;
		this->month = other.month;
		this->day = other.day;
		this->value = other.value;
	}
	return *this;
}
Data::Data(std::string data, char sep)
{
	size_t comma = data.find(sep);
	if (comma == std::string::npos)
		throw std::runtime_error("no value found");
	
	std::string datePart = data.substr(0, comma);
	std::string valPart = data.substr(comma + 1);

	std::stringstream Date(datePart);
	char dash1, dash2;

	if (!(Date >> year >> dash1 >> month >> dash2 >> day))
		throw std::runtime_error("bad input => " + data);
	
	if (dash1 != '-' || dash2 != '-')
		throw std::runtime_error("invalid date format");

	std::stringstream Val(valPart);
	if (!(Val >> value))
		throw std::runtime_error("invalid price value");

	if (year < 2009 || year > 2026) throw std::runtime_error("invalid year");
	if (month < 1 || month > 12) throw std::runtime_error("invalid month");
	if (day < 1 || day > 31) throw std::runtime_error("invalid day");

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw std::runtime_error("invalid day");
	if (month == 2) {
		bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (!(day <= (isLeap ? 29 : 28)))
			throw std::runtime_error("invalid day");
	}
}

bool Data::operator<(const Data & other) const
{
	if (year != other.year) return year < other.year;
	if (month != other.month) return month < other.month;
	return day < other.day;
}

double Data::getValue() const { return value; };

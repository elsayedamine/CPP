/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:34:42 by aelsayed          #+#    #+#             */
/*   Updated: 2025/12/31 21:53:21 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

class Data
{
	private:
		int year;
		int month;
		int day;
		double value;

	public:
		Data();
		Data(const Data &other);
		Data &operator=(const Data & other);
		~Data();

		Data(std::string data, char sep);
		double getValue() const;
		bool operator<(const Data & other) const;
};

std::string	strtrim(const std::string &s);

class BitcoinExchange
{
	private:
		std::map<Data, double> database;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		BitcoinExchange(const char *);
		void processInput(const char *) const;
};


#endif 
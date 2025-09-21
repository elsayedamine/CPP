/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 23:28:21 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/21 21:36:06 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &representation)
{
	static bool (*Checkers[])(const std::string&) = {
		&ScalarConverter::isChar,
		&ScalarConverter::isInteger,
		&ScalarConverter::isFloat,
		&ScalarConverter::isDouble,
		&ScalarConverter::isInfinite
	};

	static void (*converters[])(const std::string&) = {
		&ScalarConverter::Char,
		&ScalarConverter::Integer,
		&ScalarConverter::Float,
		&ScalarConverter::Double,
		&ScalarConverter::Infinite
	};
	for (int i = 0; i < 5; i++)
		if (Checkers[i](representation))
			return converters[i](representation);

	std::cout << "Unknown type" << std::endl;
}

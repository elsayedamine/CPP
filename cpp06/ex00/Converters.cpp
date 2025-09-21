/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converters.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:35:55 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/21 22:10:04 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	print_casts(const std::string &representation)
{
	errno = 0;
	double	d = std::strtod(representation.c_str(), NULL);
	// check if i want
	int i = static_cast<int>(d);
	char c = static_cast<char>(d);
	float f = static_cast<float>(d);
	// char
	if (std::isinf(d) || d < 0 || d > 127)
		std::cout << "char: Impossible" << std::endl;
	else if (!std::isprint(d))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	// int
	if (std::isinf(d) || d > INT_MAX || d < INT_MIN)
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
	// float
	if (std::isinf(d) || d > std::numeric_limits<float>::max() || d < -std::numeric_limits<float>::max())
		std::cout << "float: Impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	// double
	if (std::isinf(d))
		std::cout << "double: Impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
void ScalarConverter::Integer(const std::string &representation)
{
	print_casts(representation);
}
void ScalarConverter::Float(const std::string &representation)
{
	print_casts(representation.substr(representation.size() - 1));
}
void ScalarConverter::Double(const std::string &representation)
{
	print_casts(representation);
}
void ScalarConverter::Char(const std::string &representation)
{
	char c = representation[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	if (std::isprint(c))
		std::cout << "char: " << "'" << c << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}
void ScalarConverter::Infinite(const std::string &representation)
{
    bool isFloat = (representation[representation.size() - 1] == 'f' && representation.size() == 5);

    std::cout << "char: Impossible" << std::endl;
    std::cout << "int: Impossible" << std::endl;

    if (isFloat)
    {
        std::cout << "float: " << representation << std::endl;
        std::cout << "double: " << representation.substr(0, representation.size() - 1) << std::endl;
    }
    else
    {
        std::cout << "float: " << representation << "f" << std::endl;
        std::cout << "double: " << representation << std::endl;
    }
}


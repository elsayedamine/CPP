/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 01:30:09 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/19 02:32:13 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

typedef std::string str;

# define ERR "Error\n\tExpected format:\n\t<filename> <string1> <string2>\n"

// i tried to use ft_strstr but std::string::find is simply better

int	main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << ERR, 1);
	std::ifstream	infile(av[1]);
	std::ofstream	outfile((str(av[1]) + str(".replace")).c_str()); // no need to str or the literal btw

	if (!infile || !infile.is_open())
		return (std::cerr << "Error: could not open input file\n", 1);
	if (!outfile)
		return (std::cerr << "Error: could not create output file\n", 1);

	str	content((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());

	std::size_t pos = 0;
	std::size_t start = 0;
	str	full_content;
	str string2 = av[3];
	str string1 = av[2];
	std::size_t len = string1.length();
	while (pos != std::string::npos)
	{
		pos = content.find(string1, start);
		if (pos == std::string::npos)
			break ;
		str sub = content.substr(start, pos - start);
		full_content += sub;
		full_content += string2;
		start = len + pos;
	}
	full_content += content.substr(start);
	outfile << full_content;
	infile.close();
	outfile.close();
	return (0);
}

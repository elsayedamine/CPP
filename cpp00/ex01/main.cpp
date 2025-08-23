/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:25:56 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/23 18:02:05 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <limits> // Required for std::numeric_limits

str	trim(const str &s)
{
	size_t start = 0;
	while (start < s.size() && std::isspace((unsigned char)(s[start])))
		++start;
	size_t end = s.size();
	while (end > start && std::isspace((unsigned char)(s[end - 1])))
		--end;
	return (s.substr(start, end - start));
}

int	main()
{
	PhoneBook	phonebook;
	str			line;
	str			ADD = "ADD";
	str			SEARCH = "SEARCH";
	str			EXIT = "EXIT";

	std::cout << "Hey..., Well this is your contact manager!" << std::endl;
	while (true)
	{
		std::cout << "Enter ADD, SEARCH, EXIT : ";
		std::getline(std::cin, line);
		// if(std::cin.fail() || std::cin.eof())
		// {
		// 	// std::cout << "lol" << std::endl;
		// 	// std::cin.clear();
		// 	// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// 	// // continue;
		// 	// // exit(0);
		// }
		line = trim(line);
		if (!line.compare(ADD))
			phonebook.add_contact();
		else if (!line.compare(SEARCH))
			phonebook.search_contact();
		else if (!line.compare(EXIT))
			return (std::cout << "See ya!\nExiting...\n", 0);
	}
	return (0);
}
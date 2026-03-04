/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 16:42:42 by aelsayed          #+#    #+#             */
/*   Updated: 2025/12/31 22:09:53 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		{ std::cerr << "Error: could not open file." << std::endl; return 1; }
	try
	{
		BitcoinExchange store("data.csv");
		store.processInput(av[1]);
	}
	catch(const std::exception& e) {}

	return 0;
}

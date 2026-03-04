/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 21:46:46 by aelsayed          #+#    #+#             */
/*   Updated: 2025/12/31 22:59:13 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		{ std::cerr << "Error" << std::endl; return 1; }
	try
		{ RPN stack(av[1]); }
	catch(const std::exception& e) {std::cerr << e.what();}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 02:35:06 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/19 03:16:12 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void Harl::debug(void)
{
	std::cout	<< DEBUG << std::endl;
}

void Harl::info(void)
{
	std::cout	<< INFO << std::endl;
}

void Harl::warning(void)
{
	std::cout	<< WARNING << std::endl;
}

void Harl::error(void)
{
	std::cout	<< ERROR << std::endl;
}

void Harl::unknown(void)
{
	std::cout	<< "Unknown level" << std::endl;
}

void	Harl::complain(str level)
{
	void	(Harl::*fcts[5])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
		&Harl::unknown
	};
	str	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	while (i < 4 && (levels[i] != level))
		i++;
	(this->*fcts[i * (i < 4) + (i == 4) * 4])();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 03:25:44 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/19 03:39:45 by aelsayed         ###   ########.fr       */
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
	std::cout	<< "[ Probably complaining about insignificant problems ]" << std::endl;
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
	switch (i)
	{
		case 0:		(this->*fcts[0])();
		case 1:		(this->*fcts[1])();
		case 2:		(this->*fcts[2])();
		case 3:		(this->*fcts[3])(); break;
		default:	(this->*fcts[4])();
	}
}

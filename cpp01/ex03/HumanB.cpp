/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:37:23 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/19 01:24:28 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(str name) : name(name), weapon(0)
{

}

HumanB::~HumanB()
{
	
}

void	HumanB::attack() const
{
	if (weapon)
		std::cout	<< name
					<< " attacks with their "
					<< weapon->getType()
					<< std::endl;
	else
		std::cout << name << " has no weapon to attack!" << std::endl;
}

void	HumanB::setWeapon(Weapon &w)
{
	this->weapon = &w;
}
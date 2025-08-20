/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:22:07 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/20 17:24:48 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	setHits(100);
	setEnergy(100);
	setDamage(30);
	std::cout << "Default FragTrap Constructor Called" << std::endl;
}

FragTrap::FragTrap(const str &n) : ClapTrap(n)
{
	setHits(100);
	setEnergy(100);
	setDamage(30);
	std::cout << "FragTrap \"" << getName() << "\" was created with :" << std::endl;
	std::cout << std::setw(30) << "--------------------" << std::endl;
	std::cout << std::setw(27) << "HP : " << getHits() << std::endl;
	std::cout << std::setw(27) << "Energy Points : " << getEnergy() << std::endl;
	std::cout << std::setw(27) << "Attack Damage : " << getDamage() << std::endl;
	std::cout << std::setw(30) << "--------------------" << std::endl << std::endl;
}

FragTrap::FragTrap(const FragTrap &src)
{
	*this = src;
	std::cout << "FragTrap copy constructed from " << src.getName() << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << getName() << " was destroyed." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << getName()
			  << " requests a positive high five!" << std::endl;
}

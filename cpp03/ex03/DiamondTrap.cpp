/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:34:52 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/20 20:04:31 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap()
{
	setHits(FragTrap::getHits());
	setEnergy(ScavTrap::getEnergy());
	setDamage(FragTrap::getDamage());
	std::cout << "Default DiamondTrap Constructor Called" << std::endl;
}

DiamondTrap::DiamondTrap(const str &n) : ClapTrap(n + "_clap_name"), FragTrap(n), name(n)
{
	setHits(FragTrap::getHits());
	setEnergy(ScavTrap::getEnergy());
	setDamage(FragTrap::getDamage());

	std::cout << "DiamondTrap \"" << name << "\" created with:" << std::endl;
	std::cout << std::setw(30) << "--------------------" << std::endl;
	std::cout << std::setw(27) << "HP : " << getHits() << std::endl;
	std::cout << std::setw(27) << "Energy Points : " << getEnergy() << std::endl;
	std::cout << std::setw(27) << "Attack Damage : " << getDamage() << std::endl;
	std::cout << std::setw(30) << "--------------------" << std::endl << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other.ClapTrap::getName()), FragTrap(other), ScavTrap(other), name(other.name)
{
    setHits(other.getHits());
    setEnergy(other.getEnergy());
    setDamage(other.getDamage());
	std::cout << "DiamondTrap copy constructed from " << other.getName() << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->name = other.name;
		setHits(other.getHits());
		setEnergy(other.getEnergy());
		setDamage(other.getDamage());
	}
	return *this;
}

str	DiamondTrap::getName() const
{
	return this->name;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << getName() << " was destroyed." << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name : " << getName() << std::endl;
	std::cout << "ClapTrap name    : " << ClapTrap::getName() << std::endl;
}

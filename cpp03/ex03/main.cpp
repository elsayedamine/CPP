/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:41:14 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/20 19:54:31 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	ClapTrap c1("Alpha");
	c1.attack("Target1");
	c1.takeDamage(5);
	c1.beRepaired(3);

	ScavTrap s1("Bravo");
	s1.attack("Target2");
	s1.guardGate();

	FragTrap f1("Charlie");
	f1.attack("Target3");
	f1.highFivesGuys();

	DiamondTrap d1("Delta");
	d1.attack("Target4");
	d1.whoAmI();
	d1.guardGate();
	d1.highFivesGuys();

	DiamondTrap d2(d1);  // copy constructor
	DiamondTrap d3;
	d3 = d1;			 // assignment operator

	return 0;
}
// attack damage need to be fixed


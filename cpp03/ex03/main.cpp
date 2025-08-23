/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:41:14 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/23 11:58:44 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	ClapTrap c1("Alpha");
	c1.attack("Target1");
	c1.takeDamage(5);
	c1.beRepaired(3);

	DiamondTrap d1("Beta");
	d1.attack("Target4");
	d1.whoAmI();
	d1.guardGate();
	d1.highFivesGuys();

	DiamondTrap d2(d1);  // copy constructor
	DiamondTrap d3;
	d3 = d1;			 // assignment operator

	return 0;
}

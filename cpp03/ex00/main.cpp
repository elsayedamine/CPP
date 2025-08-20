/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:41:14 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/20 15:49:13 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap b("Bob");
	ClapTrap c;

	c = b;

	std::cout << "\n--- Simulation ---\n";

	b.attack("TargetDummy");
	b.takeDamage(3);
	b.beRepaired(5);

	b.attack("EvilTrap");
	b.takeDamage(12); // Should bring HP <= 0
	b.attack("AnotherDummy"); // Can't attack, dead
	b.beRepaired(4);		  // Can't repair, dead

	std::cout << "\n--- End of Simulation ---\n";

	return 0;
}

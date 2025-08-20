/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:41:14 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/20 17:27:54 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
int	main() {
	ClapTrap	Robin("Robin");
	ClapTrap	Romeo = ClapTrap("Roméo");
	ScavTrap	Cyril("Cyril");
	FragTrap	Bryan("Bryan");

	Robin.attack("Cyril");
	Cyril.takeDamage(Robin.getDamage());
	Cyril.beRepaired(18);
	Cyril.guardGate();
	Cyril.attack("Romeo");
	Romeo.takeDamage(Cyril.getDamage());
	Bryan.attack("Cyril");
	Cyril.takeDamage(Bryan.getDamage());
	Bryan.highFivesGuys();
	return 0;
}

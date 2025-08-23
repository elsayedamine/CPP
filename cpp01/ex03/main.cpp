/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 23:52:07 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/23 18:54:31 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("Exculiber");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("Katana");
		bob.attack();
	}
	{
		Weapon club = Weapon("Exculiber");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("Katana");
		jim.attack();
	}
	return 0;
}
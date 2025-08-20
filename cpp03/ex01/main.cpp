/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:41:14 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/20 17:16:09 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    // ClapTrap tests
    ClapTrap c1("CLAPPY");
    c1.attack("Target1");
    c1.takeDamage(5);
    c1.beRepaired(3);

    ClapTrap c2 = c1; // copy constructor
    c2.attack("Target2");

    ClapTrap c3;
    c3 = c1; // assignment operator
    c3.attack("Target3");

    // ScavTrap tests
    ScavTrap s1("SCAVVY");
    s1.attack("Enemy1");
    s1.takeDamage(20);
    s1.beRepaired(10);
    s1.guardGate();

    ScavTrap s2 = s1; // copy constructor
    s2.attack("Enemy2");

    ScavTrap s3;
    s3 = s1; // assignment operator
    s3.attack("Enemy3");
    s3.guardGate();

    return 0;
}

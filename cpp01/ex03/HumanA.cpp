/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:40:38 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/19 01:28:10 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const str &name, Weapon &w) : name(name), weapon(w)
{

}

HumanA::~HumanA()
{
	
}

void	HumanA::attack(void) const
{
	std::cout	<< this->name
				<< " attack with their "
				<< this->weapon.getType()
				<< std::endl;
}

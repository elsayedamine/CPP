/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 23:58:31 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/19 01:21:32 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(str name) : type(name)
{

}

Weapon::~Weapon()
{
	
}

const str	&Weapon::getType() const
{
	return this->type;
}

void	Weapon::setType(str type)
{
	this->type = type;
}

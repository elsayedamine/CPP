/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 23:53:06 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/19 01:25:25 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
# define HUMANB_H

#include <iostream>
#include "Weapon.hpp"

typedef std::string str;

class	HumanB
{
	public:
		HumanB(str name);
		~HumanB();
		void	attack(void) const;
		void	setWeapon(Weapon &weapon);

	private:
		str		name;
		Weapon	*weapon;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 23:53:06 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/19 01:25:34 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
# define HUMANA_H

#include <iostream>
#include "Weapon.hpp"

typedef std::string str;

class	HumanA
{
	public:
		HumanA(const str &name, Weapon &weapon);
		~HumanA();
		void	attack(void) const;

	private:
		str		name;
		Weapon	&weapon;
};

#endif
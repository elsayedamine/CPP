/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 23:53:06 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/19 01:17:43 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

#include <iostream>

typedef std::string str;

class	Weapon
{
	public:
		Weapon(str name);
		~Weapon();
		const str		&getType() const;
		void			setType(str type);

	private:
		str	type;
};

#endif
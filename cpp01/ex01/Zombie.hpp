/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 23:10:53 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/18 23:30:06 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

typedef std::string str;

class	Zombie
{
	public:
		Zombie();
		~Zombie();

		void	announce() const;
		void	setName(str n);
	private:
		str	name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
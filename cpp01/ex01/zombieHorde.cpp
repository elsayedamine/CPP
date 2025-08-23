/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 23:10:21 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/23 18:46:17 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (N <= 0)
	{
		std::cout << "creating " << N << " Zombies ?? Seriously ??\n";
		return (0);
	}

	Zombie	*horde = new Zombie[N];

	int i = -1;
	while (++i < N)
	{
		horde[i].setName(name);
		horde[i].announce();
	}
	return (horde);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 23:02:35 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/23 18:39:35 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*heapZombie;

	heapZombie = newZombie("Heapy");
	heapZombie->announce();
	delete heapZombie;

	randomChump("Stacky");
	return (0);
}

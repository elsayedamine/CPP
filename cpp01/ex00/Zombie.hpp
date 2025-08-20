/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 22:33:54 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/18 23:00:58 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H


#include <iostream>

typedef std::string str;

class	Zombie
{
	public:
		Zombie(str name);
		~Zombie();

		void	announce() const;
	private:
		str	name;
};

Zombie	*newZombie(str name);
void	randomChump(str name);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:21:03 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/23 11:36:44 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
		int	personal_damage;
	public:
		FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap(const str &name);
		FragTrap& operator=(const FragTrap &other);
		~FragTrap();

		void	highFivesGuys();
		int		getCopyDamage();
};

#endif

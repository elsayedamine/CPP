/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:33:56 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/20 19:47:58 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : virtual public FragTrap , virtual public ScavTrap
{
	private:
		str name;

	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap(const str &name);
		DiamondTrap &operator=(const DiamondTrap &other);
		~DiamondTrap();

		using ScavTrap::attack;
		str getName() const;
		void whoAmI();
};

#endif

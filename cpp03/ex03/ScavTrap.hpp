/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:21:19 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/23 12:13:07 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"


class ScavTrap : virtual public ClapTrap
{
	private:
		int	personal_energy;
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap(str const &name);
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();
		int		getCopyEnergy();
};

#endif
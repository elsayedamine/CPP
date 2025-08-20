/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:56:57 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/20 19:43:22 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <iomanip>

typedef std::string str;

class ClapTrap
{
	private:
		str	name;
		int	Hits;
		int	Damage;
		int	Energy;

	public:
		ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap(str const &name);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap();

		virtual void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		str		getName() const;
		int		getHits() const;
		int		getDamage() const;
		int		getEnergy() const;

		void	setName(const str &n);
		void	setHits(int h);
		void	setDamage(int d);
		void	setEnergy(int e);
};

#endif
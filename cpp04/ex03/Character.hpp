/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:54:47 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/01 17:27:31 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter
{
	private:
		str			name;
		AMateria*	inventory[4];
		// using vectors would be better but ... we can't
		AMateria*	floor[1000];
		int			floorcount;
	public:
		Character();
		Character(str const& name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		~Character();

		str const & getName() const;
		void		equip(AMateria* m);
		void		unequip(int idx);
		void		use(int idx, ICharacter& target);
};

#endif

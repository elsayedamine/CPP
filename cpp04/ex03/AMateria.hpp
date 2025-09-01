/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:46:19 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/01 16:03:51 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>

typedef std::string str;

class ICharacter;

class AMateria
{
	protected:
		str type;

	public:
		AMateria();
		AMateria(str const & type);
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		virtual ~AMateria();

		str const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};


# endif
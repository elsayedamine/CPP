/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:29:27 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/01 16:01:24 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	
}
AMateria::AMateria(str const & t) : type(t)
{
	
}
AMateria::AMateria(const AMateria& other)
{
	*this = other;
}
AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}
AMateria::~AMateria()
{
	
}
str const & AMateria::getType() const
{
	return this->type;
}
void	AMateria::use(ICharacter& target)
{
	(void)target;
}

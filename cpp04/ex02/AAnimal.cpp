/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:03:25 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/30 15:11:53 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "AAnimal Def Constr\n";
}

AAnimal::AAnimal(const AAnimal& obj)
{
	*this = obj;
	std::cout << "AAnimal Copy Constr\n";
}

AAnimal& AAnimal::operator=(const AAnimal& obj)
{
	if (this != &obj)
		this->type = obj.type;
	std::cout << "AAnimal Copy assignement\n";
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destr\n";
}
	
str AAnimal::getType() const
{
	return type;
}

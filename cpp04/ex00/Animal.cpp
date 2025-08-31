/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:38:31 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/30 15:19:57 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal Def Constr" << std::endl;
}

Animal::Animal(const Animal& other)
{
	*this = other;
	std::cout << "Animal Copy Constr" << std::endl;

}

Animal&	Animal::operator=(const Animal& other)
{
	this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal Destr" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Generic animal sound" << std::endl;
}

str	Animal::getType() const
{
	return this->type;
}

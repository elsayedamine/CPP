/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:39:46 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/29 17:46:48 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog Def Constr" << std::endl;	
}

Dog::Dog(const Dog& other) : Animal(other)
{
	*this = other;
	std::cout << "Dog Copy Constr" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
        this->type = other.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog Destr" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof woof!" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:39:46 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/30 15:16:37 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
	this->type = "Dog";
	std::cout << "Dog Def Constr" << std::endl;	
}

Dog::Dog(const Dog& other) : AAnimal(other), brain(new Brain(*other.brain))
{
	*this = other;
	std::cout << "Dog Copy Constr" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
        this->type = other.type;
	*brain = *other.brain;
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog Destr" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return brain;
}

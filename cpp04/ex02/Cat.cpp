/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:40:29 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/30 15:16:27 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : brain(new Brain())
{
	this->type = "Cat";
	std::cout << "Cat Def Constr" << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal(other), brain(new Brain(*other.brain))
{
	*this = other;
	std::cout << "Cat Copy Constr" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
		this->type = other.type;
	*brain = *other.brain;
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat Destr" << std::endl;
}

void    Cat::makeSound() const
{
	std::cout << "Meow meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return brain;
}
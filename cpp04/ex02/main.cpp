/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:13:36 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/30 15:25:02 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	// AAnimal a; // we cannot instantiate an abstract class 
	const AAnimal* animals[4];

	// Fill array with Dogs and Cats
	for (int i = 0; i < 2; i++)
		animals[i] = new Dog();
	for (int i = 2; i < 4; i++)
		animals[i] = new Cat();

	std::cout << "\n--- Making sounds ---" << std::endl;
	for (int i = 0; i < 4; i++)
		animals[i]->makeSound();

	std::cout << "\n--- Testing Brain deep copy ---" << std::endl;
	Dog basic;
	basic.getBrain()->setIdea(0, "Eat food");
	basic.getBrain()->setIdea(1, "Chase cats");

	Dog copyDog = basic; // calls copy constructor (deep copy)
	std::cout << "Basic idea[0]: " << basic.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy idea[0]:  " << copyDog.getBrain()->getIdea(0) << std::endl;

	basic.getBrain()->setIdea(0, "Sleep all day");
	std::cout << "After change -> Basic idea[0]: " << basic.getBrain()->getIdea(0) << std::endl;
	std::cout << "After change -> Copy idea[0]:  " << copyDog.getBrain()->getIdea(0) << std::endl;

	std::cout << "\n--- Cleaning up ---" << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i];

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:46:33 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/29 18:47:40 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const int N = 6;
	Animal* animals[N];

	// 1️⃣ Create half Dogs, half Cats
	for (int i = 0; i < N; i++)
	{
		if (i < N / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	// 2️⃣ Make sounds polymorphically
	std::cout << "\n=== Polymorphic Sounds ===\n";
	for (int i = 0; i < N; i++)
		animals[i]->makeSound();

	// 3️⃣ Test deep copy of Dog Brain
	std::cout << "\n=== Deep Copy Test ===\n";
	Dog originalDog;
	originalDog.getBrain()->setIdea(0, "Chase the mailman");

	Dog copiedDog = originalDog; // copy constructor
	copiedDog.getBrain()->setIdea(0, "Changed idea in copy");

	std::cout << "originalDog Brain[0]: " 
			  << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "copiedDog Brain[0]: " 
			  << copiedDog.getBrain()->getIdea(0) << std::endl;

	// 4️⃣ Delete all animals polymorphically
	std::cout << "\n=== Deleting Animals ===\n";
	for (int i = 0; i < N; i++)
		delete animals[i];

	return 0;
}

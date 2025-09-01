/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:43:05 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/01 17:19:38 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main()
{
    // std::cout << "=== Creating Characters ===" << std::endl;
    Character bob("Bob");
    Character alice("Alice");

    // // std::cout << "\n=== Creating Materias ===" << std::endl;
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    AMateria* ice2 = new Ice();

    // // std::cout << "\n=== Equipping Bob ===" << std::endl;
    bob.equip(ice);
    bob.equip(cure);
    bob.equip(ice2);

    // // std::cout << "\n=== Using Materias on self ===" << std::endl;
    bob.use(0, bob); // Ice
    bob.use(1, bob); // Cure
    bob.use(2, bob); // Ice
    bob.use(3, bob); // empty slot, no output

    // std::cout << "\n=== Unequipping and re-equipping ===" << std::endl;
    bob.unequip(1); // Cure goes to floor
    bob.use(1, bob); // Slot 1 empty → nothing
    bob.equip(new Cure()); // Equip new Cure
    bob.use(1, bob); // * heals Bob's wounds *

    // std::cout << "\n=== Using Materias on Alice ===" << std::endl;
    bob.use(0, alice); // Ice → Alice
    bob.use(1, alice); // Cure → Alice

    // std::cout << "\n=== Testing MateriaSource ===" << std::endl;
    MateriaSource src;
    AMateria* i = new Ice();
    src.learnMateria(i);
    delete i;
    AMateria* c = new Cure();
    src.learnMateria(c);
    delete c;

    AMateria* m1 = src.createMateria("ice");
    AMateria* m2 = src.createMateria("cure");
    AMateria* m3 = src.createMateria("fire"); // unknown type → nullptr

    // std::cout << "\n=== Equipping Bob with Materias from source ===" << std::endl;
    bob.equip(m1);
    bob.equip(m2);
    bob.equip(m3); // nullptr → nothing happens

    bob.use(0, alice); // Ice
    bob.use(1, alice); // Cure

    // std::cout << "\n=== Testing deep copy of Bob ===" << std::endl;
    Character copyBob(bob);
    copyBob.use(0, alice); // Ice
    copyBob.use(1, alice); // Cure

    // std::cout << "\n=== End of tests ===" << std::endl;
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 00:30:31 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/22 00:46:55 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <cstdlib>
#include <ctime>

Base* generate()
{
	int r = rand() % 3;

	switch (r)
	{
		case 0:
			std::cout << "Class A created" << std::endl;
			return new A();
		case 1:
			std::cout << "Class B created" << std::endl;
			return new B();
		case 2:
			std::cout << "Class C created" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base& p)
{
	try { (void)dynamic_cast<A&>(p); std::cout << "A" << std::endl; return; }
	catch(...) {}

	try { (void)dynamic_cast<B&>(p); std::cout << "B" << std::endl; return; }
	catch(...) {}

	try { (void)dynamic_cast<C&>(p); std::cout << "C" << std::endl; return; }
	catch(...) {}

	std::cout << "Unknown" << std::endl;
}

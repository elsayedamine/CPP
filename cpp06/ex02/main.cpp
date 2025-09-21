/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 00:33:44 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/22 00:47:05 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int main()
{
	srand(time(NULL));
    Base* ptr = generate();
    
    std::cout << "Identification by pointer: ";
    identify(ptr);
    
    std::cout << "Identification by reference: ";
    identify(*ptr);
    
    delete ptr;
    return 0;
}

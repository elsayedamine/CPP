/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 23:36:48 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/18 23:44:57 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

typedef std::string str;


int	main()
{
	str string = "HI THIS IS BRAIN";
	str	*stringPTR = &string;
	str	&stringREF = string;

	std::cout << "This is the memory address of the string variable: " << &string << std::endl;
	std::cout << "This is the memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "This is the memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << "The value of the string is : " << string << std::endl;
	std::cout << "The value pointed to by stringPTR is : " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF is : " << stringREF << std::endl;
}

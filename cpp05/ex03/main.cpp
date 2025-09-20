/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 03:45:39 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/20 06:49:19 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat john("John", 1);
		Bureaucrat jim("Jim", 150);

		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Bob");
		PresidentialPardonForm pardon("Alice");

		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;

		jim.signForm(shrub);
		john.signForm(shrub);
		john.signForm(robot);
		john.signForm(pardon);

		// Attempt to execute
		try
		{
			jim.executeForm(shrub);
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << std::endl;
		}

		john.executeForm(shrub);
		john.executeForm(robot);
		john.executeForm(pardon);

		// Print final forms
		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;
	}
	catch (const std::exception & e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:14:42 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/20 22:07:28 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	
}
Intern::Intern(const Intern& other)
{
	(void)other;
}
Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}
Intern::~Intern()
{
	
}

static AForm* createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*formCreators[3])(const std::string&) = {
		&createShrubbery,
		&createRobotomy,
		&createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](target);
		}
	}

	std::cerr << "Intern cannot create form: " << formName 
			  << " (unknown type)" << std::endl;
	return NULL;
}

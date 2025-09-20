/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 20:55:22 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/18 20:55:22 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("Unamed_target")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target)
	: AForm("ShrubberyCreation", 145, 137), target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target)
	{
		
	}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

void ShrubberyCreationForm::action() const
{
	std::ofstream file((target + "_shrubbery").c_str());
	if (!file)
		throw std::runtime_error("Failed to create file");

	file << "       ###\n"
			<< "      #o###\n"
			<< "    #####o###\n"
			<< "   #o#\\#|#/###\n"
			<< "    ###\\|/#o#\n"
			<< "     # }|{  #\n"
			<< "       }|{\n";
	file.close();
}

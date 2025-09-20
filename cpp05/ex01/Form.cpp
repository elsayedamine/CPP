/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 17:57:26 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/20 06:43:53 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Unamed Form"), isSigned(false), gradeToSign(150), gradeToExecute(150) 
{
	std::cout << "[Form] Default Constructor called." << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) 
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned), 
	gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) 
{
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

Form::~Form()
{
}

const std::string& Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	isSigned = true;
}
const char* Form::GradeTooHighException::what() const throw()
{
    return "[Form Exception] Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "[Form Exception] Grade is too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	std::string sign;
	if (form.getIsSigned())
		sign = "yes";
	else
		sign = "no";
	out << form.getName()
		<< ", form signed: " << sign
		<< ", grade required to sign: " << form.getGradeToSign()
		<< ", grade required to execute: " << form.getGradeToExecute();
	return out;
}

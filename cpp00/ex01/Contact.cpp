/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:28:39 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/18 17:17:55 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact()
{

}

Contact::~Contact()
{

}

void	Contact::setName(str name)
{
	this->first = name;
}

void	Contact::setLast(str last)
{
	this->last = last;
}

void	Contact::setNick(str nick)
{
	this->nick = nick;
}

void	Contact::setPhone(str phone)
{
	this->number = phone;
}

void	Contact::setSecret(str secret)
{
	this->secret = secret;
}

str	Contact::getName() const
{
	return this->first;
}

str Contact::getLast() const
{
	return this->last;
}

str Contact::getNick() const
{
	return this->nick;
}

str Contact::getPhone() const
{
	return this->number;
}

str	Contact::getSecret() const
{
	return this->secret;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:26:23 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/18 17:04:13 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

PhoneBook::PhoneBook() :  curr_contact(0), nb_contacts(0)
{
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}

void	PhoneBook::add_contact()
{
	str arr[5];
	str msg[5] = {	
		"Enter the name : ",
		"Enter the lastname : ",
		"Enter the nickname : ",
		"Enter the phonenumber : ",
		"Spill their darkest Secret : "};

	if (this->curr_contact == 8)
		this->curr_contact = 0;
	for(int i = 0; i < 5; i++)
	{
		std::cout << msg[i];
		std::getline(std::cin, arr[i]);
		if (!arr[i].c_str() || !*arr[i].c_str())
			return (std::cout << "A contact can't have empty fields.\n",(void)arr);
	}
	this->array[this->curr_contact].setName(arr[0]);
	this->array[this->curr_contact].setLast(arr[1]);
	this->array[this->curr_contact].setNick(arr[2]);
	this->array[this->curr_contact].setPhone(arr[3]);
	this->array[this->curr_contact].setSecret(arr[4]);
	this->curr_contact++;
	if (this->nb_contacts < 8)
		this->nb_contacts++;
}

void	PhoneBook::search_contact()
{
	str	name;
	str	last;
	str	nick;
	str	phone;
	str	secret;
	str	result;
	str	arr[5];
	if (this->curr_contact == 0)
		return (std::cout << "No contact available !\n\t Please ADD one first.\n", (void)name);
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "Firstname" << "|";
	std::cout << std::setw(10) << "Lastname" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < this->nb_contacts; i++)
	{
		name = this->array[i].getName();
		last = this->array[i].getLast();
		nick = this->array[i].getNick();
		phone = this->array[i].getPhone();
		secret = this->array[i].getSecret();
		if (name.length() > 9)
			name = name.substr(0, 9) + ".";
		if (last.length() > 9)
			last = last.substr(0, 9) + ".";
		if (nick.length() > 9)
			nick = nick.substr(0, 9) + ".";
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << name << "|";
		std::cout << std::setw(10) << last << "|";
		std::cout << std::setw(10) << nick << std::endl;
	}
	std::cout << "Type a contact's index to display their personal informations : ";
	std::getline(std::cin, result);
	int index = atoi(result.c_str());
	if ((index > 7 || index < 0) || (index == 0 && !result[0]))
		return (std::cout << "Please enter a valid digit (1-8)!\n" , (void)index);
	if (index >= this->nb_contacts)
		return (std::cout << "Contact not found !\n", (void)index);
	std::cout << "Name : " << this->array[index].getName() << std::endl;
	std::cout << "Lastname : " << this->array[index].getLast() << std::endl;
	std::cout << "Nickname : " << this->array[index].getNick() << std::endl;
	std::cout << "Phone number : " << this->array[index].getPhone() << std::endl;
	std::cout << "Darkest secret : " << this->array[index].getSecret() << std::endl;
}

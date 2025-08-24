/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:56:34 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/24 10:47:36 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_H
#define CONTACT_H

#include "main.hpp"

class	Contact
{
	private:
		str	first;
		str	last;
		str	nick;
		str	number;
		str	secret;
	public:
		Contact();
		~Contact();

		void	setName(str first);
		void	setLast(str last);
		void	setNick(str nick);
		void	setPhone(str phone);
		void	setSecret(str secret);
		str		getName() const;
		str		getLast() const;
		str		getNick() const;
		str		getPhone() const;
		str		getSecret() const;

};

#endif

// this
// const funct
// setters / getters /constr/ destr (no return val)
// public private
// static funcs in class and static vars (all about)

// classes defines what it means to be an object
// so an account is considered an account only if it has the properites of this class for example
// Classes allow us to group variables into a user-defined type and also add functionality to those variables
// we can consier also that the classes are the blueprint and the instances are the houses built using this blueprint



// std::getline(std::cin, line);
// if(std::cin.fail() || std::cin.eof())
// no .h in C++
// std::cout and what related to it
// namespace
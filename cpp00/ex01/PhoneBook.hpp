/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 14:58:29 by aelsayed          #+#    #+#             */
/*   Updated: 2025/08/24 09:47:48 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "main.hpp"

class	PhoneBook
{
	private:
		int			curr_contact;
		int			nb_contacts;
		Contact		array[8];
	public:
		PhoneBook();
		~PhoneBook();

		void	add_contact();
		void	search_contact();
};

int	isValidPhone(const str &s);
int	isPrintableString(const str &s);


#endif
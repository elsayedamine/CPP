/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:31:16 by cgodecke          #+#    #+#             */
/*   Updated: 2025/09/22 18:00:57 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::cout << "\033[33m" << "Test vector container\n"<< "\033[0m";
	std::vector<int> v;

	for (int i = 0; i < 10; i++)
		v.push_back(i);
	try
	{
		std::cout << *easyfind(v, 5) << std::endl;
		std::cout << *easyfind(v, 20) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\033[33m" << "Test list container\n" << "\033[0m";
	std::list<char> l;

	char a = 'a';
	for (int i = 0; i < 28; i++)
		l.push_back(a++);
	try
	{
		std::cout << *easyfind(l, 'z') << std::endl;
		std::cout << *easyfind(l, 1000) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	std::cout << "\033[33m" << "Test deque container\n" << "\033[0m";
	std::deque<int> d;

	for (int i = 0; i < 350; i++)
		d.push_back(i);
	try
	{
		std::cout << *easyfind(d, 349) << std::endl;
		std::cout << *easyfind(d, 560) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
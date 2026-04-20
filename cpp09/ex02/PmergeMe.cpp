/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:36:39 by aelsayed          #+#    #+#             */
/*   Updated: 2026/04/20 21:51:40 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->vec = other.vec;
		this->deq = other.deq;
	}
	return *this;
}

void PmergeMe::Validator(int ac, char **av)
{
	for (int i = 1; i < ac; ++i)
	{
		std::string str(av[i]);
		if (str.empty()) // empty
			throw std::runtime_error("Empty argument");
		for (size_t j = 0; j < str.length(); ++j)
			if (!std::isdigit(str[j])) // digits
				throw std::runtime_error("Not a positive integer");
		long val = std::atol(str.c_str());
		if (val < 0 || val > 2147483647) // ints
			throw std::runtime_error("Value out of range");
		unsorted.push_back(static_cast<int>(val));
	}
}

void PmergeMe::PrintVector(std::vector<int> vect)
{
	for (size_t i = 0; i < vect.size(); ++i)
		std::cout << vect[i] << (i == vect.size() - 1 ? "" : " ");
	std::cout << std::endl;
}

std::vector<int> PmergeMe::sortVector(std::vector<int> vect)
{
	vect = unsorted;
	int struggler = -1;
	if (vect.size() % 2)
	{
		struggler = vect[vect.size() - 1];
		vect.pop_back();
	}
	if (vect.size() == 1)
		return vect;
	// Phase one (pairing and comparing and main chain)
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> largers;
	for (size_t i = 0; i < vect.size() - 1; i += 2)
	{
		pairs.push_back(std::make_pair(std::max(vect[i], vect[i + 1]), std::min(vect[i], vect[i + 1])));
		largers.push_back(std::max(vect[i], vect[i + 1]));
	}
	largers = sortVector(largers);
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		if (it->first == largers[0])
			{largers.insert(largers.begin(), it->second); break;} } // i should flag that the loser of the first winner is alrdy added
	// now we move to the jacobsthal sequence tal ggheda
}

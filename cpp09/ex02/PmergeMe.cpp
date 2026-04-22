/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:36:39 by aelsayed          #+#    #+#             */
/*   Updated: 2026/04/22 22:55:40 by aelsayed         ###   ########.fr       */
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

void PmergeMe::PrintVector(std::vector<int> vect)
{
	for (std::size_t i = 0; i < vect.size(); ++i)
		std::cout << vect[i] << (i == vect.size() - 1 ? "" : " ");
	std::cout << std::endl;
}

void PmergeMe::Validator(int ac, char **av)
{
	for (int i = 1; i < ac; ++i)
	{
		std::string str(av[i]);
		if (str.empty())
			throw std::runtime_error("Empty argument");
		for (std::size_t j = 0; j < str.length(); ++j)
			if (!std::isdigit(str[j]))
				throw std::runtime_error("Not a positive integer");
		long val = std::atol(str.c_str());
		if (val < 0 || val > 2147483647)
			throw std::runtime_error("Value out of range");
		for (std::size_t k = 0; k < unsorted.size(); ++k)
			if (unsorted[k] == static_cast<int>(val))
				throw std::runtime_error("Duplicate value");
		unsorted.push_back(static_cast<int>(val));
	}
}

std::vector<int> PmergeMe::GeneratePening(const std::vector<int> &Main, std::vector<std::pair<int, int> > &pairs)
{
	std::vector<int> Pend;
	for (std::size_t i = 2; i < Main.size(); ++i)
		for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
			if (it->first == Main[i])
				{Pend.push_back(it->second); break;}
	return Pend;
}

std::vector<int> PmergeMe::GenerateIndices(int pending)
{
	int j(0), j0 = 1, j1 = 3;
	std::vector<int> JCBSequence;
	std::vector<int> Indices;
	JCBSequence.push_back(j0);
	JCBSequence.push_back(j1);
	while (j < pending)
	{
		j = j1 + 2 * j0;
		j0 = j1;
		j1 = j;
		JCBSequence.push_back(j);
	}
	int lst_jcb = 0;
	for (size_t i = 1; i < JCBSequence.size(); ++i)
	{
		int top = JCBSequence[i] > pending ? pending : JCBSequence[i];
		while (top > lst_jcb)
			Indices.push_back(top--);
		lst_jcb = (JCBSequence[i] > pending ? pending : JCBSequence[i]);
	}
	return (Indices);
}
std::vector<int> PmergeMe::sortVector(std::vector<int> vect)
{
	int struggler = -1;
	if (vect.size() <= 1)
		return sorted = vect, vect;
	if (vect.size() % 2)
	{
		struggler = vect[vect.size() - 1];
		vect.pop_back();
	}
	std::vector<std::pair<int, int> > pairs;
	std::vector<int> Main;
	for (std::size_t i = 0; i < vect.size() - 1; i += 2)
	{
		pairs.push_back(std::make_pair(std::max(vect[i], vect[i + 1]), std::min(vect[i], vect[i + 1])));
		Main.push_back(std::max(vect[i], vect[i + 1]));
	}
	Main = sortVector(Main);
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		if (it->first == Main[0])
			{Main.insert(Main.begin(), it->second); break;} }
	std::vector<int> Pend = GeneratePening(Main, pairs);
	std::vector<int> indices = GenerateIndices(Pend.size());
	std::vector<int> StaticMain = Main;
	for (size_t i = 0; i < indices.size(); ++i)
	{
		int loser_pos = indices[i] - 1;
		std::vector<int>::iterator pos = std::upper_bound(Main.begin(), std::find(Main.begin(), Main.end(), StaticMain[loser_pos + 2]), Pend[loser_pos]);	
		Main.insert(pos, Pend[loser_pos]);
	}
	if (struggler != -1)
		Main.insert(std::upper_bound(Main.begin(), Main.end(), struggler), struggler);
	sorted = Main;
	return (Main);
}

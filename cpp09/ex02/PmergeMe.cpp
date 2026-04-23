/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:36:39 by aelsayed          #+#    #+#             */
/*   Updated: 2026/04/23 17:53:24 by aelsayed         ###   ########.fr       */
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
PmergeMe::PmergeMe(int ac, char **av, int f)
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
		if (f == VECTOR)
		{
			for (std::size_t k = 0; k < unsorted_vec.size(); ++k)
				if (unsorted_vec[k] == static_cast<int>(val))
					throw std::runtime_error("Duplicate value");
			unsorted_vec.push_back(static_cast<int>(val));
		}
		else
		{
			for (std::size_t k = 0; k < unsorted_vec.size(); ++k)
				if (unsorted_vec[k] == static_cast<int>(val))
					throw std::runtime_error("Duplicate value");	
			unsorted_deq.push_back(static_cast<int>(val));
		}
	}
}

std::vector<int> PmergeMe::MergeSortVector(std::vector<int> vect)
{
	int struggler = -1;
	if (vect.size() <= 1)
		return vec = vect, vect;
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
	Main = MergeSortVector(Main);
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		if (it->first == Main[0])
			{Main.insert(Main.begin(), it->second); break;} }
	std::vector<int> Pend = GeneratePending(Main, pairs);
	std::vector<int> indices = GenerateIndices(Pend);
	std::vector<int> StaticMain = Main;
	for (size_t i = 0; i < indices.size(); ++i)
	{
		int loser_pos = indices[i] - 1;
		std::vector<int>::iterator pos = std::upper_bound(Main.begin(), std::find(Main.begin(), Main.end(), StaticMain[loser_pos + 2]), Pend[loser_pos]);	
		Main.insert(pos, Pend[loser_pos]);
	}
	if (struggler != -1)
		Main.insert(std::upper_bound(Main.begin(), Main.end(), struggler), struggler);
	vec = Main;
	return (Main);
}

std::deque<int> PmergeMe::MergeSortDeque(std::deque<int> deqq)
{
	int struggler = -1;
	if (deqq.size() <= 1)
		return deq = deqq, deqq;
	if (deqq.size() % 2)
	{
		struggler = deqq[deqq.size() - 1];
		deqq.pop_back();
	}
	std::deque<int> Main;
	std::deque<std::pair<int, int> > pairs;
	for (std::size_t i = 0; i < deqq.size() - 1; i += 2)
	{
		pairs.push_back(std::make_pair(std::max(deqq[i], deqq[i + 1]), std::min(deqq[i], deqq[i + 1])));
		Main.push_back(std::max(deqq[i], deqq[i + 1]));
	}
	Main = MergeSortDeque(Main);
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it) {
		if (it->first == Main[0])
			{Main.push_front(it->second); break;} } // change 
	std::deque<int> Pend = GeneratePending(Main, pairs);
	std::deque<int> indices = GenerateIndices(Pend);
	std::deque<int> StaticMain = Main;
	for (size_t i = 0; i < indices.size(); ++i)
	{
		int loser_pos = indices[i] - 1;
		std::deque<int>::iterator pos = std::upper_bound(Main.begin(), std::find(Main.begin(), Main.end(), StaticMain[loser_pos + 2]), Pend[loser_pos]);	
		Main.insert(pos, Pend[loser_pos]); // internal change 
	}
	if (struggler != -1)
		Main.insert(std::upper_bound(Main.begin(), Main.end(), struggler), struggler);
	deq = Main;
	return (Main);
}
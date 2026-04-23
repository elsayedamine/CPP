/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:35:51 by aelsayed          #+#    #+#             */
/*   Updated: 2026/04/23 18:29:44 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <sys/time.h>
# include <sstream>
# include <ctime>
# include <iomanip>
# include <algorithm>

# define VECTOR 1
# define DEQUE 2

class PmergeMe
{
	public:
		std::vector<int> unsorted_vec;
		std::deque<int> unsorted_deq;
		std::vector<int> vec;
		std::deque<int>  deq;

	public:
		PmergeMe();
		PmergeMe(int, char **, int);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		// templated utils
		template<typename M, typename P>
		M GeneratePending(const M &, const P &);
		template<typename P>
		P GenerateIndices(const P &);
		template <typename T>
		void PrintContainer(const T& container);
		
		// sorters
		std::vector<int> MergeSortVector(std::vector<int>);
		std::deque<int> MergeSortDeque(std::deque<int>);
};

template <typename T>
void PmergeMe::PrintContainer(const T& container)
{
	for (std::size_t i = 0; i < container.size(); ++i)
		std::cout << container[i] << (i == container.size() - 1 ? "" : " ");
	std::cout << std::endl;
}
template<typename M, typename P>
M PmergeMe::GeneratePending(const M &Main, const P &pairs)
{
	M Pend; // i went to i = 2 cuz the first two are alrdy inserted
	for (std::size_t i = 2; i < Main.size(); ++i)
		for (typename P::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
			if (it->first == Main[i])
				{Pend.push_back(it->second); break;}
	return Pend;
}
template<typename P>
P PmergeMe::GenerateIndices(const P &Pend)
{
	int j(0), j0 = 1, j1 = 3;
	int pending = Pend.size();
	P JCBSequence;
	P Indices;
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
template<typename T>
bool isSorted(const T& c)
{
	if (c.empty())
		return true;

	for (size_t i = 0; i < c.size() - 1; ++i)
		if (c[i] > c[i + 1])
			return false;
	return true;
}


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:35:51 by aelsayed          #+#    #+#             */
/*   Updated: 2026/04/20 20:49:34 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>
#include <sys/time.h>
#include <sstream>
# include <ctime>
# include <iomanip>
# include <algorithm>

class PmergeMe
{
	public:
		std::vector<int> unsorted;
		std::vector<int> sorted;
    private:
        std::vector<int> vec;
        std::deque<int>  deq;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

		// sorters
		std::vector<int> sortVector(std::vector<int>);
		// void sortDeque(void);

		// utils
		void Validator(int ac, char **av);
		void PrintVector(std::vector<int>);

};

#endif
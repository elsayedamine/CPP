/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:38:30 by aelsayed          #+#    #+#             */
/*   Updated: 2026/04/20 20:50:09 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

long long get_time(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000LL) + tv.tv_usec;
}

int main(int ac, char **av)
{
	if (ac < 2)
		{ std::cerr << "Error: No input provided." << std::endl; return 1; }

	try
	{
		PmergeMe sorter;
		sorter.Validator(ac, av);

		std::cout << "Before: ";
		sorter.PrintVector(sorter.unsorted);

		long long start_vec = get_time();
		std::vector<int> sorted_vec = sorter.sortVector(sorter.unsorted); 
		long long end_vec = get_time();

		// long long start_deq = get_time();
		// std::deque<int> sorted_deq = sorter.sortDeque();
		// long long end_deq = get_time();

		std::cout << "After:  ";
		sorter.PrintVector(sorter.sorted);

		// double time_vec = static_cast<double>(end_vec - start_vec);
		// double time_deq = static_cast<double>(end_deq - start_deq);

		// std::cout << "Time to process a range of " << initial_data.size() 
		// 		  << " elements with std::vector : " << std::fixed << std::setprecision(5) 
		// 		  << time_vec << " us" << std::endl;
		// std::cout << "Time to process a range of " << initial_data.size() 
		// 		  << " elements with std::deque  : " << std::fixed << std::setprecision(5) 
		// 		  << time_deq << " us" << std::endl;

	}
	catch (const std::exception &e)
		{ std::cerr << "Error" << std::endl; return 1; }

	return 0;
}
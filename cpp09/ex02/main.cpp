/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:38:30 by aelsayed          #+#    #+#             */
/*   Updated: 2026/04/23 17:56:33 by aelsayed         ###   ########.fr       */
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
		// initial instance just to print
		PmergeMe initial(ac, av, VECTOR);
		std::cout << "Before: ";
		initial.PrintContainer(initial.unsorted_vec);

		// VECTOR
		long long start_vec = get_time();
		PmergeMe vector(ac, av, VECTOR);
		vector.MergeSortVector(vector.unsorted_vec);
		long long end_vec = get_time();

		// DEQUE
		long long start_deq = get_time();
		PmergeMe deque(ac, av, DEQUE);
		deque.MergeSortDeque(deque.unsorted_deq);
		long long end_deq = get_time();

		std::cout << "After:  ";
		vector.PrintContainer(vector.vec);

		double time_vec = static_cast<double>(end_vec - start_vec);
		double time_deq = static_cast<double>(end_deq - start_deq);

		std::cout << "Time to process a range of " << vector.unsorted_vec.size() 
                  << " elements with std::vector : " << std::fixed << std::setprecision(5) 
                  << time_vec << " us" << std::endl;
        std::cout << "Time to process a range of " << deque.unsorted_deq.size() 
                  << " elements with std::deque  : " << std::fixed << std::setprecision(5) 
                  << time_deq << " us" << std::endl;

		// std::cout << (isSorted(vector.vec) ? "Sorted" : "Unsorted") << std::endl;
		// std::cout << (isSorted(deque.deq) ? "Sorted" : "Unsorted") << std::endl;

	}
	catch (const std::exception &e)
		{ std::cerr << "Error: " << e.what() << std::endl; return 1; }

	return 0;
}

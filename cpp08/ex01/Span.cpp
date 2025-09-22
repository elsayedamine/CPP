/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:36:14 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/22 19:38:49 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : max_size(0), min(INT_MAX), max(INT_MIN) {}
Span::Span(unsigned int n) : max_size(n), min(INT_MAX), max(INT_MIN) {}
Span::Span(const Span & other) : max_size(other.max_size), arr(other.arr), min(other.min), max(other.max) {}
Span::~Span() {}
Span&	Span::operator=(const Span & other)
{
	if (this != &other)
	{
		max_size = other.max_size;
		arr = other.arr;
		min = other.min;
		max = other.max;
	}
	return (*this);
}


int Span::longestSpan() const
{
	if (arr.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");
	return (max - min);
}

int Span::shortestSpan() const
{
	if (arr.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");

	std::vector<int> sorted = arr;
	std::sort(sorted.begin(), sorted.end());

	int shortest = INT_MAX;
	for (size_t i = 1; i < sorted.size(); i++)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

void	Span::addNumber(int num)
{
	if (arr.size() >= max_size)
		throw std::overflow_error("Span is full");
	arr.push_back(num);
	if (num < min)
		min = num;
	if (num > max)
		max = num;
}

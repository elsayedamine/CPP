/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 02:54:48 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/22 03:21:16 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void StringToUpper(std::string &s)
{
	for (size_t i = 0; i < s.size(); i++)
		s[i] = std::toupper(s[i]);
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	size_t len = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Original int array: ";
	iter(arr, len, printElement<int>);
	std::cout << std::endl;

	iter(arr, len, incrementElement<int>);
	std::cout << "After increment: ";
	iter(arr, len, printElement<int>);
	std::cout << std::endl;

	std::string strArr[] = {"hello", "world", "templates"};
	size_t len2 = sizeof(strArr) / sizeof(strArr[0]);

	std::cout << "String array: ";
	iter(strArr, len2, StringToUpper);
	iter(strArr, len2, printElement<std::string>);
	std::cout << std::endl;

    return 0;
}

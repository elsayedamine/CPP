/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 20:11:54 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/22 20:21:22 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

// def ctor
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}
// copy ctor
template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other) {}
// dtor
template <typename T>
MutantStack<T>::~MutantStack() {}
// assign operator
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() { return this->c.begin(); }

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() { return this->c.end(); }

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const { return this->c.begin(); }

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const { return this->c.end(); }

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() { return this->c.rbegin(); }

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() { return this->c.rend(); }

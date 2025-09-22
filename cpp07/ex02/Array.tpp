/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsayed <aelsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 03:25:17 by aelsayed          #+#    #+#             */
/*   Updated: 2025/09/22 03:45:11 by aelsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// Canonicals
template <typename T>
Array<T>::Array() : _data(new T[0]()), _size(0) {}

template <typename T>
Array<T>::~Array() { delete[] _data; }

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

template <typename T>
unsigned int Array<T>::size() const { return _size; }

template <typename T>
Array<T>::Array(const Array &other)	: _data(new T[other._size]()), _size(other._size)
{
	for (unsigned int i = 0; i < _size; ++i)
		_data[i] = other._data[i];
}


template <typename T>
Array<T>&	Array<T>::operator=(const Array<T> &other)
{
	if (this == &other)
		return *this;

	delete[] this->_data;

	_size = other._size;
	_data = new T[_size]();
	for (unsigned int i = 0; i < _size; ++i)
		_data[i] = other._data[i];

	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
	if (idx >= _size)
		throw std::out_of_range("Array index out of bounds");
	return _data[idx];
}

template <typename T>
const T& Array<T>::operator[](unsigned int idx) const
{
	if (idx >= _size)
		throw std::out_of_range("Array index out of bounds");
	return _data[idx];
}

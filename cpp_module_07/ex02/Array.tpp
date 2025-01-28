/*# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Array.tpp                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 18:43:46 by arybarsk          #+#    #+#              #
#    Updated: 2025/01/22 18:43:48 by arybarsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #*/

#include "Array.hpp"

template <typename T>
Array<T>::Array() : arrData(NULL), arrSize(0)
{
	std::cout << "Empty array constructed" << std::endl;
}

template <typename T>
Array<T>::Array(size_t n) : arrSize(n)
{
	arrData = new T[arrSize];
	for (size_t i = 0; i < arrSize; i++)
	{
		arrData[i] = T();
	}
	std::cout << "Array of T with size n constructed" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &source) : arrData(NULL),  arrSize(source.arrSize)
{
	if (source.arrData)
	{
		arrData = new T[arrSize];
		for (size_t i = 0; i < arrSize; i++)
		{
			arrData[i] = source.arrData[i];
		}
	}
	std::cout << "Array copy constructed" << std::endl;
}

template <typename T>
Array<T> &Array<T>::operator = (const Array &source)
{
	if (this != &source)
	{
		T *temp = new T[source.arrSize];
		delete[] arrData;
		arrSize = source.arrSize;
		arrData = temp;
		for (size_t i = 0; i < arrSize; i++)
		{
			arrData[i] = source.arrData[i];
		}
	}
	std::cout << "Array copy assigned" << std::endl;
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] arrData;
	std::cout << "Array destroyed" << std::endl;
}

template <typename T>
size_t Array<T>::size() const
{
	return (arrSize);
}

template <typename T>
T& Array<T>::operator [](size_t index)
{
	if (index >= arrSize)
	{
		throw std::out_of_range("Index out of range");
	}
	return (arrData[index]);
}

template <typename T>
const T& Array<T>::operator [](size_t index) const
{
	if (index >= arrSize)
	{
		throw std::out_of_range("Index out of range");
	}
	return (arrData[index]);
}

template <typename T>
void Array<T>::fillIncrementing(const T &value)
{
	for (size_t i=0; i < arrSize; i++)
	{
		arrData[i] = value + i;
	}
	std::cout << "Array filled" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:41:12 by arybarsk          #+#    #+#             */
/*   Updated: 2025/01/22 18:41:24 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	public:
		Array();
		Array(size_t n);
		Array(const Array &source);
		Array & operator = (const Array &source);
		~Array();
		
		size_t size() const;
		T& operator [](size_t index);
		const T& operator [](size_t index) const;
		
		void fillIncrementing(const T &value);
	private:
		T* arrData;
		size_t arrSize;
};

#include "Array.tpp"

#endif

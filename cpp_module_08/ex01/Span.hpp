/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:17:08 by arybarsk          #+#    #+#             */
/*   Updated: 2025/01/31 19:17:10 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

class Span
{
	public:
		Span(size_t N);
		Span(const Span &source);
		Span & operator = (const Span &source);
		~Span();
		
		void addNumber(const int number);
		size_t  shortestSpan() const;
		size_t  longestSpan() const;
		
		class noSpaceLeftException: public std::exception
		{
			virtual const char* what() const throw()
			{
				return ("Container is full");
			}
		};
		class notEnoughNumsException: public std::exception
		{
			virtual const char* what() const throw()
			{
				return ("Not enough numbers in container");
			}
		};
	private:
		size_t maxSize;
		std::multiset<int> numbers;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 19:17:14 by arybarsk          #+#    #+#             */
/*   Updated: 2025/01/31 19:17:16 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(size_t N): maxSize(N)
{
	//std::cout << "Span constructed" << std::endl;
}

Span::Span(const Span &source)
{
	*this = source;
}

Span & Span::operator = (const Span &source)
{
	if (this != &source)
	{
		this->maxSize = source.maxSize;
	}
	return (*this);
}

Span::~Span()
{
	//std::cout << "Span destroyed" << std::endl;
}

void Span::addNumber(const int number)
{
	if (numbers.size() >= maxSize)
		throw noSpaceLeftException();
	numbers.insert(number);
}

//std::transform(first1, last1, first2, output, binary_operation)
//ACTUALLY in this case:
//std::transform(first2, last1, first1, output, binary_operation)
//applies a binary operation to each pair of elements from two input ranges
//and stores the results in an output container

//std::back_inserter constructs a back-insert iterator that inserts
//new elements at the end of the container to which it is applied
size_t  Span::shortestSpan() const
{
	if (numbers.size() < 2)
		throw notEnoughNumsException();
		
	std::vector<int> spans;
	spans.reserve(numbers.size() - 1);
	
	std::multiset<int>::const_iterator it1 = numbers.begin();
	std::multiset<int>::const_iterator it2 = ++numbers.begin();
	
	std::transform(it2, numbers.end(), it1, std::back_inserter(spans), std::minus<int>());
	
	return (*std::min_element(spans.begin(), spans.end()));
}

size_t  Span::longestSpan() const
{
	if (numbers.size() < 2)
		throw notEnoughNumsException();
	return (*(--numbers.end()) - *numbers.begin());
}

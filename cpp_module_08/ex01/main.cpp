/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:34:27 by arybarsk          #+#    #+#             */
/*   Updated: 2025/01/07 14:34:30 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <fstream>
#include <limits.h>

// This function generates random values between o and INT_MAX
// by reading full 4 bytes of an int and returning its absolute value.
// In case of INT_MIN it calls itself recursively.

int getRandomVal()
{
	std::ifstream urandom("/dev/urandom", std::ios::binary);
	if (!urandom)
	{
		throw std::runtime_error("Could not open /dev/urandom");
	}
	int randomVal;
	urandom.read(reinterpret_cast<char*>(&randomVal), sizeof(randomVal));
	
	if (randomVal == INT_MIN)
		return (getRandomVal());
	if (randomVal < 0)
		randomVal = -randomVal;
	
	return (randomVal);
}

int main(void)
{	
	try
	{
		std::cout << "Testing small Span:" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		
		std::cout << "Testing large Span:" << std::endl;
		Span bigSpan = Span(20000);
		for (int i = 0; i < 20000; i++)
			bigSpan.addNumber(getRandomVal());
		std::cout << bigSpan.shortestSpan() << std::endl;
		std::cout << bigSpan.longestSpan() << std::endl;
		
		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}

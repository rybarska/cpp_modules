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

#include "Array.hpp"
#include "iter.hpp"

template <typename T>
void add1(T &val)
{
	val++;
}

template <typename T>
void add3(T &val)
{
	val += 3;
}

template <typename T>
void printElem(const T val)
{
	std::cout << val << std::endl;
}

int main(void)
{	
	try
	{
		Array<int> emptyArray;
		unsigned int n = 10;
		Array<double> arrayOfSizeN(n);
		std::cout << "Array size: " << arrayOfSizeN.size() << std::endl;
		double filler = 40;
		arrayOfSizeN.fillIncrementing(filler);
		std::cout << "5th element: " << arrayOfSizeN[4] << std::endl;
		std::cout << "Filled array: " << std::endl;
		::iter(arrayOfSizeN, printElem<double>);
		::iter(arrayOfSizeN, add3<double>);
		std::cout << "Array after call to add3: " << std::endl;
		::iter(arrayOfSizeN, printElem<double>);
		
		Array<double> copiedArray(arrayOfSizeN);
		std::cout << "Copied array: " << std::endl;
		::iter(copiedArray, printElem<double>);
		
		Array<double> anotherArray(n - 3);
		anotherArray.fillIncrementing(filler);
		anotherArray = arrayOfSizeN;
		std::cout << "Copy assigned array: " << std::endl;
		::iter(anotherArray, printElem<double>);
		
		return 0;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}

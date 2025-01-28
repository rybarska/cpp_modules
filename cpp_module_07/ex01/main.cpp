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
void printElem(T val)
{
	std::cout << val << std::endl;
}

int main(void)
{	
	try
	{
		double arr[4] = {40, 50, 60, 70};
		
		std::cout << "Original array: " << std::endl;
		::iter(arr, 4, printElem<double>);
		
		::iter(arr, 4, add1<double>);
		
		std::cout << "Array after call to incrementVal: " << std::endl;
		::iter(arr, 4, printElem<double>);
		
		::iter(arr, 4, add3<double>);
		
		std::cout << "Array after call to add3: " << std::endl;
		::iter(arr, 4, printElem<double>);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}

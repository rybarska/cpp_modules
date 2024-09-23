/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:24:46 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/22 22:24:48 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
	try
	{
		Point a(0, 0);
		Point b(6, 0);
		Point c(3, 6);
		Point point0(3, 3);
		Point point1(7, 8);
		Point point2(2, 3);
		Point point3(4, 1);
		Point point4(0, 8);
		bool result;

		result = bsp(a, b, c, point0);
		//result = bsp(a, b, c, point1);
		//result = bsp(a, b, c, point2);
		//result = bsp(a, b, c, point3);
		//result = bsp(a, b, c, point4);
		if (result)
			std::cout << "Bingo!" << std::endl;
		else
			std::cout << "It's a miss!" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}

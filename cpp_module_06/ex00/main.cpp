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

#include "ScalarConverter.hpp"

int main(void)
{	
	try
	{
		std::cout << "test z: " << std::endl;
		ScalarConverter::convert("z");
		
		std::cout << "test 42: " << std::endl;
		ScalarConverter::convert("42");
		
		std::cout << "test -42: " << std::endl;
		ScalarConverter::convert("-42");
		
		std::cout << "test 4200000000000000000000000: " << std::endl;
		ScalarConverter::convert("4200000000000000000000000");
		
		std::cout << "test 4200000000000000000000000000000000000000: " << std::endl;
		ScalarConverter::convert("4200000000000000000000000000000000000000");
		
		std::cout << "test 4.2e+2240: " << std::endl;
		ScalarConverter::convert("4.2e+2240");
		
		std::cout << "test inff: " << std::endl;
		ScalarConverter::convert("inff");
		
		std::cout << "test -inff: " << std::endl;
		ScalarConverter::convert("-inff");
		
		std::cout << "test nanf: " << std::endl;
		ScalarConverter::convert("nanf");
		
		std::cout << "test inf: " << std::endl;
		ScalarConverter::convert("inf");
		
		std::cout << "test -inf: " << std::endl;
		ScalarConverter::convert("-inf");
		
		std::cout << "test nan: " << std::endl;
		ScalarConverter::convert("nan");
		
		std::cout << "test whatchyalike: " << std::endl;
		ScalarConverter::convert("5555555555zzzzzzzzzz");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}

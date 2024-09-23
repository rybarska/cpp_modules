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

#include <iostream>
#include <string>

int main()
{
	try
	{
		std::string hi = "HI THIS IS BRAIN";
		std::string *stringPTR = &hi;
		std::string& stringREF = hi;
		
		std::cout << "The memory address of the string variable: " << &hi << std::endl;
		std::cout << "The memory address held by stringPTR: " << stringPTR << std::endl;
		std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
		
		std::cout << "The value of the string variable: " << hi << std::endl;
		std::cout << "The value pointed to by stringPTR: "<< *stringPTR << std::endl;
		std::cout << "The value pointed to by stringREF: "<< stringREF << std::endl;
		
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}

	return (0);
}

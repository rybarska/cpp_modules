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

#include "RPN.hpp"

bool isOnlyWhitespace(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		if (std::string(argv[i]).find_first_not_of(" \t\n\r") != std::string::npos)
			return (false);
	}
	return (true);
}

int main(int argc, char **argv)
{	
	try
	{
		if (argc < 2 || isOnlyWhitespace(argc, argv))
		{
			std::cerr << "Usage: ./RPN <num> <num> <operator> [... more nums and operators]" << std::endl;
			return (1);
		}
		RPN rpn;
		if (!rpn.processInput(argc, argv))
			return (1);
	}
	
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}

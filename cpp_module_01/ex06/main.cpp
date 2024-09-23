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

#include "Harl.hpp"

void checkArgs(int argc)
{
	if (argc != 2)
		throw std::invalid_argument("Usage: ./program_name complaint_level");
}

void	convertToUpper(std::string &level)
{
	int i = 0;
	while (level[i])
	{
		level[i] = std::toupper(static_cast<unsigned char>(level[i]));
		i++;
	}
}

int main(int argc, char **argv)
{	
	try
	{
		checkArgs(argc);
		
		Harl harl;
		std::string level = argv[1];
		convertToUpper(level);
		harl.complain(level);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}

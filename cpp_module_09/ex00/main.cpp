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

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{	
	try
	{
		if (argc != 2)
		{
			std::cerr << "Usage: ./btc <filename>" << std::endl;
			return (1);
		}
		BitcoinExchange crypto;
		if (crypto.processData("data.csv"))
			return (1);
		if (crypto.processInput(argv[1]))
			return (1);
	}
	
	catch (...)
	{
		std::cerr << "Unknown error" << std::endl;
		return (1);
	}
	
	return (0);
}

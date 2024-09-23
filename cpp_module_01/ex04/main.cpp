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

#include "replace.hpp"

int main(int argc, char **argv)
{	
	try
	{
		checkArgs(argc, argv);
		
		const std::string s1 = argv[2];
		const std::string s2 = argv[3];
		const bool replace = (s1 != s2);
		
		if (!replace)
		{
			std::cerr << "Warning: argv[2] and argv[3] are identical. No replacement will occur." << std::endl;
		}
		
		processFile(argv[1], s1, s2, replace);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}

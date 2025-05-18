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

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{	
	try
	{
		PmergeMe vecSort;
		
		if (vecSort.processInVec(argc, argv))
			return (1);
		
		PmergeMe deqSort;
		
		if (deqSort.processInDeq(argc, argv))
			return (1);
	}
	
	catch (...)
	{
		std::cerr << "Unknown error" << std::endl;
		return (1);
	}
	
	return (0);
}

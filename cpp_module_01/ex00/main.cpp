/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:28:48 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/21 17:28:52 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	try
	{
		Zombie* zombieOnTheHeap = newZombie("Joe Biden");
		
		zombieOnTheHeap->announce();
		
		delete zombieOnTheHeap;
		
		randomChump("Kenny");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}

	return (0);
}

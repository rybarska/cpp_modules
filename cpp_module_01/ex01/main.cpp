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
		int	N = 5;
		
		Zombie* aHordeOfZombies = zombieHorde(N, "lil sister");
		
		for (int i=0; i < N; i++)
			aHordeOfZombies[i].announce();
		
		delete[] aHordeOfZombies;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}

	return (0);
}

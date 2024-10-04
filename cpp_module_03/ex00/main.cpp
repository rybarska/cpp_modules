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

#include "ClapTrap.hpp"

int main(void)
{	
	try
	{
		ClapTrap claptrap("walkietalkie");
		claptrap.attack("aGuyPassingBy");
		claptrap.takeDamage(8);
		claptrap.beRepaired(5);
		claptrap.attack("aMaidInTheShade");
		claptrap.takeDamage(7);
		claptrap.beRepaired(5);
		claptrap.attack("aBroWithSomeDough");
		claptrap.takeDamage(9);
		claptrap.beRepaired(5);
		claptrap.takeDamage(5);
		claptrap.beRepaired(5);
		claptrap.takeDamage(5);
		claptrap.beRepaired(5);
		claptrap.takeDamage(5);
		claptrap.beRepaired(5);
		claptrap.takeDamage(5);
		claptrap.beRepaired(5);
		claptrap.attack("aNunWithAGun");
		claptrap.beRepaired(5);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}

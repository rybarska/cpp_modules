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
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{	
	try
	{
		ClapTrap claptrap("walkietalkie");
		claptrap.attack("aGuyPassingBy");
		claptrap.takeDamage(8);
		claptrap.beRepaired(5);
		claptrap.attack("aMaidInTheShade");
		
		ScavTrap scavtrap("GalaxyNote7");
		scavtrap.attack("aDudeThatWasRude");
		scavtrap.guardGate();
		
		FragTrap fragtrap("IED");
		//for (int i=0; i<101; i++)
			fragtrap.attack("aDameWithALongName");
		fragtrap.highFivesGuys();
		
		ScavTrap st("pager");
		//for (int i=0; i<101; i++)
			st.attack("aGramWithAPram");
		st.guardGate();
		
		DiamondTrap diamondtrap("kamikazeDrone");
		//for (int i=0; i<101; i++)
			diamondtrap.attack("aCrowdThatWasLoud");
		diamondtrap.takeDamage(8);
		diamondtrap.beRepaired(5);
		diamondtrap.guardGate();
		diamondtrap.highFivesGuys();
		diamondtrap.whoAmI();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}

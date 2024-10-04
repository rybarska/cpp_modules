/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 21:51:39 by arybarsk          #+#    #+#             */
/*   Updated: 2024/09/20 21:51:42 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &_name): ClapTrap(_name)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &source) : ClapTrap(source)
{
	*this = source;
}

ScavTrap & ScavTrap::operator = (const ScavTrap &source)
{
	if (this != &source)
	{
		ClapTrap::operator=(source);
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if ((getHitPoints() >= getAttackDamage()) && (getEnergyPoints() > 0))
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ScavTrap " << getName() << " attacks " 
			<< target << ", causing " 
			<<getAttackDamage() << " points of damage!" 
			<< std::endl;
	}
	else
		std::cout << "ScavTrap " << getName() << " has no energy points or hit points left to attack!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode." << std::endl;
}

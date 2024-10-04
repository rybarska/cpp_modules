/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:03:58 by arybarsk          #+#    #+#             */
/*   Updated: 2024/09/28 20:04:00 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &_name): ClapTrap(_name + "_clap_name"), ScavTrap(), FragTrap(), _name(_name)
{	
	std::cout << "DiamondTrap constructor called" << std::endl;
	std::cout << getHitPoints() << std::endl;
	std::cout << getEnergyPoints() << std::endl;
	std::cout << getAttackDamage() << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &source) : ClapTrap(source), ScavTrap(source), FragTrap(source)
{
	*this = source;
}

DiamondTrap & DiamondTrap::operator = (const DiamondTrap &source)
{
	if (this != &source)
	{
		ClapTrap::operator=(source);
		ScavTrap::operator=(source);
		FragTrap::operator=(source);
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::getName() << std::endl;
}

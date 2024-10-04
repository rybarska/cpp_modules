/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:54:40 by arybarsk          #+#    #+#             */
/*   Updated: 2024/09/28 18:54:42 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Default FragTrap constructor called" << std::endl;
	this->setHitPoints(100);
	this->setAttackDamage(30);
}

FragTrap::FragTrap(const std::string &_name): ClapTrap(_name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
	std::cout << this->FragTrap::getHitPoints() << std::endl;
	std::cout << this->FragTrap::getEnergyPoints() << std::endl;
	std::cout << this->FragTrap::getAttackDamage() << std::endl;
}

FragTrap::FragTrap(const FragTrap &source) : ClapTrap(source)
{
	*this = source;
}

FragTrap & FragTrap::operator = (const FragTrap &source)
{
	if (this != &source)
	{
		ClapTrap::operator=(source);
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if ((getHitPoints() >= getAttackDamage()) && (getEnergyPoints() > 0))
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "FragTrap " << getName() << " attacks " 
			<< target << ", causing " 
			<<getAttackDamage() << " points of damage!" 
			<< std::endl;
	}
	else
		std::cout << "FragTrap " << getName() << " has no energy points or hit points left to attack!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << getName() << " says: 'Gimme high fives guys!'" << std::endl;
}

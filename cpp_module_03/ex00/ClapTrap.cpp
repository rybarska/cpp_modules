/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:54:10 by arybarsk          #+#    #+#             */
/*   Updated: 2024/09/18 21:54:14 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &_name): _name(_name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source)
{
	*this = source;
}

ClapTrap & ClapTrap::operator = (const ClapTrap &source)
{
	if (this != &source)
	{
		this->_name = source._name;
		this->_hitPoints = source._hitPoints;
		this->_energyPoints = source._energyPoints;
		this->_attackDamage = source._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if ((this->_hitPoints >= this->_attackDamage) && (this->_energyPoints > 0))
	{
		(this->_energyPoints)--;
		std::cout << "ClapTrap " << this->_name << " attacks " 
			<< target << ", causing " 
			<< this->_attackDamage << " points of damage!" 
			<< std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has no energy points or hit points left to attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints >= static_cast<int>(amount))
	{
		(this->_hitPoints) -= amount;
		std::cout << "ClapTrap " << this->_name << " loses " << amount << " hit points!" << std::endl;
	}
	else if (this->_hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " loses " << this->_hitPoints << " hit points!" << std::endl;
		this->_hitPoints = 0;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has no hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if ((this->_energyPoints > 0))
	{
		(this->_hitPoints) += amount;
		(this->_energyPoints)--;
		std::cout << "ClapTrap " << this->_name << " is repaired and gets " << amount << " hit points!" << std::endl;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has no energy points left to be repaired!" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:54:03 by arybarsk          #+#    #+#             */
/*   Updated: 2024/09/18 21:54:05 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const std::string &_name);
		ClapTrap(const ClapTrap &source);
		ClapTrap & operator = (const ClapTrap &source);
		virtual ~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	protected:
		void setHitPoints(int hitPoints);
		void setEnergyPoints(int energyPoints);
		void setAttackDamage(int attackDamage);
		int getHitPoints() const;
		int getEnergyPoints() const;
		int getAttackDamage() const;
		std::string getName() const;
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;
};

#endif

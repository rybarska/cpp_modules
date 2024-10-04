/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:04:06 by arybarsk          #+#    #+#             */
/*   Updated: 2024/09/28 20:04:08 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(const std::string &_name);
		DiamondTrap(const DiamondTrap &source);
		DiamondTrap & operator = (const DiamondTrap &source);
		~DiamondTrap();
		void attack(const std::string& target);
		void whoAmI();
	private:
		std::string _name;
};

#endif

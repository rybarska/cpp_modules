/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 23:03:08 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/22 23:03:10 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : weapon(NULL), name(name) {}

HumanB::~HumanB() {}

void HumanB::setName(const std::string &name) { this->name = name; }

std::string HumanB::getName() const { return name; }

void HumanB::setWeapon(Weapon &weapon) { this->weapon = &weapon; }

void HumanB::attack()
{	
	if (weapon)
		std::cout << name << " attacks with " << weapon->getType() << std::endl;
	else
		std::cout << name << " is not armed! " << std::endl;
}


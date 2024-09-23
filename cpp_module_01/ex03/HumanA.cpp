/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 23:02:38 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/22 23:02:40 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon): weapon(weapon), name(name) {}

HumanA::~HumanA() {}

void HumanA::setName(const std::string &name) { this->name = name; }

std::string HumanA::getName() const { return name; }

void HumanA::attack()
{	
		std::cout << name << " attacks with " << weapon.getType() << std::endl;
}

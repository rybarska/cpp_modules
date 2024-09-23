/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:29:25 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/21 17:29:28 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{ /*std::cout << "A zombie was constructed." << std::endl;*/ }

Zombie::~Zombie()
{ std::cout << Zombie::name << " was destructed." << std::endl; }

void Zombie::announce( void )
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName() const { return name; }

void Zombie::setName(const std::string &name) { this->name = name; }

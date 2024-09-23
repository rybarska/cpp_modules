/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 23:02:28 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/22 23:02:29 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : type(type) {}

Weapon::~Weapon() {}

void Weapon::setType(const std::string &type) { this->type = type; }

std::string Weapon::getType() const { return type; }

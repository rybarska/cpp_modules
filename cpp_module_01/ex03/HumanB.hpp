/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 23:03:02 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/22 23:03:04 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(const std::string &name);
		~HumanB();
		void attack();
		void setName(const std::string &name);
		void setWeapon(Weapon &weapon);
		std::string getName() const;
	private:	
		Weapon *weapon;
		std::string name;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 23:02:50 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/22 23:02:55 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(const std::string &name, Weapon &weapon);
		~HumanA();
		void attack();
		void setName(const std::string &name);
		std::string getName() const;
	private:	
		Weapon &weapon;
		std::string name;
};

#endif

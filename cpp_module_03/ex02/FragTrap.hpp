/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:54:30 by arybarsk          #+#    #+#             */
/*   Updated: 2024/09/28 18:54:32 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
	FragTrap(const std::string &_name);
	FragTrap(const FragTrap &source);
	FragTrap & operator = (const FragTrap &source);
	~FragTrap();
	void attack(const std::string& target);
	void highFivesGuys(void);
};

#endif

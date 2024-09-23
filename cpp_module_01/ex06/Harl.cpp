/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:20:04 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/26 21:20:06 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug()
{
	std::cout << "[ DEBUG ] \n" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void Harl::info()
{
	std::cout << "[ INFO ] \n" << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning()
{
	std::cout << "[ WARNING ] \n" << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error()
{
	std::cout << "[ ERROR ] \n" << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::unknown()
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

Harl::ComplaintLevel Harl::StringToEnumValue(const std::string& level) const
{
	if (level == "DEBUG")
		return (DEBUG);
	if (level == "INFO")
		return (INFO);
	if (level == "WARNING")
		return (WARNING);
	if (level == "ERROR")
		return (ERROR);
	return (UNKNOWN);
}

void Harl::complain( std::string level )
{
	ComplaintLevel urgency = StringToEnumValue(level);
	
	switch (urgency)
	{
		case DEBUG:
			debug();
		case INFO:
			info();
		case WARNING:
			warning();
		case ERROR:
			error();
			break ;
		case UNKNOWN:
			unknown();
			break ;
	}
}

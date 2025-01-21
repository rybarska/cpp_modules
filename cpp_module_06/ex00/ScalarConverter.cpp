/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:09:40 by arybarsk          #+#    #+#             */
/*   Updated: 2025/01/14 14:09:43 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter constructed" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &source)
{
	*this = source;
}

ScalarConverter & ScalarConverter::operator = (const ScalarConverter &source)
{
	if (this != &source)
	{}
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destroyed" << std::endl;
}

void ScalarConverter::convert(const std::string &_name)
{
	if (_name.length() == 1 && std::isprint(_name[0]) && !std::isdigit(_name[0]))
	{
		char name_to_char = _name[0];
		int name_to_int = static_cast<int>(name_to_char);
		float name_to_float = static_cast<float>(name_to_char);
		double name_to_double = static_cast<double>(name_to_char);
		
		std::cout << "char: " << name_to_char << std::endl;
		std::cout << "int: " << name_to_int << std::endl;
		std::cout << "float: " << name_to_float << "f" << std::endl;
		std::cout << "double: " << name_to_double << std::endl;
	}
	else
	{
		char *end;
		double name_to_double = std::strtod(_name.c_str(), &end);
		if (_name != "inff" && _name != "-inff" && _name != "nanf" && *end != '\0')
		{
			std::cout << "Invalid argument: not a valid character or number" << std::endl;
			return ;
		}
		
		if (name_to_double >= 32 && name_to_double <= 126)
		{
			char name_to_char = static_cast<char>(name_to_double);
			std::cout << "char: " << name_to_char << std::endl;
		}
		else
		{
			std::cout << "char: non displayable" << std::endl;
		}
		
		if (name_to_double >= INT_MIN && name_to_double <= INT_MAX)
		{
			int name_to_int = static_cast<int>(name_to_double);
			std::cout << "int: " << name_to_int << std::endl;
		}
		else
		{
			std::cout << "int: impossible" << std::endl;
		}
		
		float name_to_float = static_cast<float>(name_to_double);
		std::cout << "float: " << name_to_float << "f" << std::endl;
		std::cout << "double: " << name_to_double << std::endl;
	}
}


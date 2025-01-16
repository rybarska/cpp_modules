/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:18:19 by arybarsk          #+#    #+#             */
/*   Updated: 2024/10/04 19:18:21 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
	std::cout << "Wrong Animal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &source)
{
	*this = source;
}

WrongAnimal & WrongAnimal::operator = (const WrongAnimal &source)
{
	if (this != &source)
	{
		this->type = source.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal sound" << std::endl;
}

const std::string WrongAnimal::getTypeWrong() const
{
	return (type);
}

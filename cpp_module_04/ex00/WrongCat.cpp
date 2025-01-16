/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:17:50 by arybarsk          #+#    #+#             */
/*   Updated: 2024/10/04 19:17:56 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &source) : WrongAnimal(source)
{
	*this = source;
}

WrongCat & WrongCat::operator = (const WrongCat &source)
{
	if (this != &source)
	{
		WrongAnimal::operator=(source);
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << this->type << ": Miaouuu!" << std::endl;
}

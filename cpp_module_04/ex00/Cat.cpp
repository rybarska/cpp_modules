/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:17:07 by arybarsk          #+#    #+#             */
/*   Updated: 2024/10/04 19:17:09 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &source) : Animal(source)
{
	*this = source;
}

Cat & Cat::operator = (const Cat &source)
{
	if (this != &source)
	{
		Animal::operator=(source);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << this->type << ": Miaouuu!" << std::endl;
}

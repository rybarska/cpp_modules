/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:16:35 by arybarsk          #+#    #+#             */
/*   Updated: 2024/10/04 19:16:37 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &source) : Animal(source)
{
	*this = source;
}

Dog & Dog::operator = (const Dog &source)
{
	if (this != &source)
	{
		Animal::operator=(source);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << this->type << ": Whooof!" << std::endl;
}

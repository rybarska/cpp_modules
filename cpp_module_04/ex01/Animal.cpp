/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:12:24 by arybarsk          #+#    #+#             */
/*   Updated: 2024/10/04 19:12:26 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &source)
{
	*this = source;
}

Animal & Animal::operator = (const Animal &source)
{
	if (this != &source)
	{
		this->type = source.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getIdea(int index) const
{
	(void)index;
	return ("No clue, default animal has no ideas");
}

const std::string Animal::getType() const
{
	return (type);
}

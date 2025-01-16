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
	this->_brain = new Brain;
	for (int i=0; i < 100; i++)
			this->_brain->_ideas[i] = "drink some milk";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &source) : Animal(source)
{
	this->type = source.type;
	this->_brain = new Brain(*source._brain);
	for (int i=0; i < 100; i++)
			this->_brain->_ideas[i] = "climb a tree";
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat & Cat::operator = (const Cat &source)
{
	if (this != &source)
	{
		this->type = source.type;
		delete this->_brain;
		this->_brain = new Brain(*source._brain);
		for (int i=0; i < 100; i++)
			this->_brain->_ideas[i] = "chase a bird";
	}
	return (*this);
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

std::string Cat::getIdea(int index) const
{
	return (this->_brain->_ideas[index]);
}

void Cat::makeSound() const
{
	std::cout << this->type << ": Miaouuu!" << std::endl;
}

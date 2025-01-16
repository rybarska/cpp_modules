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
	this->_brain = new Brain;
	for (int i=0; i < 100; i++)
		this->_brain->_ideas[i] = "fetch a ball";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &source) : Animal(source)
{
	this->type = source.type;
	this->_brain = new Brain(*source._brain);
	for (int i=0; i < 100; i++)
			this->_brain->_ideas[i] = "pee on a tree";
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog & Dog::operator = (const Dog &source)
{
	if (this != &source)
	{
		this->type = source.type;
		delete this->_brain;
		this->_brain = new Brain(*source._brain);
		for (int i=0; i < 100; i++)
			this->_brain->_ideas[i] = "chew a bone";
	}
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

std::string Dog::getIdea(int index) const
{
	return (this->_brain->_ideas[index]);
}

void Dog::makeSound() const
{
	std::cout << this->type << ": Whooof!" << std::endl;
}

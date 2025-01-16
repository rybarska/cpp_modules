/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:29:06 by arybarsk          #+#    #+#             */
/*   Updated: 2024/10/06 17:29:11 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	for (int i=0; i < 100; i++)
		this->_ideas[i] = "some idea";
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &source)
{
	*this = source;
}

Brain & Brain::operator = (const Brain &source)
{
	if (this != &source)
	{
		for (int i=0; i < 100; i++)
			this->_ideas[i] = source._ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

/*std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (_ideas[index]);
	else
		return ("Index must be between 0 and 99");
}*/

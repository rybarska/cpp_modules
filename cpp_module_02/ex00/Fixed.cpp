/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:32:22 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/30 14:32:25 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fpVal(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &source)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

Fixed & Fixed::operator = (const Fixed &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
		this->_fpVal = source.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits function called" << std::endl;
	return (this->_fpVal);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits function called" << std::endl;
	this->_fpVal = raw;
}

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

Fixed::Fixed(const int int_to_convert): _fpVal(int_to_convert << FRAC_BITS)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fp_to_convert): _fpVal(roundf(fp_to_convert * (1 << FRAC_BITS)))
{
	std::cout << "Float constructor called" << std::endl;
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
		this->_fpVal = source._fpVal;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
	return (_fpVal);
}

void Fixed::setRawBits( int const raw )
{
	_fpVal = raw;
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(_fpVal) / (1 << FRAC_BITS));
}

int Fixed::toInt( void ) const
{
	return (_fpVal >> FRAC_BITS);
}

std::ostream &operator<<(std::ostream &ostream, const Fixed &fixed)
{
	ostream << fixed.toFloat();
	return (ostream);
}

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

Fixed::Fixed(): _fpVal(0) {}

Fixed::Fixed(const int int_to_convert): _fpVal(int_to_convert << FRAC_BITS) {}

Fixed::Fixed(const float fp_to_convert): _fpVal(roundf(fp_to_convert * (1 << FRAC_BITS))) {}

Fixed::Fixed(const Fixed &source)
{
	*this = source;
}

Fixed & Fixed::operator = (const Fixed &source)
{
	if (this != &source)
		this->_fpVal = source._fpVal;
	return (*this);
}

Fixed::~Fixed() {}

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

bool Fixed::operator>(const Fixed &fixed) const
{
	return (_fpVal > fixed._fpVal);
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return (_fpVal < fixed._fpVal);
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (_fpVal >= fixed._fpVal);
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (_fpVal <= fixed._fpVal);
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return (_fpVal == fixed._fpVal);
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return (_fpVal != fixed._fpVal);
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed& Fixed::operator++()
{
	++_fpVal;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++_fpVal;
	return (temp);
}

Fixed& Fixed::operator--()
{
	--_fpVal;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	--_fpVal;
	return (temp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

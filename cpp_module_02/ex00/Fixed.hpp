/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:32:30 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/30 14:32:32 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &source);
		Fixed & operator = (const Fixed &source);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int _fpVal;
		static const int FRAC_BITS = 8;
};

#endif

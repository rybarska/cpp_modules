/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:24:46 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/22 22:24:48 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;
	/*std::cout << Fixed::min( a, b ) << std::endl;
	
	std::cout << Fixed::max( b, a ) << std::endl;
	std::cout << Fixed::min( b, a ) << std::endl;
	
	std::cout << Fixed::max( b, b ) << std::endl;
	std::cout << Fixed::min( b, b ) << std::endl;*/
	
	return 0;
}

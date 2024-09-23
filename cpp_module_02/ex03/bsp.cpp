/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:25:43 by arybarsk          #+#    #+#             */
/*   Updated: 2024/09/14 18:25:46 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

//area = 0.5 * |x1(y2-y3) + x2(y3-y1) + x3(y1-y2)|

Fixed	getTriangleArea(Point const one, Point const two, Point const three)
{
	Fixed x1 = one.getX();
	Fixed y1 = one.getY();
	Fixed x2 = two.getX();
	Fixed y2 = two.getY();
	Fixed x3 = three.getX();
	Fixed y3 = three.getY();
		
	Fixed absoluteValue = x1 * (y2-y3) + x2 * (y3-y1) + x3 * (y1-y2);
	if (absoluteValue < Fixed(0))
		absoluteValue = -absoluteValue;
	
	Fixed triangleArea = Fixed(0.5f) * absoluteValue;

	return (triangleArea);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed epsilon(0.01f);
	Fixed abcArea = getTriangleArea(a, b, c);
	Fixed pabArea = getTriangleArea(point, a, b);
	Fixed pacArea = getTriangleArea(point, a, c);
	Fixed pbcArea = getTriangleArea(point, b, c);
	
	Fixed sum = pabArea + pacArea + pbcArea;
	
	Fixed difference = Fixed::max(sum, abcArea) - Fixed::min(sum, abcArea);

	if (difference < epsilon)
		return (true);
	else
		return (false);
}

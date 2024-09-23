/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:25:31 by arybarsk          #+#    #+#             */
/*   Updated: 2024/09/14 18:25:32 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const float fp_1, const float fp_2): _x(fp_1), _y(fp_2) {}

Point::Point(const Point &source): _x(source._x), _y(source._y) {}

Point & Point::operator = (const Point &source) throw()
{
	(void) source;
	return (*this);
}

Point::~Point() {}

Fixed Point::getX() const
{
	return (_x);
}

Fixed Point::getY() const
{
	return (_y);
}

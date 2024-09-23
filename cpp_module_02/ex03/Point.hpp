/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:25:19 by arybarsk          #+#    #+#             */
/*   Updated: 2024/09/14 18:25:22 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float fp_1, const float fp_2);
		Point(const Point &source);
		Point & operator = (const Point &source) throw();
		~Point();
		
		Fixed getX() const;
		Fixed getY() const;
	private:
		const Fixed _x;
		const Fixed _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif

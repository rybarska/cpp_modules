/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:02:03 by arybarsk          #+#    #+#             */
/*   Updated: 2025/01/22 13:02:05 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &input1, T &input2)
{
	T temp = input1;
	input1 = input2;
	input2 = temp;
}

template <typename T>
T min(T &input1, T &input2)
{
	if (input1 < input2)
		return (input1);
	return (input2);
}

template <typename T>
T max(T &input1, T &input2)
{
	if (input1 > input2)
		return (input1);
	return (input2);
}

#endif

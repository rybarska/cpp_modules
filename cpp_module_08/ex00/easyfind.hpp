/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:01:09 by arybarsk          #+#    #+#             */
/*   Updated: 2025/01/31 17:01:13 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

class noFindException: public std::exception
{
	virtual const char* what() const throw()
	{
		return ("Value not found in container");
	}
};

template <typename T>
void easyfind(T &container, const int to_find)
{

	typename T::iterator it = std::find(container.begin(), container.end(), to_find);
	
	if (it == container.end())
		throw noFindException();
	else
		std::cout << to_find << " found in container at index " 
			<< std::distance(container.begin(), it) << std::endl;
}

template <typename T>
void easyfind(const T &container, const int to_find)
{

	typename T::const_iterator it = std::find(container.begin(), container.end(), to_find);
	
	if (it == container.end())
		throw noFindException();
	else
		std::cout << to_find << " found in container at index " 
			<< std::distance(container.begin(), it) << std::endl;
}

#endif

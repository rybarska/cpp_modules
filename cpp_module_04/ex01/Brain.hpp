/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:29:23 by arybarsk          #+#    #+#             */
/*   Updated: 2024/10/06 17:29:24 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain &source);
		Brain & operator = (const Brain &source);
		~Brain();
		//std::string getIdea(int index) const;
		std::string _ideas[100];
};

#endif

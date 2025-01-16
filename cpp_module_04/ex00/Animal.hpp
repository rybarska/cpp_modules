/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:12:17 by arybarsk          #+#    #+#             */
/*   Updated: 2024/10/04 19:12:19 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Animal
{
	public:
		Animal();
		Animal(const Animal &source);
		Animal & operator = (const Animal &source);
		virtual ~Animal();
		virtual void makeSound() const;
		const std::string getType() const;
	protected:
		std::string type;
};

#endif

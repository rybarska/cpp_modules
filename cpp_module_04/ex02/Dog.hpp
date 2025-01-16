/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:16:43 by arybarsk          #+#    #+#             */
/*   Updated: 2024/10/04 19:16:49 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &source);
		Dog & operator = (const Dog &source);
		~Dog();
		virtual std::string getIdea(int index) const;
		void makeSound() const;
	private:
		Brain* _brain;
};

#endif

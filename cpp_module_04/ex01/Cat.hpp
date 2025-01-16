/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:16:57 by arybarsk          #+#    #+#             */
/*   Updated: 2024/10/04 19:16:58 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &source);
		Cat & operator = (const Cat &source);
		~Cat();
		std::string getIdea(int index) const;
		void makeSound() const;
	private:
		Brain* _brain;
};

#endif

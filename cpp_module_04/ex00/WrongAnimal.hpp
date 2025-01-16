/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:18:13 by arybarsk          #+#    #+#             */
/*   Updated: 2024/10/04 19:18:15 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &source);
		WrongAnimal & operator = (const WrongAnimal &source);
		virtual ~WrongAnimal();
		void makeSound() const;
		const std::string getTypeWrong() const;
	protected:
		std::string type;
};

#endif

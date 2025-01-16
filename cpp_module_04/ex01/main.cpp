/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:24:46 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/22 22:24:48 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void)
{	
	try
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << "Dog's idea 0: " << j->getIdea(0) << std::endl;
		std::cout << "Cat's idea 0: " << i->getIdea(0) << std::endl;
		
		const Animal* animalHorde[10];
		
		for (int k=0; k < 5; k++)
			animalHorde[k] = new Dog(*static_cast<const Dog*>(j));
		for (int k=5; k < 10; k++)
		{
			animalHorde[k] = new Cat(*static_cast<const Cat*>(i));
		}
		for (int k=0; k < 10; k++)
			std::cout << "type: " << animalHorde[k]->getType() << std::endl;
		
		for (int k=0; k < 10; k++)
			std::cout << "idea: " << animalHorde[k]->getIdea(k) << std::endl;
		
		
		for (int k=0; k < 10; k++)
			delete animalHorde[k];
		
		Dog doggy;
		doggy = *static_cast<const Dog*>(j);
		std::cout << "doggy's idea 0: " << doggy.getIdea(0) << std::endl;
			
		delete j;
		delete i;
			
	
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}

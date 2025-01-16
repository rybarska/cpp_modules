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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{	
	try
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		const WrongAnimal* dangerWaterCow = new WrongAnimal();
		const WrongAnimal* catAclysm = new WrongCat();
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		std::cout << catAclysm->getTypeWrong() << " " << std::endl;
		dangerWaterCow->makeSound();
		catAclysm->makeSound();
		delete(j);
		delete(i);
		delete(meta);
		delete(dangerWaterCow);
		delete(catAclysm);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}

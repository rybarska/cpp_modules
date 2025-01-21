/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:34:27 by arybarsk          #+#    #+#             */
/*   Updated: 2025/01/07 14:34:30 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <fstream>

int getRandomVal()
{
	std::ifstream urandom("/dev/urandom", std::ios::binary);
	if (!urandom)
	{
		throw std::runtime_error("Could not open /dev/urandom");
	}
	unsigned char randomVal;
	urandom.read(reinterpret_cast<char*>(&randomVal), sizeof(randomVal));
	return (randomVal % 3);
}

Base * generate(void)
{
	int randomInt = getRandomVal();
	
	if (randomInt == 0)
	{
		std::cout << "Class instantiated: A" << std::endl;
		return new A();
	}
	else if (randomInt == 1)
	{
		std::cout << "Class instantiated: B" << std::endl;
		return new B();
	}
	else if (randomInt == 2)
	{
		std::cout << "Class instantiated: C" << std::endl;
		return new C();
	}
	else
		return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Class identified as: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class identified as: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class identified as: C" << std::endl;
	else
		std::cerr << "Error: no class identified" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)(dynamic_cast<A&>(p));
		std::cout << "Class identified as: A" << std::endl;
		return ;
	}
	catch (const std::bad_cast &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	try
	{
		(void)(dynamic_cast<B&>(p));
		std::cout << "Class identified as: B" << std::endl;
		return ;
	}
	catch (const std::bad_cast &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	
	try
	{
		(void)(dynamic_cast<C&>(p));
		std::cout << "Class identified as: C" << std::endl;
		return ;
	}
	catch (const std::bad_cast &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cerr << "Error: no class identified" << std::endl;
}

int main(void)
{	
	try
	{
		Base *inst = generate();
		if (!inst)
		{
			std::cerr << "Error: no class instantiated" << std::endl;
			return (1);
		}
		identify(inst);
		identify(*inst);
		delete(inst);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}

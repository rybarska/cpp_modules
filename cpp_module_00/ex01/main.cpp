/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 23:05:15 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/17 23:05:17 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	try
	{
		PhoneBook phoneBook;
	
		while (std::cin.good())
			phoneBook.chooseAction();
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Runtime error: " << e.what() << std::endl;
		return (1);
	}
	catch (const std::exception&)
	{
		return (0);
	}

	return (0);
}

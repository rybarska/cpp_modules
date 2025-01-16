/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:31:35 by arybarsk          #+#    #+#             */
/*   Updated: 2025/01/12 17:31:39 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern constructed" << std::endl;
}

Intern::Intern(const Intern &source)
{
	*this = source;
}

Intern & Intern::operator = (const Intern &source)
{
	if (this != &source)
	{
		;
	}
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destroyed" << std::endl;
}

AForm* Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
	typedef AForm* (*MakeFormFunction)(const std::string &target);
	
	struct FormConstructor
	{
		std::string formName;
		MakeFormFunction make;
	};
	
	FormConstructor handlers[] =
	{
		{"presidential pardon", &PresidentialPardonForm::make}, 
		{"robotomy request", &RobotomyRequestForm::make},
		{"shrubbery creation", &ShrubberyCreationForm::make},
	};
	
	for (int i = 0; i < 3; i++)
	{
		if (handlers[i].formName == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return handlers[i].make(formTarget);
		}
			
	}
	std::cout << "Error: Intern could not create " << formName << " because of wrong form name" << std::endl;
	return (NULL);
}

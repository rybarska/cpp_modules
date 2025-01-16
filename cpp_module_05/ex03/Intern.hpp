/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:31:25 by arybarsk          #+#    #+#             */
/*   Updated: 2025/01/12 17:31:31 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Bureaucrat;
class AForm;
class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

class Intern
{
	public:
		Intern();
		Intern(const Intern &source);
		Intern & operator = (const Intern &source);
		~Intern();
		AForm* makeForm(const std::string &formName, const std::string &formTarget);
};

#endif

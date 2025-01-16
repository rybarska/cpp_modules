/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:34:51 by arybarsk          #+#    #+#             */
/*   Updated: 2025/01/07 14:34:53 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
AForm("PresidentialPardonForm", 25, 5), 
_target(target)
{
	std::cout << "PresidentialPardonForm constructed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &source):
AForm(source), 
_target(source._target)
{
	std::cout << "Copy constructor for PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator = (const PresidentialPardonForm &source)
{
	if (this != &source)
	{
		setSignedStatus(source.getSignedStatus());
	}
	std::cout << "Copy assignment operator for PresidentialPardonForm called" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destroyed" << std::endl;
}

bool PresidentialPardonForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > getGradeReqToSign())
	{
		throw GradeTooLowException();
		return (false);
	}
	else
	{
		setSignedStatus(true);
		return (true);
	}
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > getGradeReqToExec())
	{
		throw GradeTooLowException();
	}
	else if (!getSignedStatus())
	{
		throw FormNotSignedException();
	}
	else
	{
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
}

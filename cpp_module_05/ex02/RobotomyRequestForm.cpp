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

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
AForm("RobotomyRequestForm", 72, 45), 
_target(target)
{
	std::cout << "RobotomyRequestForm constructed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source):
AForm(source), 
_target(source._target)
{
	std::cout << "Copy constructor for RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator = (const RobotomyRequestForm &source)
{
	if (this != &source)
	{
		setSignedStatus(source.getSignedStatus());
	}
	std::cout << "Copy assignment operator for RobotomyRequestForm called" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destroyed" << std::endl;
}

bool RobotomyRequestForm::getRandomBool() const
{
	std::ifstream urandom("/dev/urandom", std::ios::binary);
	if (!urandom)
	{
		throw std::runtime_error("Could not open /dev/urandom");
	}
	unsigned char randomVal;
	urandom.read(reinterpret_cast<char*>(&randomVal), sizeof(randomVal));
	return (randomVal % 2 == 0);
}

bool RobotomyRequestForm::beSigned(const Bureaucrat &bureaucrat)
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

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
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
		std::cout << "Vrrr-vrr-vrrrrrrrrrr" << std::endl;
		if (getRandomBool())
			std::cout << _target << " has been robotomized successfully" << std::endl;
		else
			std::cout << "Robotomy failed" << std::endl;	
	}
}

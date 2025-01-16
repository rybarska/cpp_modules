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

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string &_name, int _grade): _name(_name), _grade(_grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat constructed, name: " << _name << ", grade: " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &source)
{
	*this = source;
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat &source)
{
	if (this != &source)
	{
		this->_grade = source._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destroyed, name: " << _name << ", grade: " << _grade << std::endl;
}

const std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	else if (_grade < 1)
		throw GradeTooHighException();
	_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed form " << form << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed form " << form << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << _name << " couldn't execute " << form << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat)
{
	ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (ostream);
}

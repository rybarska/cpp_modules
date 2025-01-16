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

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
AForm("ShrubberyCreationForm", 145, 137),
_target(target)
{
	std::cout << "ShrubberyCreationForm constructed" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &source):
AForm(source), 
_target(source._target)
{
	std::cout << "Copy constructor for ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator = (const ShrubberyCreationForm &source)
{
	if (this != &source)
	{
		setSignedStatus(source.getSignedStatus());
	}
	std::cout << "Copy assignment operator for ShrubberyCreationForm called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destroyed" << std::endl;
}

bool ShrubberyCreationForm::beSigned(const Bureaucrat &bureaucrat)
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

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
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
		char cwd[PATH_MAX];
		if (getcwd(cwd, sizeof(cwd)) == NULL)
			return;
		else
		{
			std::string fileName = std::string(cwd) + "/" + _target + "_shrubbery";
			std::ofstream outfile((fileName).c_str());
			if (!outfile.is_open())
			{
				std::cerr << "error opening file " << std::endl;
				return;
			}
			else
			{
				std::cout << "Opening file: " << (_target + "_shrubbery") << std::endl;

			}
			outfile << " | ||| | " << " | ||| | " << " | ||| | " << std::endl;
			outfile << "  | | |  " << "  | | |  " << "  | | |  " << std::endl;
			outfile << "   |||   " << "   |||   " << "   |||   " << std::endl;
			outfile << "    |    " << "    |    " << "    |    " << std::endl;
			outfile << "    |    " << "    |    " << "    |    " << std::endl;
			outfile << "    |    " << "    |    " << "    |    " << std::endl;
			outfile << "    |    " << "    |    " << "    |    " << std::endl;
			outfile << "    |    " << "    |    " << "    |    " << std::endl;
			outfile.close();
		}
	}
}

AForm* ShrubberyCreationForm::make(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

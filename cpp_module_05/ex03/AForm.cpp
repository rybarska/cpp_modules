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

#include "AForm.hpp"

//AForm::AForm(){}

AForm::AForm(const std::string &_formName, int _gradeReqToSign, int _gradeReqToExec): _formName(_formName),
_signed(false),
_gradeReqToSign(_gradeReqToSign),
_gradeReqToExec(_gradeReqToExec)
{
	if (_gradeReqToSign < 1 || _gradeReqToExec < 1 )
		throw GradeTooHighException();
	else if (_gradeReqToSign > 150 || _gradeReqToExec > 150)
		throw GradeTooLowException();
	std::cout << "Form constructed, form name: " << _formName << ", signed: " << _signed << ", gradeReqToSign: " << _gradeReqToSign << ", gradeReqToExec: " << _gradeReqToExec << std::endl;
}

AForm::AForm(const AForm &source):
_formName(source._formName),
_signed(source._signed),
_gradeReqToSign(source._gradeReqToSign),
_gradeReqToExec(source._gradeReqToExec)
{
	std::cout << "Copy constructor called, form name: " << _formName << std::endl;
}

AForm & AForm::operator = (const AForm &source)
{
	if (this != &source)
	{
		this->_signed = source._signed;
	}
	std::cout << "Copy assignment operator called, form name: " << _formName << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "Form destroyed, form name: " << _formName << std::endl;
}

const std::string AForm::getFormName() const
{
	return (_formName);
}

bool AForm::getSignedStatus() const
{
	return (_signed);
}

void AForm::setSignedStatus(bool sign)
{
	_signed = sign;
}

int AForm::getGradeReqToSign() const
{
	return (_gradeReqToSign);
}

int AForm::getGradeReqToExec() const
{
	return (_gradeReqToExec);
}

bool AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeReqToSign)
	{
		throw GradeTooLowException();
		return (false);
	}
	_signed = true;
	return (true);
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > _gradeReqToExec)
	{
		throw GradeTooLowException();
	}
	if (_signed == false)
	{
		throw FormNotSignedException();
	}
	/* do something something */
}

std::ostream &operator<<(std::ostream &ostream, const AForm &form)
{
	ostream << form.getFormName() << ", form gradeReqToSign " << form.getGradeReqToSign() << ", form gradeReqToExec " << form.getGradeReqToExec() << ", form signed " << form.getSignedStatus();
	return (ostream);
}

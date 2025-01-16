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

#include "Form.hpp"

Form::Form(const std::string &_formName, int _gradeReqToSign, int _gradeReqToExec): _formName(_formName),
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

Form::Form(const Form &source):
_formName(source._formName),
_signed(source._signed),
_gradeReqToSign(source._gradeReqToSign),
_gradeReqToExec(source._gradeReqToExec)
{
	std::cout << "Copy constructor called, form name: " << _formName << std::endl;
}

Form & Form::operator = (const Form &source)
{
	if (this != &source)
	{
		this->_signed = source._signed;
	}
	std::cout << "Copy assignment operator called, form name: " << _formName << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destroyed, form name: " << _formName << std::endl;
}

const std::string Form::getFormName() const
{
	return (_formName);
}

bool Form::getSignedStatus() const
{
	return (_signed);
}

int Form::getGradeReqToSign() const
{
	return (_gradeReqToSign);
}

int Form::getGradeReqToExec() const
{
	return (_gradeReqToExec);
}

bool Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeReqToSign)
	{
		throw GradeTooLowException();
		return (false);
	}
	_signed = true;
	return (true);
}

std::ostream &operator<<(std::ostream &ostream, const Form &form)
{
	ostream << form.getFormName() << ", form gradeReqToSign " << form.getGradeReqToSign() << ", form gradeReqToExec " << form.getGradeReqToExec() << ", form signed " << form.getSignedStatus();
	return (ostream);
}

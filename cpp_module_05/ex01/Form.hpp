/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:35:00 by arybarsk          #+#    #+#             */
/*   Updated: 2025/01/07 14:35:02 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(const std::string &_formName, int _gradeReqToSign, int _gradeReqToExec);
		Form(const Form &source);
		Form & operator = (const Form &source);
		~Form();
		const std::string getFormName() const;
		bool getSignedStatus() const;
		int getGradeReqToSign() const;
		int getGradeReqToExec() const;
		bool beSigned(const Bureaucrat &bureaucrat);
		class GradeTooHighException: public std::exception
		{
			virtual const char* what() const throw()
			{
				return "grade too high";
			}
		};
		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw()
			{
				return "grade too low";
			}
		};
	private:
		const std::string _formName;
		bool _signed;
		const int _gradeReqToSign;
		const int _gradeReqToExec;
};

std::ostream &operator<<(std::ostream &ostream, const Form &form);

#endif

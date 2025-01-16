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

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(const std::string &_formName, int _gradeReqToSign, int _gradeReqToExec);
		AForm(const AForm &source);
		AForm & operator = (const AForm &source);
		virtual ~AForm();
		const std::string getFormName() const;
		bool getSignedStatus() const;
		void setSignedStatus(bool sign);
		int getGradeReqToSign() const;
		int getGradeReqToExec() const;
		virtual bool beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
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
		class FormNotSignedException: public std::exception
		{
			virtual const char* what() const throw()
			{
				return "form not signed";
			}
		};
	private:
		const std::string _formName;
		bool _signed;
		const int _gradeReqToSign;
		const int _gradeReqToExec;
};

std::ostream &operator<<(std::ostream &ostream, const AForm &form);

#endif

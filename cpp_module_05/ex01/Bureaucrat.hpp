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

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(const std::string &_name, int _grade);
		Bureaucrat(const Bureaucrat &source);
		Bureaucrat & operator = (const Bureaucrat &source);
		virtual ~Bureaucrat();
		const std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form &form);
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
		const std::string _name;
		int _grade;
};

std::ostream &operator<<(std::ostream &ostream, const Bureaucrat &bureaucrat);

#endif

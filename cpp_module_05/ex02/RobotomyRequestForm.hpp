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

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &source);
		RobotomyRequestForm & operator = (const RobotomyRequestForm &source);
		~RobotomyRequestForm();
		bool beSigned(const Bureaucrat &bureaucrat);
		void execute(Bureaucrat const & executor) const;
		bool getRandomBool() const;
	private:
		const std::string _target;
};

#endif

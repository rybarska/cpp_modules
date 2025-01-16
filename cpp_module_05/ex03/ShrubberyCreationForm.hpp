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

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <limits.h>
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &source);
		ShrubberyCreationForm & operator = (const ShrubberyCreationForm &source);
		~ShrubberyCreationForm();
		bool beSigned(const Bureaucrat &bureaucrat);
		void execute(Bureaucrat const & executor) const;
		static AForm* make(const std::string &target);
	private:
		const std::string _target;
};

#endif

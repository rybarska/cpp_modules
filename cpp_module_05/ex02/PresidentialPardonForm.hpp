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

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &source);
		PresidentialPardonForm & operator = (const PresidentialPardonForm &source);
		~PresidentialPardonForm();
		bool beSigned(const Bureaucrat &bureaucrat);
		void execute(Bureaucrat const & executor) const;
	private:
		const std::string _target;
};

#endif

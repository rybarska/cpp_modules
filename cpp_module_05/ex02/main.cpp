/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:34:27 by arybarsk          #+#    #+#             */
/*   Updated: 2025/01/07 14:34:30 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{	
	try
	{
		Bureaucrat t("T", 145);
		t.decrementGrade();
		t.decrementGrade();
		t.decrementGrade();
		t.decrementGrade();
		t.decrementGrade();
		
		Bureaucrat b("B", 5);
		b.incrementGrade();
		b.incrementGrade();
		b.incrementGrade();
		b.incrementGrade();
		
		std::cout << t << std::endl;
		std::cout << b << std::endl;
		
		/*AForm form("F", 5, 10);
		AForm glah("G", 5, 10);
		
		std::cout << form << std::endl;
		std::cout << glah << std::endl;
		
		b.signForm(form);
		
		std::cout << form << std::endl;
		
		t.signForm(glah);*/
		
		PresidentialPardonForm p("Hunter");
		t.signForm(p);
		b.executeForm(p);
		
		ShrubberyCreationForm s("Sahara");
		b.signForm(s);
		b.executeForm(s);
		
		RobotomyRequestForm e("Elon");
		b.signForm(e);
		b.executeForm(e);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}

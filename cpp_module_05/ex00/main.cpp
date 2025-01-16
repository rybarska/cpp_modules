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
		//b.incrementGrade();
		
		std::cout << t << std::endl;
		std::cout << b << std::endl;
		
		//Bureaucrat d("D", 1);
		//d.incrementGrade();
		//Bureaucrat f("F", 150);
		//f.decrementGrade();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}

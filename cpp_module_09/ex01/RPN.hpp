/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:40:59 by arybarsk          #+#    #+#             */
/*   Updated: 2025/03/22 21:41:02 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <list>
#include <exception>
#include <cmath>

#define RESET	"\033[0m"
#define RED	"\033[31m"
#define YELLOW	"\033[33m"

class RPN
{
	public:
		RPN();
		RPN(const RPN &source);
		RPN & operator = (const RPN &source);
		~RPN();
		bool processInput(int argc, char **argv);
	private:
		std::list<double> operands;
		std::list<std::string> tokens;
		void getTokens(int argc, char **argv);
		bool isValidOperator(const std::string &str);
		bool pushResultToList(std::string token);
		bool pushNumToList(std::string token);
		double executeOperation(double num1, double num2, char op);
};

#endif

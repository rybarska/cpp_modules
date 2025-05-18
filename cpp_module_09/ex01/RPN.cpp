/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:40:50 by arybarsk          #+#    #+#             */
/*   Updated: 2025/03/22 21:40:54 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	//std::cout << "RPN constructed" << std::endl;
}

RPN::RPN(const RPN &source)
{
	*this = source;
}

RPN & RPN::operator = (const RPN &source)
{
	if (this != &source)
	{
		this->operands = source.operands;
		this->tokens = source.tokens;
	}
	return (*this);
}

RPN::~RPN()
{
	//std::cout << "BitcoinExchange destroyed" << std::endl;
}

void RPN::getTokens(int argc, char **argv)
{
	if (argc == 2)
	{
		std::istringstream iss(argv[1]);
		std::string token;
		while (iss >> token)
			tokens.push_back(token);
	}
	else
	{
		for (int i = 1; i < argc; i++)
			tokens.push_back(argv[i]);
	}
}

bool RPN::isValidOperator(const std::string &str)
{
	return (str == "+" || str == "-" || str == "/" || str == "*");
}

double RPN::executeOperation(double num1, double num2, char op)
{
	double opResult;
	if (op == '+')
		opResult = num1 + num2;
	else if (op == '-')
		opResult = num1 - num2;
	else if (op == '*')
		opResult = num1 * num2;
	else if (op == '/')
	{
		if (num2 == 0)
			throw std::runtime_error("Error: dividing by zero");
		opResult = num1 / num2;
	}
	else
		throw std::runtime_error("Error: bad operator");
	if (std::isinf(opResult))
		throw std::runtime_error("Error: result is infinite (overflow)");
	if (std::isnan(opResult))
		throw std::runtime_error("Error: result is NaN");
	return (opResult);
}

bool RPN::pushResultToList(std::string token)
{
	if (operands.size() < 2)
	{
		std::cerr << RED << "Error: bad RPN expression: not enough operands for: " << token << RESET << std::endl;
		return (false);
	}
	double num2 = operands.back();
	operands.pop_back();
	double num1 = operands.back();
	operands.pop_back();
	double result = executeOperation(num1, num2, token[0]);
	operands.push_back(result);
	return (true);
}

bool RPN::pushNumToList(std::string token)
{
	std::istringstream iss(token);
	double num;
	iss >> num;
	if (!iss.eof() || iss.fail())
	{
		std::cerr << RED << "Error: bad token" << RESET << std::endl;
		return (false);
	}
	operands.push_back(num);
	return (true);
}

bool RPN::processInput(int argc, char **argv)
{
	tokens.clear();
	operands.clear();
	
	getTokens(argc, argv);
	
	for (std::list<std::string>::iterator it = tokens.begin(); it != tokens.end(); ++it)
	{
		std::string token = *it;
		if (isValidOperator(token))
		{
			if (!pushResultToList(token))
				return (false);
		}
		else 
		{
			if (!pushNumToList(token))
				return (false);
		}
	}
	if (operands.size() > 1)
	{
		std::cerr << RED << "Error: bad RPN expression (more than 1 operand left)" << RESET << std::endl;
		return (false);
	}
	if (!operands.empty())
		std::cout << "Result: " << operands.back() << std::endl;
	return (true);
}

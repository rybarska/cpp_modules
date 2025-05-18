/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:06:50 by arybarsk          #+#    #+#             */
/*   Updated: 2025/02/24 18:06:52 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	//std::cout << "PmergeMe constructed" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &source)
{
	*this = source;
}

PmergeMe & PmergeMe::operator = (const PmergeMe &source)
{
	if (this != &source)
	{
		inputVec = source.inputVec;
		resultVec = source.resultVec;
		vec3D = source.vec3D;
		inputDeq = source.inputDeq;
		resultDeq = source.resultDeq;
		deq3D = source.deq3D;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	//std::cout << "PmergeMe destroyed" << std::endl;
}

const char* tooManyArgsException::what() const throw()
{
	return ("Error: Too many arguments (max amount: 3000)");
}

bool PmergeMe::isArgcValid(int argc)
{
	const int MAX_ARGS = 3000 + 1;
	if (argc < 2)
	{
		std::cerr << "Usage: ./PmergeMe <positive ints>..." << std::endl;
		return (false);
	}
	if (argc > MAX_ARGS)
	{
		std::cerr << "Error: too many args to handle" << std::endl;
		return (false);
	}
	return (true);
}

bool PmergeMe::isPositiveInt(const std::string &str, int &num)
{
	if (str.empty())
		return (false);
	
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	
	std::istringstream iss(str);
	iss >> num;
	
	if (!iss.eof() || iss.fail() || num <= 0)
		return (false);
	
	return (true);
}

void PmergeMe::getNextJacobstahl(int &k, int &JS)
{
	JS = pow(2, k + 1) - JS;
	k++;
}

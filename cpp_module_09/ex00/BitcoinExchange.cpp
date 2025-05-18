/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:33:34 by arybarsk          #+#    #+#             */
/*   Updated: 2025/03/22 21:33:37 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &source)
{
	*this = source;
}

BitcoinExchange & BitcoinExchange::operator = (const BitcoinExchange &source)
{
	if (this != &source)
	{
		this->data = source.data;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::printData(void)
{
	for (std::map<std::string, double>::const_iterator it = data.begin(); it != data.end(); it++)
	{
		std::cout << it->first << " => " << it->second << std::endl;
	}
}

bool BitcoinExchange::isDateInFuture(int year, int month, int day)
{
	int inputPacked = year * 10000 + month * 100 + day;
	
	std::time_t now = std::time(NULL);
	std::tm *timeNow = std::localtime(&now);
	
	int currentPacked = (timeNow->tm_year + 1900) * 10000 + (timeNow->tm_mon + 1) * 100 + timeNow->tm_mday;
	
	if (inputPacked > currentPacked)
		return (true);
	return (false);
}

bool BitcoinExchange::isDateValid(int year, int month, int day)
{
	if (year < 2009 || year > 2025 || month < 1 || month > 12 || day < 1 || day > 31)
		return (false);
		
	if (month == 2)
	{
		if (day > 29 || (day > 28 && !(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))))
		return (false);
	}
	
	if (day > 30)
	{
		if (month == 4 || month == 6 || month == 9 || month == 11)
			return (false);
	}
	
	return (true);
}

bool BitcoinExchange::isDateFormatted(const std::string &dateStr)
{
	if (dateStr.length() != 10)
		return (false);
	int expectedDigitPositions[] = {0, 1, 2, 3, 5, 6, 8, 9};
	for (int i = 0; i < 8; ++i)
	{
		if (!std::isdigit(dateStr[expectedDigitPositions[i]]))
			return (false);
	}
	if (dateStr[4] != '-' || dateStr[7] != '-')
		return (false);
	return (true);
}

bool BitcoinExchange::isDateOK(const std::string &dateStr)
{
	if (!isDateFormatted(dateStr))
		return (false);

	std::string yearStr = dateStr.substr(0, 4);
	std::string monthStr = dateStr.substr(5, 2);
	std::string dayStr = dateStr.substr(8, 2);
	if (yearStr.length() != 4 || monthStr.length() != 2 || dayStr.length() != 2)
		return (false);
		
	int year, month, day;
	std::istringstream yearStream(yearStr);
	std::istringstream monthStream(monthStr);
	std::istringstream dayStream(dayStr);
	if (!(yearStream >> year) || !(monthStream >> month) || !(dayStream >> day))
		return (false);

	if (!isDateValid(year, month, day))
		return (false);

	if (isDateInFuture(year, month, day))
		return (false);

	return (true);
}

bool BitcoinExchange::isNumOK(const std::string &valueStr)
{
	std::istringstream iss(valueStr);
	double value;
	char extraChars;
	if (!(iss >> value))
		return (false);
	if (iss >> extraChars)
		return (false);
	return (true);
}

double BitcoinExchange::getExchangeRate(const std::string dateStr)
{
	if (data.empty())
		return (0.0);
	if (dateStr < data.begin()->first)
	{
		std::cerr << RED << "Error: input date is before the earliest rate data: " << dateStr << RESET << std::endl;
		return (-1.0);
	}
	if (dateStr > data.rbegin()->first)
	{
		std::cerr << CYAN << "Warning: input date is after the latest rate data: " << dateStr << RESET << std::endl;
	}
	std::map<std::string, double>::const_iterator it = data.lower_bound(dateStr);
	if (it == data.begin())
		return (0.0);
	if (it != data.end() && it->first == dateStr)
		return (it->second);
	return ((--it)->second);
}

bool BitcoinExchange::isDatabaseLineOK(std::string line, std::string &dateStr, std::string &valueStr, double &value)
{
	char splitter = ',';
	std::istringstream iss(line);
	if (line.empty())
		return (false);
	if (!std::getline(iss, dateStr, splitter) || !std::getline(iss, valueStr))
	{
		std::cerr << YELLOW << "Error: invalid database line: " << line << RESET << std::endl;
		return (false);
	}
	if (!isDateOK(dateStr))
	{
		std::cerr << YELLOW << "Error: invalid database date: " << dateStr << RESET << std::endl;
		return (false);
	}
	std::istringstream strToDouble(valueStr);
	if (!(strToDouble >> value) || !isNumOK(valueStr))
	{
		std::cerr << YELLOW << "Error: invalid database value: " << valueStr << RESET << std::endl;
		return (false);
	}
	std::string surplus;
	if (iss >> surplus)
	{
		std::cerr << YELLOW << "Error: Unexpected data after database value: " << surplus << RESET << std::endl;
		return (false);
	}
	return (true);
}

bool BitcoinExchange::isInputLineOK(std::string line, std::string &dateStr, std::string &valueStr, double &value)
{ 	
	std::istringstream iss(line);
	char splitter;

	if (line.empty())
		return (false);
	if (!(iss >> dateStr >> splitter >> valueStr) || (splitter != '|'))
	{
		std::cerr << YELLOW << "Error: invalid input line: " << line << RESET << std::endl;
		return (false);
	}
	if (!isDateOK(dateStr))
	{
		std::cerr << YELLOW << "Error: invalid input date: " << dateStr << RESET << std::endl;
		return (false);
	}
	std::istringstream strToDouble(valueStr);
	if (!(strToDouble >> value) || !isNumOK(valueStr) || value < 0 || value > 1000)
	{
		std::cerr << YELLOW << "Error: invalid input value: " << valueStr << RESET << std::endl;
		return (false);
	}
	std::string surplus;
	if (iss >> surplus)
	{
		std::cerr << YELLOW << "Error: Unexpected data after input value: " << surplus << RESET << std::endl;
		return (false);
	}
	return (true);
}

int BitcoinExchange::processData(const std::string filename)
{
	std::string line;
	std::string dateStr;
	std::string valueStr;
	double value = 0.0;
	bool lineSkipped = true;
	std::ifstream datafile(filename.c_str());
	if (!datafile)
	{
		std::cerr << RED << "Error: could not open " << filename << RESET << std::endl;
		return (1);
	}
	while (std::getline(datafile, line))
	{
		if (lineSkipped && line.find("date") != std::string::npos)
		{
			lineSkipped = false;
			continue ;
		}
		lineSkipped = false;
		
		if (isDatabaseLineOK(line, dateStr, valueStr, value))
			data[dateStr] = value;
	}
	datafile.close();
	//printData();
	return (0);
}

int BitcoinExchange::processInput(const std::string filename)
{
	std::string line;
	std::string dateStr;
	std::string valueStr;
	double value = 0.0;
	double exchangeRate;
	bool lineSkipped = true;
	if (data.empty())
	{
		std::cerr << RED << "Error: no data in database" << RESET << std::endl;
		return (1);
	}
	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::cerr << RED << "Error: could not open " << filename << RESET << std::endl;
		return (1);
	}
	while (std::getline(infile, line))
	{
		if (lineSkipped && line.find("date") != std::string::npos)
		{
			lineSkipped = false;
			continue ;
		}
		lineSkipped = false;

		if (isInputLineOK(line, dateStr, valueStr, value))
		{
			exchangeRate = getExchangeRate(dateStr);
			if (exchangeRate < 0.0)
				continue ;
			std::cout << dateStr << " => " << value << " = " << value * exchangeRate << std::endl;
		}
	}
	infile.close();
	return (0);
}

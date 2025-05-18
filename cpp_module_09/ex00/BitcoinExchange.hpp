/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:33:41 by arybarsk          #+#    #+#             */
/*   Updated: 2025/03/22 21:33:45 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>
#include <map>
#include <exception>

#define RESET	"\033[0m"
#define RED	"\033[31m"
#define YELLOW	"\033[33m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &source);
		BitcoinExchange & operator = (const BitcoinExchange &source);
		~BitcoinExchange();
		int processData(const std::string filename);
		int processInput(const std::string filename);
	private:
		std::map<std::string, double> data;
		bool isDateOK(const std::string &date);
		bool isDateFormatted(const std::string &dateStr);
		bool isDateValid(int year, int month, int day);
		bool isDateInFuture(int year, int month, int day);
		bool isNumOK(const std::string &dateStr);
		bool isInputLineOK(std::string line, std::string &dateStr, std::string &valueStr, double &value);
		bool isDatabaseLineOK(std::string line, std::string &dateStr, std::string &valueStr, double &value);
		double getExchangeRate(const std::string dateStr);
		void printData(void);
};

#endif

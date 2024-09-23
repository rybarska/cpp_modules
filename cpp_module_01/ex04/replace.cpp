/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 22:02:18 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/27 22:02:22 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void checkArgs(int argc, char **argv)
{
	if (argc != 4)
		throw std::invalid_argument("Usage: ./program_name <filename> s1 s2");
	if (std::string(argv[1]).empty())
		throw std::invalid_argument("Error: argv[1] cannot be an empty string");
	if (std::string(argv[2]).empty())
		throw std::invalid_argument("Error: argv[2] cannot be an empty string");
}

void replaceString(std::string &line, const std::string &s1, const std::string &s2)
{
	std::size_t found = line.find(s1);
	while (found != std::string::npos)
	{
		line.erase(found, s1.length());
		line.insert(found, s2);
		found = line.find(s1, found + s2.length());
	}
}

void processFile(const std::string &infileName, const std::string &s1, const std::string &s2, bool replace)
{
	std::ifstream inFile(infileName.c_str());
	if (!inFile)
		throw std::runtime_error("Error: could not open input file");
	
	std::string outFileName = infileName + ".replace";
	std::ofstream outFile(outFileName.c_str());
	if (!outFile)
		throw std::runtime_error("Error: could not open output file");
	
	std::string line;
	while (std::getline(inFile, line))
	{
		if (replace)
			replaceString(line, s1, s2);
		outFile << line << std::endl;
	}
}

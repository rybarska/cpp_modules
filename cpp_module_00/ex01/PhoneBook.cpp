/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:41:59 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/17 19:42:02 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : addedContacts(0), index(0)
{ /*std::cout << "PhoneBook Constructor " << std::endl; */ }

PhoneBook::~PhoneBook()
{ /*std::cout << "PhoneBook Destructor " << std::endl; */ }

std::string PhoneBook::trim(const std::string& str)
{
	size_t strStart = str.find_first_not_of(" \t\n\r");
	size_t strEnd = str.find_last_not_of(" \t\n\r");
	
	if (strStart == std::string::npos)
		return ("");
	return str.substr(strStart, strEnd - strStart + 1);
}

bool PhoneBook::isAscii(const std::string& str)
{
	for (size_t i=0; i < str.size(); ++i)
	{
		if (static_cast<unsigned char>(str[i]) > 127)
			return (false);
	}
	return (true);
}

bool PhoneBook::getGoodInput(const std::string& prompt, std::string& input)
{
	while (true)
	{
		std::cout << prompt << std::endl;
		std::getline(std::cin, input);
		if (!std::cin.good())
		{
			std::cerr << "Input error" << std::endl;
			return (false);
		}
		input = trim(input);
		if (input == "exit" || input == "EXIT")
			throw std::exception();
		if (!isAscii(input))
		{
			std::cout << "Input cannot contain non-ASCII characters." << std::endl;
			continue ;
		}
		if (input.empty())
		{
			std::cout << "Field cannot be empty." << std::endl;
			continue ;
		}
		return (true);
	}
}

void PhoneBook::addContact()
{
	Contact contact;
	contact.setAssignedIndex(index);
	
	std::string input;
	
	if (!getGoodInput("Enter first name:", input))
		return ;
	contact.setFirstName(input);
	
	if (!getGoodInput("Enter last name:", input))
		return ;
	contact.setLastName(input);
	
	if (!getGoodInput("Enter nickname:", input))
		return ;
	contact.setNickname(input);
	
	if (!getGoodInput("Enter phone number:", input))
		return ;
	contact.setPhoneNumber(input);
	
	if (!getGoodInput("Enter darkest secret:", input))
		return ;
	contact.setDarkestSecret(input);
	
	if (addedContacts < MAX_CONTACTS)
		addedContacts++;
	contacts[index] = contact;
	index++;
	index = index % MAX_CONTACTS;
}

std::string PhoneBook::fitStringToColumn(const std::string &str) const
{
	if (str.length() > COL_WIDTH)
		return str.substr(0, COL_WIDTH - 1) + ".";
	return std::string(COL_WIDTH - str.length(), ' ') + str;
}

void PhoneBook::printColumnNames() const
{
	std::cout << std::setw(10) << std::right << "index" << "|" 
	<< std::setw(10) << std::right << "first name" << "|" 
	<< std::setw(10) << std::right << "last name" << "|" 
	<< std::setw(10) << std::right << "nickname" << std::endl;
}

void PhoneBook::printContactRow(const Contact &contact) const
{
	std::cout << std::setw(COL_WIDTH) << std::right 
	<< contact.getAssignedIndex() << "|" 
	<< fitStringToColumn(contact.getFirstName()) << "|" 
	<< fitStringToColumn(contact.getLastName()) << "|" 
	<< fitStringToColumn(contact.getNickname()) << std::endl;
}

void PhoneBook::printAllContacts() const
{
	printColumnNames();
	for (size_t i=0; i < addedContacts; ++i)
	{
		printContactRow(contacts[i]);
	}
}

void PhoneBook::printFoundContact(const Contact &contact) const
{	
	std::cout << "index :" << contact.getAssignedIndex() << std::endl;
	std::cout << "first name :" << contact.getFirstName() << std::endl;
	std::cout << "last name :" << contact.getLastName() << std::endl;
	std::cout << "nickname :" << contact.getNickname() << std::endl;
	std::cout << "phone number :" << contact.getPhoneNumber() << std::endl;
	std::cout << "darkest secret :" << contact.getDarkestSecret() << std::endl;
}

void PhoneBook::searchAndPrintContact()
{
	printAllContacts();
	if (!addedContacts)
	{
		std::cout << "No contacts have been added" << std::endl;
		return ;
	}
	size_t searchedIndex = -1;
	while (searchedIndex < 0 || searchedIndex > (addedContacts - 1))
	{
		std::string input;
		if (!getGoodInput("Enter index:", input))
			return ;
		bool isNumeric = true;
		for (size_t i=0; i < input.length(); ++i)
		{
			if (!std::isdigit(input[i]))
			{
				isNumeric = false;
				break ;
			}
		}
		if (isNumeric)
		{
			searchedIndex = atoi(input.c_str());
			if (searchedIndex >= 0 && searchedIndex < addedContacts)
				break ;
		}
		std::cout << "Invalid input: index out of range or not numeric" << std::endl;
	}
	printFoundContact(contacts[searchedIndex]);
}

void PhoneBook::chooseAction()
{
	std::cout << "Enter ADD to add contact, SEARCH to search contact, EXIT to exit program" << std::endl;
	std::string action;
	std::getline(std::cin, action);
	if (!std::cin.good())
	{
		std::cerr << "Input error" << std::endl;
		throw std::runtime_error("Input error");
	}
	action = trim(action);
	for (size_t i=0; i < action.length(); ++i)
		action[i] = std::toupper(action[i]);
	if ((action == "S" || action == "SEARCH") && !addedContacts)
		std::cout << "No contacts have been added, try again:" << std::endl;
	else if (action == "S" || action == "SEARCH")
		searchAndPrintContact();
	else if (action == "A" || action == "ADD")
		addContact();
	else if (action == "EXIT")
		throw std::exception();
	else
		std::cout << "Invalid input, try again:" << std::endl;
}

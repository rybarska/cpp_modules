/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:42:52 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/18 18:42:54 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip> // for std::setw
#include <cstdlib> // for atoi
#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook
{
	public:
	PhoneBook();
	~PhoneBook();
	void chooseAction();
	
	private:
	std::string trim(const std::string& str);
	bool isAscii(const std::string& str);
	bool getGoodInput(const std::string& prompt, std::string& input);
	void addContact();
	std::string fitStringToColumn(const std::string &str) const;
	void printColumnNames() const;
	void printContactRow(const Contact &contact) const;
	void printAllContacts() const;
	void printFoundContact(const Contact &contact) const;
	void searchAndPrintContact();
	
	Contact contacts[MAX_CONTACTS];
	size_t addedContacts;
	size_t index;
};

#endif

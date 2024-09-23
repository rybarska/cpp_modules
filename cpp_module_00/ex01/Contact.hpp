/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 18:44:15 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/18 18:44:21 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

#define COL_WIDTH 10

class Contact
{
	public:
	Contact();
	~Contact();

	void setFirstName(const std::string &name);
	void setLastName(const std::string &name);
	void setNickname(const std::string &nick);
	void setPhoneNumber(const std::string &num);
	void setDarkestSecret(const std::string &secret);
	void setAssignedIndex(size_t index);
	
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
	size_t getAssignedIndex() const;
	
	bool isFirstNameEmpty() const;
	bool isLastNameEmpty() const;
	bool isNicknameEmpty() const;
	bool isPhoneNumberEmpty() const;
	bool isDarkestSecretEmpty() const;
	
	private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	size_t assignedIndex;
};

#endif

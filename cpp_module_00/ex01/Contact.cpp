/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 23:05:28 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/17 23:05:32 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : assignedIndex(-1)
{ /*std::cout << "Contact Constructor " << firstName << std::endl; */ }

Contact::~Contact()
{ /*std::cout << "Contact Destructor " << firstName << std::endl; */ }

void Contact::setFirstName(const std::string &name) { firstName = name; }
void Contact::setLastName(const std::string &name) { lastName = name; }
void Contact::setNickname(const std::string &nick) { nickname = nick; }
void Contact::setPhoneNumber(const std::string &num) { phoneNumber = num; }
void Contact::setDarkestSecret(const std::string &secret) { darkestSecret = secret; }
void Contact::setAssignedIndex(size_t index) { assignedIndex = index; }

std::string Contact::getFirstName() const { return firstName; }
std::string Contact::getLastName() const { return lastName; }
std::string Contact::getNickname() const { return nickname; }
std::string Contact::getPhoneNumber() const { return phoneNumber; }
std::string Contact::getDarkestSecret() const { return darkestSecret; }
size_t Contact::getAssignedIndex() const { return assignedIndex; }

bool Contact::isFirstNameEmpty() const { return firstName.empty(); }
bool Contact::isLastNameEmpty() const { return lastName.empty(); }
bool Contact::isNicknameEmpty() const { return nickname.empty(); }
bool Contact::isPhoneNumberEmpty() const { return phoneNumber.empty(); }
bool Contact::isDarkestSecretEmpty() const { return darkestSecret.empty(); }



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:10:20 by arybarsk          #+#    #+#             */
/*   Updated: 2025/01/19 15:10:22 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer constructed" << std::endl;
}

Serializer::Serializer(const Serializer &source)
{
	*this = source;
}

Serializer & Serializer::operator = (const Serializer &source)
{
	if (this != &source)
	{}
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Serializer destroyed" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t serialized = reinterpret_cast<uintptr_t>(ptr);
	return (serialized);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *deserialized = reinterpret_cast<Data*>(raw);
	return (deserialized);
}

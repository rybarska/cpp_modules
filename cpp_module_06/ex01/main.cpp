/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:34:27 by arybarsk          #+#    #+#             */
/*   Updated: 2025/01/07 14:34:30 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{	
	try
	{
		Data someData;
		someData.someInt = 42;
		someData.someString = "blah";
		
		std::cout << "Address of someData: " << &someData << std::endl;
		
		uintptr_t serializedData = Serializer::serialize(&someData);
		
		Data *deserializedData = Serializer::deserialize(serializedData);
		std::cout << "Deserialized data address: " << deserializedData << std::endl;
		std::cout << "Deserialized data -> someInt: " << deserializedData->someInt << std::endl;
		std::cout << "Deserialized data -> someString: " << deserializedData->someString << std::endl;
		
		if (deserializedData != &someData || deserializedData->someInt != someData.someInt
			|| deserializedData->someString != someData.someString)
		{
			std::cerr << "Error: deserialized data does not match original data" << std::endl;
		}
		else
		{
			std::cout << "Success!" << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}

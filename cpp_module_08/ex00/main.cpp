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

#include "easyfind.hpp"

int main(void)
{	
	try
	{
		std::vector<int> empty_vec;
		//easyfind(empty_vec, 30);
		std::list<int> empty_li;
		//easyfind(empty_li, 5);
		std::deque<int> empty_deq;
		//easyfind(empty_deq, 700);
		
		std::vector<int> vec;
		
		vec.push_back(40);
		vec.push_back(30);
		vec.push_back(70);
		vec.push_back(50);
		vec.push_back(60);
		
		std::cout << "Testing std::vector:" << std::endl;
		
		easyfind(vec, 30);
		//easyfind(vec, 80);
		
		std::list<int> li;
		
		li.push_back(4);
		li.push_back(3);
		li.push_back(7);
		li.push_back(5);
		li.push_back(6);
		
		std::cout << "Testing std::list:" << std::endl;
		
		easyfind(li, 5);
		//easyfind(li, 8);
		
		std::deque<int> deq;
		
		deq.push_back(400);
		deq.push_back(300);
		deq.push_back(700);
		deq.push_back(500);
		deq.push_back(600);
		
		std::cout << "Testing std::deque:" << std::endl;
		
		easyfind(deq, 700);
		//easyfind(deq, 800);
		
		const std::vector<int>& c_vec = vec;
		std::cout << "Testing const std::vector:" << std::endl;
		easyfind(c_vec, 30);
		//easyfind(c_vec, 80);
		
		const std::list<int>& c_li = li;
		std::cout << "Testing const std::list:" << std::endl;
		easyfind(c_li, 5);
		//easyfind(c_li, 8);
		
		const std::deque<int>& c_deq = deq;
		std::cout << "Testing const std::deque:" << std::endl;
		easyfind(c_deq, 700);
		//easyfind(c_deq, 800);
		
		return (0);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}

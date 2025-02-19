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

#include "MutantStack.hpp"

void testMutantStack()
{
	std::cout << "Testing MutantStack:" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << "MutantStack forward iteration:" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::cout << "MutantStack reverse iteration:" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	++rit;
	--rit;
	while (rit != rite)
	{
	std::cout << *rit << std::endl;
	++rit;
	}
	std::stack<int> s(mstack);
	std::cout << std::endl;
}

void testList()
{
	std::cout << "Testing std::list:" << std::endl;
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::cout << "std::list forward iteration:" << std::endl;
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::cout << "std::list reverse iteration:" << std::endl;
	std::list<int>::reverse_iterator rit = mstack.rbegin();
	std::list<int>::reverse_iterator rite = mstack.rend();
	++rit;
	--rit;
	while (rit != rite)
	{
	std::cout << *rit << std::endl;
	++rit;
	}
	std::list<int> s(mstack);
	std::cout << std::endl;
}

void testVector()
{
	std::cout << "Testing std::vector:" << std::endl;
	std::vector<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::cout << "std::vector forward iteration:" << std::endl;
	std::vector<int>::iterator it = mstack.begin();
	std::vector<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::cout << "std::vector reverse iteration:" << std::endl;
	std::vector<int>::reverse_iterator rit = mstack.rbegin();
	std::vector<int>::reverse_iterator rite = mstack.rend();
	++rit;
	--rit;
	while (rit != rite)
	{
	std::cout << *rit << std::endl;
	++rit;
	}
	std::vector<int> s(mstack);
	std::cout << std::endl;
}

void testDeque()
{
	std::cout << "Testing std::deque:" << std::endl;
	std::deque<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	std::cout << "std::deque forward iteration:" << std::endl;
	std::deque<int>::iterator it = mstack.begin();
	std::deque<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::cout << "std::deque reverse iteration:" << std::endl;
	std::deque<int>::reverse_iterator rit = mstack.rbegin();
	std::deque<int>::reverse_iterator rite = mstack.rend();
	++rit;
	--rit;
	while (rit != rite)
	{
	std::cout << *rit << std::endl;
	++rit;
	}
	std::deque<int> s(mstack);
	std::cout << std::endl;
}

void testConstMutantStack()
{
	std::cout << "Testing const MutantStack:" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	const MutantStack<int> cstack(mstack);
	
	std::cout << "const MutantStack forward iteration:" << std::endl;
	MutantStack<int>::const_iterator cit = cstack.begin();
	MutantStack<int>::const_iterator cite = cstack.end();
	++cit;
	--cit;
	while (cit != cite)
	{
	std::cout << *cit << std::endl;
	++cit;
	}
	std::cout << "const MutantStack reverse iteration:" << std::endl;
	MutantStack<int>::const_reverse_iterator crit = cstack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = cstack.rend();
	++crit;
	--crit;
	while (crit != crite)
	{
	std::cout << *crit << std::endl;
	++crit;
	}
	std::stack<int> s(mstack);
}

int main(void)
{	
	try
	{
		testMutantStack();
		testList();
		testVector();
		testDeque();
		testConstMutantStack();
		return 0;
	}

	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}

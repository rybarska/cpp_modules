/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:13:03 by arybarsk          #+#    #+#             */
/*   Updated: 2025/02/17 13:13:07 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include <vector>
#include <algorithm>

template < typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &source);
		MutantStack & operator = (const MutantStack &source);
		~MutantStack();
		
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator const_reverse_iterator;
		
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;
	private:
		
};

#include "MutantStack.tpp"

#endif

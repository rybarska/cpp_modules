// **************************************************************************** #
//                                                                              #
//                                                         :::      ::::::::    #
//    MutantStack.tpp                                    :+:      :+:    :+:    #
//                                                     +:+ +:+         +:+      #
//    By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+         #
//                                                 +#+#+#+#+#+   +#+            #
//    Created: 2025/02/17 13:13:15 by arybarsk          #+#    #+#              #
//    Updated: 2025/02/17 13:13:19 by arybarsk         ###   ########.fr        #
//                                                                              #
// **************************************************************************** #

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &source)
{
	*this = source;
}

template <typename T, typename Container>
MutantStack<T, Container> & MutantStack<T, Container>::operator = (const MutantStack &source)
{
	if (this != &source)
		this->c = source.c;
	return (*this);
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return this->c.end();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
{
	return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const
{
	return this->c.end();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin()
{
	return this->c.rbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend()
{
	return this->c.rend();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin() const
{
	return this->c.rbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend() const
{
	return this->c.rend();
}

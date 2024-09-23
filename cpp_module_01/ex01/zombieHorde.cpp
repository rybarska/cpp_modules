/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:06:45 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/22 21:06:47 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* zombieHorde = new Zombie[N];
	for (int i=0; i < N; i++)
		(zombieHorde[i]).setName(name);
	return (zombieHorde);
}

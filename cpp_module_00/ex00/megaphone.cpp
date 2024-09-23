/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 18:14:14 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/17 18:14:15 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 0;
		while (argv[++i])
		{
			j = -1;
			while (argv[i][++j])
				std::cout << (char)std::toupper((unsigned char)argv[i][j]);
		}
		std::cout << std::endl;
	}
	return (0);
}

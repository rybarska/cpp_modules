/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arybarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:09:31 by arybarsk          #+#    #+#             */
/*   Updated: 2024/08/26 21:09:33 by arybarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

void checkArgs(int argc, char **argv);
void replaceString(std::string &line, const std::string &s1, const std::string &s2);
void processFile(const std::string &infileName, const std::string &s1, const std::string &s2, bool replace);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:54:10 by mzeroual          #+#    #+#             */
/*   Updated: 2023/10/20 10:22:38 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <list>

typedef struct t_data
{
    std::string date;
    std::string value;
} _data;

// Comman function
std::list<std::string>	split(std::string line, std::string delimiter);
std::string				trimSpace(std::string remove);
int						isNumber(std::string number);
int						parseDate(std::string date);
int						parseValue(std::string value, int min, int max);

int 					parseLine(std::string line, std::string delimiter, int i, std::list<_data> &liste);

#endif

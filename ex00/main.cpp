/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:53:33 by mzeroual          #+#    #+#             */
/*   Updated: 2023/11/17 11:20:51 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <algorithm>

bool comp(const _data& s1, const _data& s2)
{
	return (s1.date < s2.date);
}

void _exchange(std::list<_data> data, _data input)
{
	data.sort(comp);
	std::list<_data>::iterator  tmp = std::lower_bound(data.begin(), data.end(), input, comp);
	if (input.date == (*tmp).date)
		std::cout << input.date << " => " << input.value << " => " << (strtod(input.value.c_str(), NULL) * strtod((*tmp).value.c_str(), NULL)) << std::endl;
	else
		std::cout << input.date << " => " << input.value << " => " << (strtod(input.value.c_str(), NULL) * strtod((*--tmp).value.c_str(), NULL)) << std::endl;
}

int		main(int ac, char *av[])
{
	std::list<_data> data;
	std::list<_data> input;
	if (ac == 2)
	{
		std::string		content;
		std::ifstream	infile;
		std::ifstream	datafile;
		datafile.open("data.csv");
		if (!datafile.is_open())
			std::cout << "Error : data file not found\n";
		else {
			infile.open(av[1]);
			if (!infile.is_open())
				std::cout << "Error : file " << av[1] << " not found\n";
			else {
				int i = 0;
				while (std::getline(datafile, content))
					if (!parseLine(content, ",", i++, data))
						return (std::cout << "Error : bad input in line " << i << " >> " << content << std::endl, 1);
				i = 0;
				while (std::getline(infile, content)) {
					if (!content.empty()) {
						if (!parseLine(content, "|", i++, input))
							std::cout << "Error : bad input in line " << i << " >> " << content << std::endl;
						else {
							for (std::list<_data>::iterator it = input.begin(); it != input.end(); it++)
							{
								_exchange(data, *it);
								input.pop_front();
							}
						}
					}

				}
				infile.close();	
			}
			datafile.close();
		}
	}
	else
		std::cerr << "Error : You need file name" << std::endl;
	return 0;
}

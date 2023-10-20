/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:53:33 by mzeroual          #+#    #+#             */
/*   Updated: 2023/10/19 22:57:13 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <algorithm>

bool comp(const _data& s1, const _data& s2)
{
	return (s1.date < s2.date);
}

void exchange(std::list<_data> data, std::list<_data> input)
{
	// std::sort(data.begin(), data.end(), comp);
	data.sort(comp);
	for (std::list<_data>::iterator it2 = data.begin(); it2 != data.end(); it2++)
	{
		std::cout << (*it2).date << std::endl;
	}
	
	for (std::list<_data>::iterator it = input.begin(); it != input.end(); it++)
	{
		if (it != input.begin()) {
			std::list<_data>::iterator  tmp = std::lower_bound(data.begin(), data.end(), *it, comp);
			std::cout << (tmp == data.end()) << std::endl;
			
		}
		// std::string tmp = *it;
		// for (std::list<_data>::iterator it1 = data.begin(); it1 != data.end(); it1++)
		// {
		// 	if ((*it1).date <= (*it).date)
		// 	{
		// 		std::cout << (*it1).date << std::endl;
		// 	}
		// }
		
	}
	
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
		if (!datafile)
			std::cout << "Error : data file not found\n";
		else {
			infile.open(av[1]);
			if (!infile)
				std::cout << "Error : file " << av[1] << " not found\n";
			else {
				int i = 0;
				while (std::getline(datafile, content))
					parseLine(content, ",", i++, data);
				i = 0;
				while (std::getline(infile, content))
					parseLine(content, "|", i++, input);
				exchange(data, input);
				infile.close();	
			}
			datafile.close();
		}
	}
	else
		std::cerr << "Error : You need file name" << std::endl;
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:53:33 by mzeroual          #+#    #+#             */
/*   Updated: 2023/10/18 14:02:57 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::list<std::string>	split(std::string line, std::string delimiter)
{
	std::list<std::string> parse;
	
	size_t pos = line.find(delimiter);
	if (pos != std::string::npos)
	{
		while (pos != std::string::npos)
		{
			parse.push_back(line.substr(0, pos));
			line = line.substr(pos + 1, line.size());
			pos = line.find(delimiter);
		}
		parse.push_back(line.substr(0, line.size()));
	}
	else
		return (parse.push_back(line), parse);
	return (parse);
}

void	trimSpace(std::string &remove)
{
	size_t	i;

	for (i = 0; i < remove.size(); i++)
		if (remove[i] != ' ')
			break ;
	remove = remove.substr(i, remove.size());
	for (i = remove.size() -1; i >= 0; i--)
		if (remove[i] != ' ')
			break ;
	remove = remove.substr(0, i + 1);
}

int		isNumber(std::string number)
{
	for (size_t i = 0; i < number.size(); i++)
		if (!isdigit(number[i]))
			return (0);
	return (1);
}

int	parseDate(std::string date, std::string delimiter)
{
	std::list<std::string>				dateSplit;
	std::list<std::string>::iterator	dateSplitIt;
	long								dateLong[3];
	char								*rest;

	rest = 0;
	dateSplit = split(date, delimiter);
	if (dateSplit.size() != 3)
		// std::cerr << "Error : in line " << lineNum << " date not valid\n";
		return (0);
	else {
		int i = 0;
		for (dateSplitIt = dateSplit.begin(); dateSplitIt != dateSplit.end(); dateSplitIt++)
		{
			// std::cout << "#" << *dateSplitIt << "#" << std::endl;
			if (!isNumber(*dateSplitIt)) {
				// std::cerr << "Error : in line " << lineNum << " date not valid >> " << date << std::endl;
				return (0);
			}
			long number = strtol((*dateSplitIt).c_str(), &rest, 10);
			if (!number && *rest) {
				// std::cerr << "Error : in line " << lineNum << " date not valid >> " << date << std::endl;
				return (0);
			}
			else
				dateLong[i] = number;
			i++;
		}
		i = 0;
		for (size_t i = 0; i < 3; i++)
		{
			// std::cout << "$" << dateLong[i] << "$" << std::endl;
			if (i == 0 && !(dateLong[i] >= 2009 && dateLong[i] <= 2023) ) {
				// std::cerr << "Error : in line " << lineNum << " date not valid >> " << date << std::endl;
				return (0);
			}
			else if (i == 1 && !(dateLong[i] >= 1 && dateLong[i] <= 12)) {
				// std::cerr << "Error : in line " << lineNum << " date not valid >> " << date << std::endl;
				return (0);
			}
			else if (i == 2 && (
				(dateLong[i - 1] != 2 && dateLong[i - 1] <= 7 && ((dateLong[i - 1] % 2 == 1 && !(dateLong[i] >= 1 && dateLong[i] <= 31))
																|| (dateLong[i - 1] % 2 == 0 && !(dateLong[i] >= 1 && dateLong[i] <= 30))))
				|| (dateLong[i - 1] != 2 && dateLong[i - 1] >= 8 && ((dateLong[i - 1] % 2 == 0 && !(dateLong[i] >= 1 && dateLong[i] <= 31))
																|| (dateLong[i - 1] % 2 == 1 && !(dateLong[i] >= 1 && dateLong[i] <= 30))))
				|| (dateLong[i - 1] == 2 && ((dateLong[i - 2] % 4 == 0 && !(dateLong[i] >= 1 && dateLong[i] <= 29)) 
										|| (dateLong[i - 2] % 4 != 0 && !(dateLong[i] >= 1 && dateLong[i] <= 28))))
				|| (dateLong[i - 2] == 2009 && dateLong[i - 1] == 1 && dateLong[i] < 3)
				))
				// std::cerr << "Error : in line " << lineNum << " date not valid >> " << date << std::endl;
				return (0);
		}
	}
	return (1);
}

void	parseValue(std::string value, int lineNum, int min, int max, std::string fileName)
{
	char *rest = 0;
	double number = strtod(value.c_str(), &rest);
	if ((!number && *rest) || !(number >= min && number <= max)) {
		std::cerr << "Error : in file " << fileName << " line " << lineNum << " value not valid >> " << value << std::endl;
	}
}
 
void	prseLine(std::string line, int lineNum, std::string delimiter, int min, int max, std::string fileName)
{
	std::list<std::string> date;
	
	if (!line.empty()) {
		std::list<std::string> lineSplit = split(line, delimiter);
		if (lineSplit.size() != 2) {
			std::cerr << "Error : in file " << fileName << " line " << lineNum << " syntax error " << line << std::endl;
		}
		else {
			trimSpace(*lineSplit.begin());
			if (!parseDate(*lineSplit.begin(), "-"))
				std::cerr << "Error : in file " << fileName << " line " << lineNum << " date not valid >> " << *lineSplit.begin() << std::endl;
			else {
				trimSpace(*++lineSplit.begin());
				parseValue(*++lineSplit.begin(), lineNum, min, max, fileName); 
			}
		}
	}
}

void	parseFile(std::list<std::string> input, std::string delimiter, std::string date, std::string value, std::string fileName)
{
	int i = 0;
	std::list<std::string>::iterator first = input.begin();
	for (std::list<std::string>::iterator it = first; it != input.end(); it++)
	{
		if (it == first) {
			std::list<std::string> head = split(*it, delimiter);
			if (head.size() == 2) {
				for (std::list<std::string>::iterator it = head.begin(); it != head.end(); it++) {
					trimSpace(*it);
					if (*it != date && *it != value)
						std::cerr << "Error : in file " << fileName << " in the first line\n";
				}
			}
			else
				std::cerr << "Error : in file " << fileName << " in the first line\n";

		}
		else if (delimiter == "|")
			prseLine(*it, i, delimiter, 0, 1000, fileName);
		else if (delimiter == ",")
			prseLine(*it, i, delimiter, 0, INT_MAX, fileName);
		i++;
	}
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		std::list<std::string> input;
		std::list<std::string> data;
		std::string content;
		
		std::ifstream infile;
		std::ifstream datafile;

		datafile.open("data.csv");
		if (!datafile) 
			std::cout << "Error : data file not found\n";
		else {
			infile.open(av[1]);
			if (!infile)
				std::cout << "Error : file " << av[1] << " not found\n";
			else {                      
				datafile.close();
				while (std::getline(infile, content, '\n')) {
					input.push_back(content);
				}
				while (std::getline(datafile, content, '\n')) {
					data.push_back(content);
				}
				parseFile(data, ",", "date", "exchange_rate", "data.csv");
				parseFile(input, "|", "date", "value", av[1]);
				infile.close();	
			}                   
			datafile.close();
		}
	}
	else
		std::cerr << "Error : You need file name" << std::endl;
	return 0;
}

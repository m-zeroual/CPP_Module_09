/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:53:33 by mzeroual          #+#    #+#             */
/*   Updated: 2023/10/18 22:03:55 by mzeroual         ###   ########.fr       */
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

int		parseDate(std::string date, std::string delimiter)
{
	std::list<std::string>				dateSplit;
	std::list<std::string>::iterator	dateSplitIt;
	long								dateLong[3];
	char								*rest;

	rest = 0;
	dateSplit = split(date, delimiter);
	if (dateSplit.size() != 3)
		return (0);
	else {
		int i = 0;
		for (dateSplitIt = dateSplit.begin(); dateSplitIt != dateSplit.end(); dateSplitIt++)
		{
			// std::cout << "#" << *dateSplitIt << "#" << std::endl;
			if (!isNumber(*dateSplitIt)) 
				return (0);
			long number = strtol((*dateSplitIt).c_str(), &rest, 10);
			if (!number && *rest) 
				return (0);
			dateLong[i] = number;
			i++;
		}
		i = 0;
		for (size_t i = 0; i < 3; i++)
		{
			// std::cout << "$" << dateLong[i] << "$" << std::endl;
			if (i == 0 && !(dateLong[i] >= 2009 && dateLong[i] <= 2023)) 
				return (0);
			else if (i == 1 && !(dateLong[i] >= 1 && dateLong[i] <= 12)) 
				return (0);
			else if (i == 2 && (
				(dateLong[i - 1] != 2 && dateLong[i - 1] <= 7 && ((dateLong[i - 1] % 2 == 1 && !(dateLong[i] >= 1 && dateLong[i] <= 31))
																|| (dateLong[i - 1] % 2 == 0 && !(dateLong[i] >= 1 && dateLong[i] <= 30))))
				|| (dateLong[i - 1] != 2 && dateLong[i - 1] >= 8 && ((dateLong[i - 1] % 2 == 0 && !(dateLong[i] >= 1 && dateLong[i] <= 31))
																|| (dateLong[i - 1] % 2 == 1 && !(dateLong[i] >= 1 && dateLong[i] <= 30))))
				|| (dateLong[i - 1] == 2 && ((dateLong[i - 2] % 4 == 0 && !(dateLong[i] >= 1 && dateLong[i] <= 29)) 
										|| (dateLong[i - 2] % 4 != 0 && !(dateLong[i] >= 1 && dateLong[i] <= 28))))
				|| (dateLong[i - 2] == 2009 && dateLong[i - 1] == 1 && dateLong[i] < 3)
				))
				return (0);
		}
	}
	return (1);
}

int		parseValue(std::string value, int min, int max)
{
	char *rest = 0;
	double number = strtod(value.c_str(), &rest);
	if ((!number && *rest) || !(number >= min && number <= max))
		return (0);
	return (1);
}
 
void	prseLine(BitcoinExchange& obj, int line)
{
	// std::list<std::string> date;
	std::string date;
	std::string value;
	
	for (std::list<std::string>::iterator it = (obj.getContent()).begin(); it !=  (obj.getContent()).end(); it++)
	{
		if (!(*it).empty()) {
			std::list<std::string> lineSplit = split(*it, obj.getDelimiter());
			date = *lineSplit.begin();
			value = *++lineSplit.begin();
			if (lineSplit.size() != 2)
				std::cerr << "Error : in file " << obj.getName() << " line " << line << " syntax error " << value << std::endl;
			else {
				trimSpace(date);
				if (!parseDate(date, "-"))
					std::cerr << "Error : in file " << obj.getName() << " line " << line << " date not valid >> " << date << std::endl;
				else {
					trimSpace(value);
					// if (!parseValue(value, obj.getMin(), obj.getMax()))
					// 	std::cerr << "Error : in file " << obj.getName() << " line " << obj.getName() << " value not valid >> " << value << std::endl;
				}
			}
		}
		obj.pushDate(date);
		obj.pushValue(value);
	}
}

void	parseFile(BitcoinExchange& obj)
{
	int i = 0;
	std::list<std::string>::iterator first = (obj.getContent()).begin();
	for (std::list<std::string>::iterator it = first; it != (obj.getContent()).end(); it++)
	{
		if (it == first) {
			std::list<std::string> head = split(*it, obj.getDelimiter());
			if (head.size() == 2) {
				for (std::list<std::string>::iterator it = head.begin(); it != head.end(); it++) {
					trimSpace(*it);
					if (*it != "date" && *it != obj.getType())
						std::cerr << "Error : in file " << obj.getName() << " in the first line\n";
				}
			}
			else
				std::cerr << "Error : in file " << obj.getName() << " in the first line\n";
		}
		else if (obj.getDelimiter() == "|")
			prseLine(obj, i);
		else if (obj.getDelimiter() == ",")
			prseLine(obj, i);
		i++;
	}
}

int		main(int ac, char *av[])
{
	BitcoinExchange input(av[1], "value", "|");
	// BitcoinExchange data("data.csv", ",", "exchange_rate");
	if (ac == 2)
	{
		// std::list<std::string> input;
		// std::list<std::string> data;
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
				while (std::getline(infile, content, '\n'))
					input.pushContent(content);
				std::list<std::string> inputt = input.getContent();
				// for (std::list<std::string>::iterator it = inputt.begin(); it != inputt.end(); it++)
				// {
				// 	std::cout << *it << std::endl;
				// }
				
				// while (std::getline(datafile, content, '\n')) {
				// 	data.pushLine(content);
				// }
				// parseFile(data, ",", "date", "exchange_rate", "data.csv");
				parseFile(input);
				infile.close();	
			}
			datafile.close();
		}
	}
	else
		std::cerr << "Error : You need file name" << std::endl;
	return 0;
}

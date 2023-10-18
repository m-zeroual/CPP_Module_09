/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:53:33 by mzeroual          #+#    #+#             */
/*   Updated: 2023/10/18 09:38:55 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::list<std::string> split(std::string line, std::string delimiter)
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

void trimSpace(std::string &remove)
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

int isNumber(std::string number)
{
	for (size_t i = 0; i < number.size(); i++)
		if (!isdigit(number[i]))
			return (0);
	return (1);
}

void parseDate(std::string date, int lineNum, std::string delimiter)
{
	std::list<std::string>				dateSplit;
	std::list<std::string>::iterator	dateSplitIt;

	long								dateLong[3];


	char *rest = 0;
	dateSplit = split(date, delimiter);
	if (dateSplit.size() != 3)
		std::cerr << "Error : in line " << lineNum << " date not valid\n";
	else {
		int i = 0;
		for (dateSplitIt = dateSplit.begin(); dateSplitIt != dateSplit.end(); dateSplitIt++)
		{
			// std::cout << "#" << *dateSplitIt << "#" << std::endl;
			long number = strtol((*dateSplitIt).c_str(), &rest, 10);
			if (!number && *rest) {
				std::cerr << "Error : in line " << lineNum << " date not valid\n";
				break ;
			}
			else
				dateLong[i] = number;
			i++;
		}
		i = 0;
		for (size_t i = 0; i < 3; i++)
		{
			std::cout << "$" << dateLong[i] << "$" << std::endl;
			if (i == 0 && !(dateLong[i] >= 2009 && dateLong[i] <= 2023) )
				std::cerr << "Error : in line " << lineNum << " Year not valid\n";
			else if (i == 1 && !(dateLong[i] >= 1 && dateLong[i] <= 12))
				std::cerr << "Error : in line " << lineNum << " Month not valid\n";
			else if (i == 2 && (
				(dateLong[i - 1] != 2 && dateLong[i - 1] <= 7 && ((dateLong[i - 1] % 2 == 1 && !(dateLong[i] >= 1 && dateLong[i] <= 31))
																|| (dateLong[i - 1] % 2 == 0 && !(dateLong[i] >= 1 && dateLong[i] <= 30))))
				|| (dateLong[i - 1] != 2 && dateLong[i - 1] >= 8 && ((dateLong[i - 1] % 2 == 0 && !(dateLong[i] >= 1 && dateLong[i] <= 31))
																|| (dateLong[i - 1] % 2 == 1 && !(dateLong[i] >= 1 && dateLong[i] <= 30))))
				|| (dateLong[i - 1] == 2 && ((dateLong[i - 2] % 4 == 0 && !(dateLong[i] >= 1 && dateLong[i] <= 29)) 
										|| (dateLong[i - 2] % 4 != 0 && !(dateLong[i] >= 1 && dateLong[i] <= 28))))
				|| (dateLong[i - 2] == 2009 && dateLong[i - 1] == 1 && dateLong[i] < 3)
				))
				std::cerr << "Error : in line " << lineNum << " Day not valid\n";
		}
	}
}

void	parseValue(std::string value, int lineNum)
{
	char *rest = 0;
	double number = strtod(value.c_str(), &rest);
	if ((!number && *rest) || !(number >= 0 && number <= 1000)) {
		std::cout << "Error : in line " << lineNum << " value not valid\n";
	}
}
 
void prseLine(std::string line, int lineNum, std::string delimiter)
{
	std::list<std::string> date;
	
	if (!line.empty()) {
		std::list<std::string> lineSplit = split(line, delimiter);
		if (lineSplit.size() != 2) {
			std::cerr << "Error : general error in line " << lineNum<< std::endl;
		}
		else {
			trimSpace(*lineSplit.begin());
			parseDate(*lineSplit.begin(), lineNum, "-");
			trimSpace(*++lineSplit.begin());
			parseValue(*++lineSplit.begin(), lineNum); 
		}
	}
}

void parseInputFile(std::list<std::string> inputContant)
{
	int i = 0;
	std::list<std::string>::iterator first = inputContant.begin();
	for (std::list<std::string>::iterator it = first; it != inputContant.end(); it++)
	{
		if (it == first) {
			if (*first != "date | value")
				std::cerr << "Error : in head of input file\n";
		}
		else
			prseLine(*it, i, "|");
		if (i == 1)
			break ;
		i++;
	}
}

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		std::list<std::string> input;
		std::string content;
		
		std::ifstream fileName;
		fileName.open(av[1]);
		if (!fileName) {                            
			std::cout << "Error : opening the file\n";          
		}
		else {
			while (std::getline(fileName, content, '\n')) {
				input.push_back(content);
			}
			parseInputFile(input);
			fileName.close();                   
		}
	}
	else
		std::cerr << "Error : You need file name" << std::endl;
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:53:33 by mzeroual          #+#    #+#             */
/*   Updated: 2023/10/17 15:50:47 by mzeroual         ###   ########.fr       */
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
	{
		if (!isdigit(number[i]))
			return (0);
	}
	return (1);
}
void parseDate(std::list<std::string> lineSplit, int lineNum)
{
	// std::list<std::string>				date;
	// std::list<int>::iterator			dateit;
	std::list<std::string>				dateString;
	std::list<std::string>::iterator	dateStringit;
	
	std::list<int>						dateInt;
	std::list<int>::iterator			dateIntit;
	
	std::list<std::string>::iterator	lineSplitIt;
	
	if (lineSplit.size() != 2) {
		std::cerr << "Error : general error in line " << lineNum<< std::endl;
	}
	else {
		char *rest = 0;
		lineSplitIt = lineSplit.begin();
		// for (; lineSplitIt != lineSplit.end(); lineSplitIt++)
		// {
		// 	std::cout << "#" << *lineSplitIt << "#" << std::endl;
		// }
		
		// trimSpace(*it);
		// trimSpace(*++it);
		// std::cout << "#" << *it << "#" << std::endl;
		// std::cout << "#" << *++it << "#" << std::endl;
		// std::cout << *it << std::endl;
		
		dateString = split(*lineSplit.begin(), "-");
		if (dateString.size() != 3)
			std::cerr << "Error : in line " << lineNum << " date not valid\n";
		else {
			for (dateStringit = dateString.begin(); dateStringit != dateString.end(); dateStringit++)
			{
				std::cout << "$" << *dateStringit << "$" << std::endl;
				trimSpace(*dateStringit);
				long number = strtol((*dateStringit).c_str(), &rest, 10);
				if (*rest || !number) {
					std::cerr << "Error : in line " << lineNum << " date not valid\n";
					break ;
				}
				dateInt.push_back(number);
			}
			// int i = 0;
			for (dateIntit = dateInt.begin(); dateIntit != dateInt.end(); dateIntit++)
			{
				std::cout << "$" << *dateIntit << "$" << std::endl;
				// if (i = 0)
				// {
				// 	std::cerr << "Error : in line " << lineNum << " Year not valid\n";
				// }
				// i++;
			}
			
			// Dateit = Date.begin();
			// for (; Dateit != Date.end(); Dateit++)
			// {
			// 	// Date.push_back(strtod((*dateit).c_str(), &rest));
			// 	std::cout << "$" << *Dateit << "$" << std::endl;
			// 	// std::cout << "$" << *dateit << "$" << std::endl;
			// }
			// dateit = date.begin();
		}
		
		// else {
		// dateit = date.begin();
		// std::cout << "$" << *dateit << "$" << std::endl;
		// std::cout << "$" << *++dateit << "$" << std::endl;
		// // std::cout << "$" << *++dateit << "$" << std::endl;
		// std::cout << *++it << std::endl;
		// }
	}
	// int i = 0;
	// for (std::list<std::string>::iterator it = firstIt; it != lineSplit.end(); it++)
	// {
		// if (lineSplit.size() != 2) {
		// 	std::cerr << "Error : general error in line " << lineNum<< std::endl;
		// 	// break ;
		// }
		// else {
											// trimSpace(*it);
											// std::list<std::string> date;
											// if (it == firstIt) {
											// 	date = split(*it, "-");
											// 	if (date.size() != 3) {
											// 		std::cerr << "Error : in line " << lineNum << " date not valid\n";
											// 		// break ;
											// 	}
											// 	else
											// 	{
											// 		std::list<std::string>::iterator it1 = date.begin();
											// 		double year = strtod((*it1).c_str(), &rest);
											// 		double month = strtod((*++it1).c_str(), &rest);
											// 		double day = strtod((*++it1).c_str(), &rest);
											// 		std::cout << year << std::endl;
											// 		std::cout << month << std::endl;
											// 		std::cout << day << std::endl;
											// 		// for (std::list<std::string>::iterator it1 = date.begin(); it1 != date.end(); it1++)
											// 		// {
											// 		// 	double number = strtod((*it1).c_str(), &rest);
											// 		// 	if (*rest || !number) {
											// 		// 			std::cerr << "Error : in line " << lineNum << " date not valid\n";
											// 		// 		// if (i == 0)
											// 		// 		// else if (i == 1)
											// 		// 		// 	std::cerr << "Error : in line " << lineNum << " Month valid\n";
											// 		// 		// else if (i == 2)
											// 		// 		// 	std::cerr << "Error : in line " << lineNum << " Day valid\n";
											// 		// 		// break ;
											// 		// 	}
											// 		// 	else if (i == 0 && !(number > 2004 && number < 2022))
											// 		// 			std::cerr << "Error : in line " << lineNum << " Year not valid\n";
											// 		// 	else if (i == 1 && !(number > 1 && number < 12))
											// 		// 			std::cerr << "Error : in line " << lineNum << " Month not valid\n";
											// 		// 	else if (i == 2 && !(number > 1 && number < 30))
											// 		// 			std::cerr << "Error : in line " << lineNum << " Day not valid\n";
											// 		// 	i++;
											// 		// }
											// 	}
											// 	rest = 0;
											// }
											// else {
											// 	double number = strtod((*it).c_str(), &rest);
											// 	if (*rest || !number) {
											// 		std::cerr << "Error : in line " << lineNum << " value not a number\n";
											// 	}
											// }
		// }
	// }
}

void prseLine(std::string line, int lineNum, std::string delimiter)
{
	std::list<std::string> date;
	
	if (!line.empty()) {
		std::list<std::string> lineSplit = split(line, delimiter);
		parseDate(lineSplit, lineNum);
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

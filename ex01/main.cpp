/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:45:08 by mzeroual          #+#    #+#             */
/*   Updated: 2023/10/20 21:50:39 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>

std::string	trimSpace(std::string remove, char c)
{
	size_t	i;

	for (i = 0; i < remove.size(); i++)
		if (remove[i] != c)
			break ;
	remove = remove.substr(i, remove.size());
	for (i = remove.size() -1; i >= 0; i--)
		if (remove[i] != ' ')
			break ;
	remove = remove.substr(0, i + 1);
	return (remove);
}

std::stack<std::string>	split(std::string line, char delimiter)
{
	std::stack<std::string> parse;
	
	size_t pos = line.find(delimiter);
	if (pos != std::string::npos)
	{
		while (pos != std::string::npos)
		{
			parse.push(line.substr(0, pos));
			line = line.substr(pos + 1, line.size());
			line = trimSpace(line, delimiter);
			pos = line.find(delimiter);
		}
		parse.push(line.substr(0, line.size()));
	}
	else
		return (parse.push(line), parse);
	return (parse);
}

void parseArgs(std::string element)
{
	char *end = NULL;
	long n = strtol(element.c_str(), &end, 10);
	// if (*end && (strlen(end) >= 2
	// || (strlen(end) == 1 && *end != '+' && *end != '-' && *end != '*' && *end != '/')
	// || (strlen(end) == 1 && isprint(*end))))
	// if (*end && (strlen(end) >= 2 && isprint(*end) && (*end != '+' && *end != '-' && *end != '*' && *end != '/')))
	// || (strlen(end) == 1 && *end != '+' && *end != '-' && *end != '*' && *end != '/')))


	//  || strlen(end) >= 2 || ((*end != '+' && *end != '-' && *end != '*' && *end != '/') || n)))
	if (*end && (strlen(end) >= 2 || element.length() != strlen(end) || (*end != '+' && *end != '-' && *end != '*' && *end != '/') ))
	{
		std::cout << "Error : not a number!!\n";
		exit (1);
	}
	// if (strlen(end) == 1 && (*end == '+' || *end == '-' || *end == '*' || *end == '/'))
	//     countOp++;
	if (n < 0)
	{
		std::cout << "Error : number is negative!!\n";
		exit (1);
	}
}
// void checkSyntax(std::string args)
// {
//     std::cout <<  "#" << args << "#" << std::endl;
// }

void readInput(std::string args)
{
	args = trimSpace(args, ' ');
	std::stack<std::string> args_split = split(args, ' ');
	std::stack<std::string> copy(args_split);

	// checkSyntax(args);
	size_t len = args_split.size();
	for (size_t i = 0; i < len; i++)
	{
		std::string element = args_split.top();
		std::cout << "|" << element << "|" << std::endl;
		parseArgs(element);
		args_split.pop();
	}
	args_split = copy;
	// for (size_t i = 0; i < len; i++)
	// {
	// 	std::string element = args_split.top();
	// 	if ()
	// 	// std::cout << "|" << element << "|" << std::endl;
	// 	parseArgs(element);
	// 	args_split.pop();
	// }
}

int main(int ac, char const *av[])
{
	if (ac == 2)
	{
		readInput(av[1]);
	}
	else
		std::cout << "bad args!!\n";
	return 0;
}

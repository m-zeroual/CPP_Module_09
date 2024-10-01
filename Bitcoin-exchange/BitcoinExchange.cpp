/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:28:42 by mzeroual          #+#    #+#             */
/*   Updated: 2023/11/20 09:34:35 by mzeroual         ###   ########.fr       */
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

std::string	trimSpace(std::string remove)
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
	return (remove);
}

int	isNumber(std::string number)
{
	for (size_t i = 0; i < number.size(); i++)
		if (!isdigit(number[i]))
			return (0);
	return (1);
}

int	parseDate(std::string date)
{
	std::list<std::string>				dateSplit;
	std::list<std::string>::iterator	dateSplitIt;
	long								dateLong[3];
	char								*rest;

	rest = 0;
	dateSplit = split(date, "-");
	if (dateSplit.size() == 3) {
		int i = 0;
		for (dateSplitIt = dateSplit.begin(); dateSplitIt != dateSplit.end(); dateSplitIt++)
		{
			if ((*dateSplitIt).empty() || !isNumber(*dateSplitIt)) 
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
				|| (dateLong[i - 2] == 2023 && (dateLong[i - 1] > 11 || (dateLong[i - 1] == 11 && dateLong[i] > 20)))
				))
				return (0);
		}
	}
	else
		return (0);
	return (1);
}

int	parseValue(std::string value, int min, int max)
{
	char *rest = 0;
	double number = strtod(value.c_str(), &rest);
	if (*rest || ((!number && *rest) || !(number >= min && number <= max)))
		return (0);
	return (1);
}
//--------------------------------------------------------------------

int		parseLine(std::string line, std::string delimiter, int i, std::list<_data> &liste)
{
	if (!line.empty()) {
		std::list<std::string> lineSplit = split(line, delimiter);

		if (lineSplit.size() == 2) {
			std::string date = trimSpace(*lineSplit.begin());
			std::string value = trimSpace(*++lineSplit.begin());
			if (i != 0) {
				if (!parseDate(date))
					return (0);
				else {
					if (delimiter == "|" && !parseValue(value, 0, 1000))
						return (0);
					else if (delimiter == "," && !parseValue(value, 0, INT_MAX))
						return (0);
				}
				_data s = {date, value};
				liste.push_back(s);
			}
			else if (i == 0 && ((delimiter == "|" && (date != "date" || value != "value"))
							|| (delimiter == "," && (date != "date" || value != "exchange_rate"))))
				return (0);
		}
		else {
			return (0);
		}
	}
	return (1);
}

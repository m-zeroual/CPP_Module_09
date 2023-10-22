/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:45:08 by mzeroual          #+#    #+#             */
/*   Updated: 2023/10/21 13:43:08 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void calcul(std::stack<int> &s1, char op)
{
	int rhs = s1.top();
	s1.pop();
	int lhs = s1.top();
	s1.pop();
	if (op == '+')
		s1.push(lhs + rhs);
	else if (op == '-')
		s1.push(lhs - rhs);
	else if (op == '*')
		s1.push(lhs * rhs);
	else if (op == '/')
		s1.push(lhs / rhs);
}

int  parseInput(std::string arg)
{
	std::stack<int> s1;
	std::stringstream s(arg);
	std::string word;

	while (s >> word) {
		if (word.length() > 1)
			return (std::cout << "Error\n", 0);
		else if (!isdigit(word[0]) && word[0] != '-' && word[0] != '+' && word[0] != '*' && word[0] != '/')
			return (std::cout << "Error\n", 0);
		if (isnumber(word[0]))
			s1.push(std::atoi(word.c_str()));
		else {
			if (s1.size() < 2)
				return (std::cout << "Error : syntax!!\n", 0);
			else
				calcul(s1, word[0]);
		}
	}
	if (s1.size() != 1)
		return (std::cout << "Error : syntax!!\n", 0);
	std::cout << s1.top() << std::endl;
	return (1);
}

int main(int ac, char const *av[])
{
	if (ac == 2)
		parseInput(av[1]);
	else
		std::cout << "bad args!!\n";
	return 0;
}

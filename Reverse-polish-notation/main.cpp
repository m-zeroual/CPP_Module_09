/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:45:08 by mzeroual          #+#    #+#             */
/*   Updated: 2023/11/17 15:01:54 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char const *av[])
{
	if (ac == 2)
		parseInput(av[1]);
	else
		std::cout << "bad args!!\n";
	return 0;
}
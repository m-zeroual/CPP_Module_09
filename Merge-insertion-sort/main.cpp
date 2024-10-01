/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:51:45 by mzeroual          #+#    #+#             */
/*   Updated: 2023/11/19 15:17:39 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// --------------- main --------------------
int main(int ac, char *av[])
{
	std::vector<int>    vector;
	std::deque<int>     deque;
	float				us;
	clock_t				time;
	
	if (ac > 1)
	{
		av = av + 1;
		for (int i = 0; i < ac - 1; i++) {
			if (!parse(av[i]))
				return (1);
			vector.push_back(std::atoi(av[i]));
			deque.push_back(std::atoi(av[i]));
		}
		display("Before:\t", vector);
		time = clock();
		recursion(vector);
		us = (float)(clock() - time) / CLOCKS_PER_SEC * 1000;
		display("After:\t", vector);
		std::cout << "Time to process a range of " << ac-1 << " elements with std::vector " << us << " us\n";

		time = clock();
		recursion(deque);
		us = ( (float)(clock() - time) / CLOCKS_PER_SEC * 1000 );
		std::cout << "Time to process a range of " << ac-1 << " elements with std::deque " << us << " us\n";
	}
	else
		std::cout << "give me positive numbers to sort.\n";
	return 0;
}

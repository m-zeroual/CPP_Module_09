/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:53:33 by mzeroual          #+#    #+#             */
/*   Updated: 2023/11/17 11:20:51 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <algorithm>

bool comp(const _data& s1, const _data& s2)
{
	return (s1.date < s2.date);
}

void _exchange(std::list<_data> data, _data input)
{
	data.sort(comp);
	std::list<_data>::iterator  tmp = std::lower_bound(data.begin(), data.end(), input, comp);
	if (input.date == (*tmp).date)
		std::cout << input.date << " => " << input.value << " => " << (strtod(input.value.c_str(), NULL) * strtod((*tmp).value.c_str(), NULL)) << std::endl;
	else
		std::cout << input.date << " => " << input.value << " => " << (strtod(input.value.c_str(), NULL) * strtod((*--tmp).value.c_str(), NULL)) << std::endl;
}

// _data, parseLine are define in header file
// _exchange are already define in top of code

int main(int argc, char* av[]) {
    if (argc < 2) {
        std::cerr << "Error: You need to provide a file name as an argument" << std::endl;
        return 1;
    }

    std::ifstream datafile("./files/data.csv");
    if (!datafile.is_open()) {
        std::cerr << "Error: Data file not found" << std::endl;
        return 1;
    }

    std::ifstream infile(av[1]);
    if (!infile.is_open()) {
        std::cerr << "Error: File " << av[1] << " not found" << std::endl;
        return 1;
    }

    std::string content;
    int i = 0;
    std::list<_data> data;

    // Reading and parsing the data file
    while (std::getline(datafile, content)) {
        if (!parseLine(content, ",", i++, data)) {
            std::cerr << "Error: Bad input in line " << i << " >> " << content << std::endl;
            return 1;
        }
    }

    i = 0;
    std::list<_data> input;

    // Reading and parsing the input file
    while (std::getline(infile, content)) {
        if (!content.empty()) {
            if (!parseLine(content, "|", i++, input)) {
                std::cerr << "Error: Bad input in line " << i << " >> " << content << std::endl;
                return 1;
            }

            // Safely process the input list
            for (std::list<_data>::iterator it = input.begin(); it != input.end(); ) {
                _exchange(data, *it);  
                it = input.erase(it);  // Safely erase after processing
            }
        }
    }

    // Closing files
    infile.close();
    datafile.close();

    return 0;
}

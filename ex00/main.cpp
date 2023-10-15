/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:53:33 by mzeroual          #+#    #+#             */
/*   Updated: 2023/10/15 20:33:39 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
std::list<std::string> split(std::string line, std::string delimiter)
{
    size_t npos = -1;
    size_t first = 0;
    std::list<std::string> parse;
    

    size_t pos = line.find(delimiter);
    if (pos != npos)
    {
        while (pos != npos)
        {
            parse.push_back(line.substr(0, pos));
            line = line.substr(pos + 1, line.size());
            first = pos + 1;
            pos = line.find(delimiter);
        }
        parse.push_back(line.substr(0, line.size()));

    }
    return (parse);
}

void removeSpace(std::string &remove)
{
    size_t npos = -1;
    
    size_t pos = remove.find(" ");
    if (pos != npos && pos)
        remove = remove.substr(0, pos);
    else if (!pos)
        remove = remove.substr(1, remove.size());
        
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
void prseLine(std::string line, int lineNum)
{
    (void)lineNum;
    std::list<std::string> date;
    
    if (!line.empty()) {
        std::list<std::string> lineSplit = split(line, "|");
        std::list<std::string>::iterator firstIt = lineSplit.begin();
        
        for (std::list<std::string>::iterator it = firstIt; it != lineSplit.end(); it++)
        {
            if (lineNum == 2)
                exit (0);
            removeSpace(*it);
            if (lineNum != 0)
                std::cout << "#" << *it << "#\n";
            if (it == firstIt) {
                date = split(*it, "-");
            }
            for (std::list<std::string>::iterator it1 = date.begin(); it1 != date.end(); it1++)
            {
                if (lineNum == 2)
                    exit (0);
                std::cout << "$" << *it1 << "$\n";
                if (!isNumber(*it1))
                    std::cerr << "Error : in line " << lineNum << " date not valid"<< std::endl;
                    
                // if ((++it1) ==  paseFisrtPart.end())
                //     std::cout << std::endl;
                // it1--;
            }
            // break ;
            // std::cout << "#\n";
            // std::cout << std::endl;
        }
    }
//     for (size_t i = 0; i < 14; i++)
//     {
//         // int j = 0;
//         if (!line.empty() && lineNum != 0 && ((i == 10 && line[i] != ' ') || (i == 12 && line[i] != ' '))) {
//             for (std::list<std::string>::iterator it1 = paseFisrtPart.begin(); it1 != paseFisrtPart.end(); it1++)
//             {
//                 std::cout << *it1 << std::endl;
//                 if (paseFisrtPart.size() >= 4 || paseFisrtPart.size() < 3)
//                 {
//                     std::cerr << "Error : in line " << lineNum << " date format is must be like (Year-Month-Day)"<< std::endl;
//                     break ;
//                 }
                
//                 // else if (!isNumber(*it1))
//                 // {
//                 //     if (paseFisrtPart.size() == 0)
//                 //         std::cerr << "Error : in line " << lineNum << " Year not a number"<< std::endl;
//                 //     else if (paseFisrtPart.size() == 1)
//                 //         std::cerr << "Error : in line " << lineNum << " Month not a number"<< std::endl;
//                 //     else if (paseFisrtPart.size() == 2)
//                 //         std::cerr << "Error : in line " << lineNum << " Day not a number"<< std::endl;
//                 // }
//                 // std::cout << "$" << *it1 << "$ ";
//                 // if (!isNumber(*it1))
//                 //     std::cerr << "Error : in line " << lineNum << " date not a number"<< std::endl;
                    
//                 // if ((++it1) ==  paseFisrtPart.end())
//                 //     std::cout << std::endl;
//                 // it1--;
//             }
//             break ;
// //             std::cerr << "Error : in line " << lineNum << " You need this (format: \"date(\'Year-Month-Day\') | value\")\n\
// // date  : 4 Number for Year, two for Month and two for Day\n\
// // value : Number between 0 and 1000 (float and int)."<< std::endl;
//             // break ;
//         }
//     }

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
        prseLine(*it, i);
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

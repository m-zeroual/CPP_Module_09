/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:51:45 by mzeroual          #+#    #+#             */
/*   Updated: 2023/10/22 18:38:17 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
typedef std::pair< std::vector<int>, std::vector<int> > pair;

int parse(char *av)
{
    char *end = NULL;
    long n = std::strtol(av, &end, 10);
    if (*end)
        return (std::cout << "Error : not a number.\n", 0);
    else if (n < 0)
        return (std::cout << "Error : not a positive number.\n", 0);
    return (1);
}

std::vector<pair> convertToPair(std::vector<std::vector<int> > numbers, std::vector<int> &rest)
{
    std::vector<pair>   pairs;
    pair                p;
    size_t size = numbers.size() / 2 * 2;
    for (size_t i = 0; i < size; i += 2)
    {
        p.first = numbers[i];
        p.second = numbers[i+1];
        pairs.push_back(p);
    }
    if (size != numbers.size())
        rest = numbers[numbers.size() - 1];
    return (pairs);
}


std::vector<int> groupPair(pair p)
{
    std::vector<int> v;
    for (size_t i = 0; i < p.first.size(); i++)
    {
        v.push_back(p.first[i]);
    }
    for (size_t i = 0; i < p.second.size(); i++)
    {
        v.push_back(p.second[i]);
    }
    return (v);
}
std::vector<pair> merge(std::vector<pair> &vpairs)
{
    std::vector<pair>   pairs;
    pair                p;
    pair                swap;
    pair                rest;
    std::vector<int>    v1;
    std::vector<int>    v2;
    
    size_t size = (int)(vpairs.size() / 2) * 2;
    // std::cout << "size : " << size << std::endl;
    size_t i = 0;
    for (i = 0; i < size; i += 2)
    {
        // if (vpairs[i].second.back() < )
        if (vpairs[i].second.back() < vpairs[i].first.back())
        {
            swap.first = vpairs[i].second;
            swap.second = vpairs[i].first;
            vpairs[i].first = swap.first;
            vpairs[i].second = swap.second;
        }
        if (vpairs[i + 1].second.back() < vpairs[i + 1].first.back())
        {
            swap.first = vpairs[i + 1].second;
            swap.second = vpairs[i + 1].first;
            vpairs[i + 1].first = swap.first;
            vpairs[i + 1].second = swap.second;
        }
        v1 = groupPair(vpairs[i]);
        v2 = groupPair(vpairs[i + 1]);
        p.first = v1;
        p.second = v2;
        pairs.push_back(p);
        // std::cout << i << std::endl;
    }
    // std::cout << "i " << i << std::endl;
    if (i && size != vpairs.size())
    {
        if (vpairs[i].second.back() < vpairs[i].first.back())
        {
            rest.second = vpairs[i].first;
            rest.first = vpairs[i].second;
            std::cout << "rest " << rest.first.back() << " " << rest.second.back() << std::endl;
        }
        // {
        //     swap.first = vpairs[i - 1].second;
        //     swap.second = vpairs[i - 1].first;
        //     vpairs[i - 1].first = swap.first;
        //     vpairs[i - 1].second = swap.second;
        // }
    }
    return (pairs);
}

std::vector<pair> rec(std::vector<pair> vpairs)
{
    std::vector<pair>   pairs;

    pairs = merge(vpairs);
    // pairs = sort(vpairs);
    for (std::vector<pair >::iterator it = vpairs.begin(); it != vpairs.end() ; it++)
    {
        std::cout << "{";
        for (size_t i = 0; i < (*it).first.size(); i++)
            std::cout << (*it).first[i] << " ";
        std::cout << ":";
        for (size_t i = 0; i < (*it).second.size(); i++)
            std::cout << (*it).second[i] << " ";
        std::cout << "},";
    }
    std::cout << std::endl;

    if (vpairs.size() != 1)
        rec(pairs);
    return (pairs);
}

int main(int ac, char *av[])
{
    // std::vector<>
    std::vector<int>                rest;
    std::vector<int>                number;
    std::vector<std::vector<int> >  numbers;
    std::vector<pair>               vpairs;
    pair p;
    if (ac > 1)
    {
        av = av + 1;
        for (int i = 0; i < ac - 1; i++)
        {
            if (!parse(av[i]))
                return (1);
            number.push_back(std::atoi(av[i]));
            numbers.push_back( number );
            number.pop_back();
        }

        vpairs = convertToPair(numbers, rest);
        if (!rest.empty())
            std::cout << "mmmmmm" << rest.back() << std::endl;
        // std::cout << "here\n";
        vpairs = rec(vpairs);        
    }
    else
        std::cout << "give me positive numbers to sort.\n";
    return 0;
}

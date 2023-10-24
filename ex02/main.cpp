/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:51:45 by mzeroual          #+#    #+#             */
/*   Updated: 2023/10/24 10:34:41 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
void display(std::vector <int> d)
{
    for (size_t i = 0; i < d.size(); i++)
    {
        std::cout << d[i] << " ";
    }
        
    
}
vPair convertToPair(vVector numbers, std::vector<int> &rest)
{
    vPair   pairs;
    pair    p;
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


std::vector<int> group(pair p)
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
pair group(std::vector<int> v)
{
    std::vector<int>    v1;
    std::vector<int>    v2;
    pair                p;
    size_t size = v.size();
    
    for (size_t i = 0; i < size; i++)
    {
        if (i < size / 2)
            v1.push_back(v[i]);
        else
            v2.push_back(v[i]);
    }
    p.first = v1;
    p.second = v2;
    return (p);
}

void swapPair(pair &p)
{
    pair    swap;
    
    swap.first = p.second;
    swap.second = p.first;
    p.first = swap.first;
    p.second = swap.second;
}
void merge(vPair &vpairs)
{
    pair    rest;
    vPair   p;
    
    size_t size = (int)(vpairs.size() / 2) * 2;
    size_t i = 0;
    for (i = 0; i < size; i += 2)
    {
        for (size_t j = 0; j < 2; j++)
        {
            if (vpairs[(i + j)].second.back() < vpairs[i + j].first.back())
                swapPair(vpairs[i + j]);
        }
        if (vpairs[i + 1].second.back() < vpairs[i].second.back())
            std::swap(vpairs[i], vpairs[i + 1]);
        rest.first = group(vpairs[i]);
        rest.second = group(vpairs[i + 1]);
        p.push_back(rest);
    }

    if (size != vpairs.size())
    {
        if (vpairs[i].second.back() < vpairs[i].first.back())
            swapPair(vpairs[i]);
        rest = vpairs[i];
        
        // std::cout << "rest : {";
        // for (size_t i = 0; i < rest.first.size(); i++)
        // {
        //     std::cout << rest.first[i] << " ";
        // }
        // std::cout << " : ";
        // for (size_t i = 0; i < rest.second.size(); i++)
        // {
        //     std::cout << rest.second[i] << " ";
        // }
        // // std::cout << rest.first.back();
        // std::cout << "}\n";
    }
    // vpairs.clear();
    vpairs = p;
    // return (pairs);
}

bool comp(std::vector<int> a, std::vector<int> b)
{
    return (a.back() < b.back());
}
void insertion(vPair &vpairs)
{
    vPair   tmp;
    vPair   mchain;
    pair    pair;

        size_t size = vpairs.size();
        for (size_t i = 0; i < size; i++)
        {
            // std::cout << "after push : ";
            // for (size_t j = 0; j < vpairs[i].second.size(); j++)
            // {
                // std::cout << i << "\n";
            // }
                // pair.first = vpairs[i].second;
                // pair.second = vpairs[i + 1].second;
                tmp.push_back(group(vpairs[i].first));
                tmp.push_back(group(vpairs[i].second));
                
                // display(mchain[i].first);
                // display(mchain[i].second);
                // std::cout << "\n";
                // display(mchain[i].second);
            // std::cout << "main chain is : ";
            // for (size_t i = 0; i < mchain.size(); i++)
            // {
            //     for (size_t j = 0; j < mchain[j].size(); j++)
            //     {
            //         std::cout << mchain[i][j] << " ";
            //     }
                
            // }
            // std::cout << "\n";
            
        }
        vpairs = tmp;
        for (vPair::iterator it = vpairs.begin(); it != vpairs.end() ; it++)
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
        // for (size_t i = 0; i < size; i++)
        // {
        //     std::vector<std::vector<int> >::iterator pos = std::lower_bound(mchain.begin(), mchain.end(), vpairs[i].first, comp);
        //     for (std::vector<std::vector<int> >::iterator  it = mchain.begin(); it < mchain.end(); it++)
        //     {
        //         if (it == pos)
        //         {
        //             mchain.insert(it, vpairs[i].first);
        //         }
        //     } 
        // }
        //     std::cout << "main chain is : ";
        //     for (size_t i = 0; i < mchain.size(); i++)
        //     {
        //         for (size_t j = 0; j < mchain[i].size(); j++)
        //         {
        //             std::cout << mchain[i][j] << " ";
        //         }
                
        //     }
        //     std::cout << "\n";
        
    // }
}

void rec(vPair &vpairs)
{
    vPair   pairs(vpairs);
    vpairs.clear();
    std::cout << "before\n";
    for (std::vector<pair >::iterator it = pairs.begin(); it != pairs.end() ; it++)
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
    std::cout << "----------------------------------------------" << std::endl;

    merge(pairs);

    std::cout << "after\n";
    for (std::vector<pair>::iterator it = pairs.begin(); it != pairs.end() ; it++)
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
    
    // vpairs.clear();
    // exit(0);
    // std::cout << std::endl;
    
    // pairs = sort(vpairs);
    // std::cout << "recursion\n";
    // for (std::vector<pair >::iterator it = vpairs.begin(); it != vpairs.end() ; it++)
    // {
    //     std::cout << "{";
    //     for (size_t i = 0; i < (*it).first.size(); i++)
    //         std::cout << (*it).first[i] << " ";
    //     std::cout << ":";
    //     for (size_t i = 0; i < (*it).second.size(); i++)
    //         std::cout << (*it).second[i] << " ";
    //     std::cout << "},";
    // }
    // std::cout << std::endl;

    vpairs = pairs;
    if (vpairs.size() != 1)
        rec(vpairs);
    // std::cout << "after\n";
    // for (std::vector<pair >::iterator it = vpairs.begin(); it != vpairs.end() ; it++)
    // {
    //     std::cout << "{";
    //     for (size_t i = 0; i < (*it).first.size(); i++)
    //         std::cout << (*it).first[i] << " ";
    //     std::cout << ":";
    //     for (size_t i = 0; i < (*it).second.size(); i++)
    //         std::cout << (*it).second[i] << " ";
    //     std::cout << "},";
    // }
    // std::cout << std::endl;
    insertion(vpairs);

    // return (pairs);
}

int main(int ac, char *av[])
{
    // std::vector<>
    std::vector<int>    rest;
    std::vector<int>    number;
    
    vVector             numbers;
    vPair               vpairs;
    vPair               save;
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
        if (numbers.size() == 1)
            return (std::cout << numbers[0].back() << std::endl, 0);

        vpairs = convertToPair(numbers, rest);
        if (!rest.empty())
            std::cout << "rest : " << rest.back() << std::endl;
        // std::cout << "here\n";
        rec(vpairs);
            std::cout << "after\n";
        // for (std::vector<pair>::iterator it = vpairs.begin(); it != vpairs.end() ; it++)
        // {
        //     std::cout << "{";
        //     for (size_t i = 0; i < (*it).first.size(); i++)
        //         std::cout << (*it).first[i] << " ";
        //     std::cout << ":";
        //     for (size_t i = 0; i < (*it).second.size(); i++)
        //         std::cout << (*it).second[i] << " ";
        //     std::cout << "},";
        // }
        // std::cout << std::endl; 
    }
    else
        std::cout << "give me positive numbers to sort.\n";
    return 0;
}

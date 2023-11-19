/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:52:21 by mzeroual          #+#    #+#             */
/*   Updated: 2023/11/17 15:03:46 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <utility>

// std::vector
typedef std::pair< std::vector<int>, std::vector<int> > pairVector;
typedef std::vector<pairVector>                         vectorPair;
typedef std::vector<std::vector<int> >                  vectorVector;

// std::deque
typedef std::pair< std::deque<int>, std::deque<int> >   pairDeque;
typedef std::deque<pairDeque>                           dequePair;
typedef std::deque< std::deque<int> >                   dequeDeque;

// ---------- template function -------------
template<typename T>
void display(std::string s, T arrP)
{
	std::cout << s;
	for (size_t i = 0; i < arrP.size(); i++)
		std::cout << arrP[i] << " ";
	std::cout << std::endl;
}
template<typename T>
void swapPair(T &p)
{
	T	swap;

	swap.first = p.second;
	swap.second = p.first;
	p.first = swap.first;
	p.second = swap.second;
}
template<typename T>
bool comp(T a, T b)
{
	return (a.back() < b.back());
}

template<typename T>
void sort(T &arrP)
{
	size_t size = arrP.size();
	for (size_t i = 0; i < size; i++)
	{
		if (comp(arrP[i].second, arrP[i].first))
			swapPair(arrP[i]);
	}
}

int parse(char *av);

// ------------------------- vector ---------------------------------
vectorPair merge(std::vector<int> v, std::vector<int> &rest);
std::vector<int> convertFromPairToVector(vectorPair vP);
std::vector<int> convertToVector(vectorVector v);
void insertion(std::vector<int> &v, std::vector<int> rest);
void recursion(std::vector<int> &v);


// ------------------------- deque ---------------------------------
dequePair merge(std::deque<int> v, std::deque<int> &rest);
std::deque<int> convertFromPairToDeque(dequePair vP);
std::deque<int> convertToDeque(dequeDeque v);
void insertion(std::deque<int> &v, std::deque<int> rest);
void recursion(std::deque<int> &v);

#endif
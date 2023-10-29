/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:51:45 by mzeroual          #+#    #+#             */
/*   Updated: 2023/10/29 14:46:45 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cmath>
int contComp = 0;
int mergeCount = 0;

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
		std::cout << d[i] << " ";
}

void swapPair(pair &p)
{
	pair    swap;

	swap.first = p.second;
	swap.second = p.first;
	p.first = swap.first;
	p.second = swap.second;
}

vPair merge(std::vector<int> v, std::vector<int> &rest)
{
	pair				pair;
	vPair				vp;
	size_t				c;
	std::vector<int>	v1;
	std::vector<int>	v2;

	c = 1 << ++mergeCount;
	size_t size = v.size() / c * c;
	for (size_t i = 0; i < size; i+=c) {
		for (size_t j = 0; j < c / 2; j++) 
			v1.push_back(v[i+j]);
		for (size_t j = c / 2; j < c; j++) 
			v2.push_back(v[i+j]);
		pair = std::make_pair(v1, v2);
		vp.push_back(pair);
		v1.clear();
		v2.clear();
	}
	if (size != v.size())
	{
		for (size_t i = size; i < v.size(); i++)
			v1.push_back(v[i]);
		rest = v1;
		v1.clear();
	}
	return(vp);
}
void sort(vPair &vp)
{
	size_t size = vp.size();
	for (size_t i = 0; i < size; i++)
	{
		contComp++;
		if (vp[i].second.back() < vp[i].first.back())
			swapPair(vp[i]);
	}
}
bool comp(std::vector<int> a, std::vector<int> b)
{
	contComp++;
	return (a.back() < b.back());
}
std::vector<int> convertFromPairToVector(vPair vP)
{
	std::vector<int> v; 
	for (size_t i = 0; i < vP.size(); i++)
	{
		for (size_t j = 0; j < vP[i].first.size(); j++)
			v.push_back(vP[i].first[j]);
	
		for (size_t j = 0; j < vP[i].second.size(); j++)
			v.push_back(vP[i].second[j]);
	}
	return (v);
}

std::vector<int> convertToVector(vVector v)
{
	std::vector<int> v1;
	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = 0; j < v[i].size(); j++)
			v1.push_back(v[i][j]);
	}
	return (v1);
}

void insertion(std::vector<int> &v, std::vector<int> rest)
{
	std::cout << ">>>>> REV <<<<<" << std::endl;
	pair							p;
	vPair							vp;
	std::vector<int>				v1;
	std::vector<int>				v2;
	std::vector< std::vector<int> >	mchain;
	std::vector< std::vector<int> >	paned;
	// std::vector<size_t>				jacobsthal;

	// for (size_t i = 0; i < 20; i++)
	// {
	// 	jacobsthal.push_back((pow(2, ((i + 1) + 1)) + pow(-1, ( i + 1))) / 3);
	// 	// std::cout << jacobsthal[i] << std::endl;
	// }
	
	size_t c = 1 << mergeCount--;

	size_t size = v.size() / c * c;
	for (size_t i = 0; i < size; i+=c) {
		for (size_t j = 0; j < c / 2; j++) 
			v1.push_back(v[i+j]);
		for (size_t j = c / 2; j < c; j++) 
			v2.push_back(v[i+j]);
		p = std::make_pair(v1, v2);
		vp.push_back(p);
		v1.clear();
		v2.clear();
	}
	// std::cout << "vp size\t: " << vp.size() << std::endl;
	for (size_t i = 0; i < vp.size(); i++) {
		paned.push_back(vp[i].first);
		mchain.push_back(vp[i].second);
	}
	if (rest.size())
		paned.push_back(rest);
	mchain.insert(mchain.begin(), *paned.begin());
	int countPush = 0;
	for (size_t i = 1; i < paned.size() - 1; i++) {
			size_t jacobsthal = (pow(2, ((i+1) + 1)) + pow(-1, (i+1))) / 3;						//(2k+1 + (−1)k)/3
			size_t jacobsthalEnd = ((pow(2, ((i+1) - 1) + 1) + pow(-1, ((i+1) - 1))) / 3) + 1;	//(2(k-1)+1 + (−1)(k-1))/3 => Btk−1+1
			// if (jacobsthal > paned.size() || jacobsthalEnd > paned.size())
			// 	break ;
			// std::cout << "size\t: " << paned.size() << std::endl;
			// std::cout << "here\t: " << jacobsthal << " " << jacobsthalEnd << std::endl;
			// std::cout << "start\t: " << jacobsthal << std::endl;
			// std::cout << "end\t: " << jacobsthalEnd << std::endl;
			// std::cout << "\n";
			// std::cout << "\n";
			if (jacobsthal > paned.size())
				jacobsthal = paned.size();
			// if (jacobsthalEnd > paned.size())
			// 	jacobsthalEnd = paned.size();
			// std::cout << "\n";
			// std::cout << "size\t: " << paned.size() << std::endl;
			// std::cout << "here\t: " << jacobsthal << " " << jacobsthalEnd << std::endl;
			std::cout << "start\t: " << jacobsthal << std::endl;
			std::cout << "end\t: " << jacobsthalEnd  << std::endl;
			std::cout << "\n";
			if (jacobsthalEnd > jacobsthal)
				break ;
			for (size_t j = jacobsthal; j >= jacobsthalEnd ; j--)
			{
				std::cout << "idx = " << j-1 << std::endl;
				display(paned[j-1]);
				std::cout << std::endl;
				// size_t jac = jacobsthal + i + j - ;
				// if(jac > mchain.size())
				// 	jac = mchain.size() - 1;
				mchain.insert(std::lower_bound(mchain.begin(), mchain.begin() + (jacobsthal + countPush), paned[j-1], comp), paned[j-1]);
				countPush++;
				// std::cout << "j = " << j << std::endl;
			}
			
			// for (size_t j = jacobsthal; j < jacobsthalEnd; j++)
			// {
			// 	std::cout << jacobsthal << std::endl;
			// 	std::cout << jacobsthalEnd << std::endl;
			// 	if (j > paned.size())
			// 		break;
			// 	// std::cout << j << std::endl;
			// }
			// mchain.insert(std::lower_bound(mchain.begin(), mchain.end(), paned[i], comp), paned[i]);

	}
	v = convertToVector(mchain);
}

void recursion(std::vector<int> &v)
{
	std::cout << ">>>>> REC <<<<<" << std::endl;
	std::vector<int>	rest;

	vPair vp = merge(v, rest);
	sort(vp);
	v = convertFromPairToVector(vp);
	if (vp.size() != 1)
		recursion(v);
	insertion(v, rest);

	// for (size_t i = 0; i < vpIn.size(); i++) {
	// 	paned.push_back(vpIn[i].first);
	// 	mchain.push_back(vpIn[i].second);
	// }
	// if (rest.size())
	// 	paned.push_back(rest);

	// mchain.insert(mchain.begin(), *paned.begin());
	// for (size_t i = 1; i < paned.size(); i++) {
	// 	mchain.insert(std::lower_bound(mchain.begin(), mchain.end(), paned[i], comp), paned[i]);
	// }
	// v = convertToVector(mchain);
}

int main(int ac, char *av[])
{
	std::vector<int>    numbers;

	if (ac > 1)
	{
		av = av + 1;
		for (int i = 0; i < ac - 1; i++)
		{
			if (!parse(av[i]))
				return (1);
			numbers.push_back(std::atoi(av[i]));
		}
		recursion(numbers);
		display(numbers);
		std::cout << std::endl;
		std::cout << "comp : " << contComp << std::endl; 
	}
	else
		std::cout << "give me positive numbers to sort.\n";
	return 0;
}

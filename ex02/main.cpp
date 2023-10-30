/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:51:45 by mzeroual          #+#    #+#             */
/*   Updated: 2023/10/30 17:29:10 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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






// ------------------------- vector ---------------------------------
vectorPair merge(std::vector<int> v, std::vector<int> &rest)
{
	pairVector			pair;
	vectorPair			vp;
	std::vector<int>	v1;
	std::vector<int>	v2;
	size_t				c;

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

std::vector<int> convertFromPairToVector(vectorPair vP)
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

std::vector<int> convertToVector(vectorVector v)
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
	pairVector			p;
	vectorPair			vp;
	std::vector<int>	v1;
	std::vector<int>	v2;
	vectorVector		mchain;
	vectorVector		paned;

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
	for (size_t i = 0; i < vp.size(); i++) {
		paned.push_back(vp[i].first);
		mchain.push_back(vp[i].second);
	}
	if (rest.size())
		paned.push_back(rest);
	mchain.insert(mchain.begin(), *paned.begin());
	int countPush = 0;
	size = mchain.size();
	for (size_t i = 1; i < paned.size(); i++) {
			size_t jacobsthalStart = (pow(2, ((i+1) + 1)) + pow(-1, (i+1))) / 3;				//(2k+1 + (−1)k)/3
			size_t jacobsthalEnd = ((pow(2, ((i+1) - 1) + 1) + pow(-1, ((i+1) - 1))) / 3) + 1;	//(2(k-1)+1 + (−1)(k-1))/3 => Btk−1+1
			if (jacobsthalStart > paned.size())
				jacobsthalStart = paned.size();
			if (jacobsthalEnd > paned.size())
				break ;
			for (size_t j = jacobsthalStart; j >= jacobsthalEnd ; j--) {
				countPush = jacobsthalStart + (mchain.size() - size) - (jacobsthalStart - j);
				mchain.insert(std::lower_bound(mchain.begin(), mchain.begin() + countPush , paned[j-1], comp<std::vector<int> >), paned[j-1]);
			}
	}
	v = convertToVector(mchain);
}

void recursion(std::vector<int> &v)
{
	if (v.size() == 1)
		return ;
	std::vector<int>	rest;

	vectorPair vp = merge(v, rest);
	sort(vp);
	v = convertFromPairToVector(vp);
	if (vp.size() != 1)
		recursion(v);
	insertion(v, rest);
}

// ------------------------- deque ---------------------------------
dequePair merge(std::deque<int> v, std::deque<int> &rest)
{
	pairDeque			pair;
	dequePair			vp;
	size_t				c;
	std::deque<int>		v1;
	std::deque<int>		v2;

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

std::deque<int> convertFromPairToDeque(dequePair vP)
{
	std::deque<int> v;

	for (size_t i = 0; i < vP.size(); i++)
	{
		for (size_t j = 0; j < vP[i].first.size(); j++)
			v.push_back(vP[i].first[j]);
	
		for (size_t j = 0; j < vP[i].second.size(); j++)
			v.push_back(vP[i].second[j]);
	}
	return (v);
}

std::deque<int> convertToDeque(dequeDeque v)
{
	std::deque<int> v1;

	for (size_t i = 0; i < v.size(); i++)
	{
		for (size_t j = 0; j < v[i].size(); j++)
			v1.push_back(v[i][j]);
	}
	return (v1);
}

void insertion(std::deque<int> &v, std::deque<int> rest)
{
	pairDeque			p;
	dequePair			vp;
	std::deque<int>		v1;
	std::deque<int>		v2;
	dequeDeque			mchain;
	dequeDeque			paned;

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
	for (size_t i = 0; i < vp.size(); i++) {
		paned.push_back(vp[i].first);
		mchain.push_back(vp[i].second);
	}
	if (rest.size())
		paned.push_back(rest);
	mchain.insert(mchain.begin(), *paned.begin());
	int countPush = 0;
	size = mchain.size();
	for (size_t i = 1; i < paned.size(); i++) {
			size_t jacobsthalStart = (pow(2, ((i+1) + 1)) + pow(-1, (i+1))) / 3;					//(2k+1 + (−1)k)/3
			size_t jacobsthalEnd = ((pow(2, ((i+1) - 1) + 1) + pow(-1, ((i+1) - 1))) / 3) + 1;	    //(2(k-1)+1 + (−1)(k-1))/3 => Btk−1+1
			if (jacobsthalStart > paned.size())
				jacobsthalStart = paned.size();
			if (jacobsthalEnd > paned.size())
				break ;
			for (size_t j = jacobsthalStart; j >= jacobsthalEnd ; j--) {
				countPush = jacobsthalStart + (mchain.size() - size) - (jacobsthalStart - j);
				mchain.insert(std::lower_bound(mchain.begin(), mchain.begin() + countPush , paned[j-1], comp<std::deque<int> >), paned[j-1]);
			}
	}
	v = convertToDeque(mchain);
}

void recursion(std::deque<int> &v)
{
	if (v.size() == 1)
		return ;
	std::deque<int>	rest;

	dequePair vp = merge(v, rest);
	sort(vp);
	v = convertFromPairToDeque(vp);
	if (vp.size() != 1)
		recursion(v);
	insertion(v, rest);
}


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
		us = ( (float)(clock() - time) / CLOCKS_PER_SEC * 1000 );
		display("After:\t", vector);
		std::cout << "Time to process a range of " << ac-1 << " elements with std::vector " << us << " us\n";
		mergeCount = 0;
		time = clock();
		recursion(deque);
		us = ( (float)(clock() - time) / CLOCKS_PER_SEC * 1000 );
		std::cout << "Time to process a range of " << ac-1 << " elements with std::deque " << us << " us\n";
	}
	else
		std::cout << "give me positive numbers to sort.\n";
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:51:45 by mzeroual          #+#    #+#             */
/*   Updated: 2023/10/28 18:08:37 by mzeroual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
int contComp = 0;
int mergeCount = 0;

std::vector<int> convertFromPairToVector(vPair vP);
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
// vPair convertToPair(vVector numbers, std::vector<int> &rest)
// {
// 	vPair   pairs;
// 	pair    p;
// 	size_t size = numbers.size() / 2 * 2;
// 	for (size_t i = 0; i < size; i += 2)
// 	{
// 		p.first = numbers[i];
// 		p.second = numbers[i+1];
// 		pairs.push_back(p);
// 	}
// 	if (size != numbers.size())
// 		rest = numbers[numbers.size() - 1];
// 	return (pairs);
// }

// std::vector<int> group(pair p)
// {
// 	std::vector<int> v;
// 	for (size_t i = 0; i < p.first.size(); i++)
// 	{
// 		v.push_back(p.first[i]);
// 	}
// 	for (size_t i = 0; i < p.second.size(); i++)
// 	{
// 		v.push_back(p.second[i]);
// 	}
// 	return (v);
// }
// pair group(std::vector<int> v)
// {
// 	std::vector<int>    v1;
// 	std::vector<int>    v2;
// 	pair                p;
// 	size_t size = v.size();
	
// 	for (size_t i = 0; i < size; i++)
// 	{
// 		if (i < size / 2)
// 			v1.push_back(v[i]);
// 		else
// 			v2.push_back(v[i]);
// 	}
// 	p.first = v1;
// 	p.second = v2;
// 	return (p);
// }

void swapPair(pair &p)
{
	pair    swap;
	
	swap.first = p.second;
	swap.second = p.first;
	p.first = swap.first;
	p.second = swap.second;
}
// void merge(vPair &vpairs, std::vector<int> &rest)
// {
// 	pair    swap;
// 	vPair   p;

// 	size_t size = (int)(vpairs.size() / 2) * 2;
// 	size_t i = 0;
// 	for (i = 0; i < size; i += 2) {
// 		for (size_t j = 0; j < 2; j++) {
// 			if (vpairs[(i + j)].second.back() < vpairs[i + j].first.back())
// 				swapPair(vpairs[i + j]);
// 		}
// 		if (vpairs[i + 1].second.back() < vpairs[i].second.back())
// 			std::swap(vpairs[i], vpairs[i + 1]);
// 		swap.first = group(vpairs[i]);
// 		swap.second = group(vpairs[i + 1]);
// 		p.push_back(swap);
// 	}
// 	if (size != vpairs.size()){
// 		if (vpairs[i].second.back() < vpairs[i].first.back())
// 			swapPair(vpairs[i]);
// 		rest = group(vpairs[i]);
// 	}
// 	vpairs = p;
// }

vPair merge(std::vector<int> v, std::vector<int> &rest)
{
	pair				pair;
	vPair				vp;
	size_t				c;
	std::vector<int>	v1;
	std::vector<int>	v2;

	c = pow(2, ++mergeCount);
	std::cout << "c = " << c << "\n";

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

// std::vector<int> groupSecond(std::vector<std::pair<int, int> > vp)
// {
// 	size_t size = vp.size() / 2 * 2;
// 	std::vector<int> v1;
// 	for (size_t i = 0; i < size; i++)
// 	{
// 		v1.push_back(vp[i].second);
// 	}
// 	return (v1);
// }
vPair insertion(std::vector<int> &v)
{
	std::cout << "\n\n>>>>> REV <<<<<" << std::endl;
	pair				p;
	vPair				vp;
	std::vector<int>	v1;
	std::vector<int>	v2;
	
	// mergeCount--;
	// mergeCount--;
	// std::cout << "after ";
	// display(v);
	// std::cout << "\n";
	size_t c = pow(2, mergeCount--);
	// mergeCount--;
	// std::cout << "c = " << c << "\n";

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
	return(vp);
	
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
void recursion(std::vector<int> &v)
{
	std::cout << ">>>>> REC <<<<<" << std::endl;
	std::vector<int>	rest;
	// std::vector<std::pair<int, int> > vp2;
	// if () check fisrt recurtion
	// display(v);
	vPair vp = merge(v, rest);
	sort(vp);
	
	// std::cout << "rest = ";
	// display(rest);
	// std::cout << "\n";
	// for (size_t i = 0; i < vp.size(); i++)
	// {
	// 	std::cout << "[";
	// 	for (size_t j = 0; j < vp[i].first.size(); j++)
	// 		std::cout << vp[i].first[j] << " ";
	// 	std::cout << ":";
	// 	for (size_t j = 0; j < vp[i].second.size(); j++)
	// 		std::cout << vp[i].second[j] << " ";
	// 	std::cout << "]";
	// }
	// std::cout << "\n";
	
	v = convertFromPairToVector(vp);

	// std::cout << "===> " << vp.size() << "\n";
	if (vp.size() && vp.size() != 1)
		recursion(v);

	pair							pair;
	vPair							tmp;
	std::vector< std::vector<int> >	mchain;
	std::vector< std::vector<int> >	paned;
	vPair vpIn = insertion(v);
	for (size_t i = 0; i < vpIn.size(); i++)
	{
		std::cout << "[";
		for (size_t j = 0; j < vpIn[i].first.size(); j++)
			std::cout << vpIn[i].first[j] << " ";
		std::cout << ":";
		for (size_t j = 0; j < vpIn[i].second.size(); j++)
			std::cout << vpIn[i].second[j] << " ";
		std::cout << "]";
	}
	std::cout << "\n";
	
	size_t size = vpIn.size();
	for (size_t i = 0; i < size; i++) {
		paned.push_back(vpIn[i].first);
		mchain.push_back(vpIn[i].second);
	}
	if (rest.size())
		paned.push_back(rest);

	// std::cout << "b mchain : ";
	// for (size_t i = 0; i < mchain.size(); i++) {
	// 	display(mchain[i]);
	// 	std::cout << ",";
	// 	}
	// std::cout << "\n";
	// std::cout << "paned : ";
	// for (size_t i = 0; i < paned.size(); i++) {
	// 	display(paned[i]);
	// 	std::cout << ",";
	// }
	// std::cout << "\n";

	mchain.insert(mchain.begin(), *paned.begin());
	for (size_t i = 1; i < paned.size(); i++)
		mchain.insert(std::lower_bound(mchain.begin(), mchain.end(), paned[i], comp), paned[i]);

	// std::cout << "a mchain : ";
	// for (size_t i = 0; i < mchain.size(); i++)
	// 	display(mchain[i]);
	// std::cout << "\n";

	v = convertToVector(mchain);

	display(v);
	std::cout << "\n";
	std::cout << "\n";
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

int main(int ac, char *av[])
{
	std::vector<int>    sortedN;
	std::vector<int>    rest;
	std::vector<int>    numbers;
	vPair               vpairs;
	vPair               save;
	pair				p;
	
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
		std::cout << "\n\n";
		display(numbers);
		// for (std::vector<pair>::iterator it = vpairs.begin(); it != vpairs.end() ; it++)
		// {
		// 	std::cout << "{";
		// 	for (size_t i = 0; i < (*it).first.size(); i++)
		// 		std::cout << (*it).first[i] << " ";
		// 	std::cout << ":";
		// 	for (size_t i = 0; i < (*it).second.size(); i++)
		// 		std::cout << (*it).second[i] << " ";
		// 	std::cout << "},";
		// }
		std::cout << "\ncomp : " << contComp << std::endl; 
	}
	else
		std::cout << "give me positive numbers to sort.\n";
	return 0;
}

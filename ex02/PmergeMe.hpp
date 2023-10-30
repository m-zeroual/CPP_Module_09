/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzeroual <mzeroual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:52:21 by mzeroual          #+#    #+#             */
/*   Updated: 2023/10/30 16:08:44 by mzeroual         ###   ########.fr       */
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


// std::deque
typedef std::pair< std::vector<int>, std::vector<int> > pairVector;
typedef std::vector<pairVector>                         vectorPair;
typedef std::vector<std::vector<int> >                  vectorVector;

// std::deque
typedef std::pair< std::deque<int>, std::deque<int> >   pairDeque;
typedef std::deque<pairDeque>                           dequePair;
typedef std::deque< std::deque<int> >                   dequeDeque;

#endif
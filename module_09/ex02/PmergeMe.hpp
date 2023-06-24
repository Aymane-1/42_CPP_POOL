/* ************************************************************************** */
/*                                                                                                                                5x4545                                                 */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:17:00 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/09 18:02:38 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sys/time.h>

//----------------------------------------***       VECTOR PART       ***-----------------------------------------------

void								parser(char **argv, std::vector<int> &arr);
void								parseInput(std::string input);
void								storeData(std::string input, std::vector<int> &arr);
std::vector<int>					fordJhonson(std::vector<int> &arr);
std::vector<std::pair<int, int> > 	MakePairs(std::vector<int> &arr);
void							 	sortPairs(std::vector<std::pair<int, int> > &arr);
std::vector<int>					divideSequence(std::vector<std::pair<int, int> > arrPairs);
std::vector<int>					insertPendElements(std::vector<int> pendElements, std::vector<int> &mainChain);
void								addElement_v1(int target, std::vector<int> &mainChain);
std::vector<int>					JacobsthalSequence(std::vector<int> smallestArr);
int									binarySearch(std::vector<int> mainChain, int target, int low, int high);
void								printData(std::vector<int> arr);
double								getTimeLap(struct timeval startTime, struct timeval endTime);

//----------------------------------------***        DEQUE PART      ***-----------------------------------------------


void								_parser(char **argv, std::deque<int> &arr);
void								_storeData(std::string input, std::deque<int> &arr);
std::deque<int>						_fordJhonson(std::deque<int> &arr);
std::deque<std::pair<int, int> > 	_MakePairs(std::deque<int> &arr);
void							 	_sortPairs(std::deque<std::pair<int, int> > &arr);
std::deque<int>						_divideSequence(std::deque<std::pair<int, int> > arrPairs);
std::deque<int>						_insertPendElements(std::deque<int> pendElements, std::deque<int> &mainChain);
void								_addElement_v1(int target, std::deque<int> &mainChain);
std::deque<int>						_JacobsthalSequence(std::deque<int> smallestArr);
int									_binarySearch(std::deque<int> mainChain, int target, int low, int high);
void								_printData(std::deque<int> arr);

#endif
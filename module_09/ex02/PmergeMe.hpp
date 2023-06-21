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
#include <cmath>

void								parseInput(std::string input);
void								storeData(std::string input, std::vector<int> &arr);
void								fordJhonson(std::vector<int> &arr);
std::vector<std::pair<int, int> > 	MakePairs(std::vector<int> &arr);
void							 	sortPairs(std::vector<std::pair<int, int> > &arr);
std::vector<int>					divideSequence(std::vector<std::pair<int, int> > arrPairs, int straggler);
std::vector<int>					insertPendElements(std::vector<int> pendElements, std::vector<int> &mainChain, int straggler);
void								addElement(int target, std::vector<int> &mainChain, int &index);
void								addstraggler(int target, std::vector<int> &mainChain);
std::vector<int>					JacobsthalSequence(std::vector<int> smallestArr);
int									binarySearch(std::vector<int> mainChain, int target, int low, int high);
void								printData(std::vector<int> arr);

#endif
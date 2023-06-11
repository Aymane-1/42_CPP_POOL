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

void								parseInput(std::string input);
void								storeData(std::string input, std::vector<int> &arr);
void								fordJhonson(std::vector<int> &arr);
std::vector<std::pair<int, int> > 	MakePairs(std::vector<int> &arr);
void							 	sortPairs(std::vector<std::pair<int, int> > &arr);
// void	makeSmallestBiggestlists(std::vector<int> &arr);
// void	sortBiggestList(std::vector<int> &Blist);
// void	insertSmallestList(std::vector<int> &Smallest, std::vector<int> &Biggest);
void								printData(std::vector<int> arr);

// Don't forget to add the last element is array length is odd!

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:17:36 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/14 20:16:24 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	parseInput(std::string input)
{
	int i = 0;
	int j = 0;
	while (input[i])
	{
		if (input[i] == '-')
		{
			j = i + 1;
			while(isdigit(input[j]))
				j++;
			if (input[j] == ' ' || !input[j])
				throw std::invalid_argument("Error: numbers should be positive!");
			else
				throw std::invalid_argument("Error: invalid arguments!");
		}
		if (!isdigit(input[i]) && input[i] != ' ')
			throw std::invalid_argument("Error: invalid arguments!");
		i++;
	}
}

void	storeData(std::string input, std::vector<int> &arr)
{
	int			inputIndex = 0;
	
	while (input[inputIndex] == ' ')
		inputIndex++;
	while (input[inputIndex])
	{
		std::string value = "";
		while (isdigit(input[inputIndex]))
		{
			value += input[inputIndex];
			inputIndex++;
		}
		if (value.empty())
		{
			inputIndex++;	
			continue;
		}
		arr.push_back(std::stoi(value));
		inputIndex++;
	}
}

void	printData(std::vector<int> arr)
{
	std::vector<int>::iterator it = arr.begin();
	while(it != arr.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

std::vector<std::pair<int, int> > 	MakePairs(std::vector<int> &arr)
{
	std::vector<std::pair<int, int> > 	arrPairs;
	std::vector<int>::iterator			it = arr.begin();
	std::vector<int>::iterator			next = it + 1;
	while (*it != arr.back())
	{
		arrPairs.push_back(std::make_pair(*it, *next));
		if (*next != arr.back())
			it += 2, next += 2;
		else
			it += 1, next += 1;
	}
	return (arrPairs);
}

void		sortPairs(std::vector<std::pair<int, int> > &arr)
{
	std::vector<std::pair<int, int> >::iterator it = arr.begin();
	while(it != arr.end())
	{
		if (it->first > it->second)
		{
			int temp;
			temp = it->first;
			it->first = it->second;
			it->second = temp;
		}
		it++;
	}
}

bool	descendOrder(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
	return (a.second < b.second);
}

void	divideSequence(std::vector<std::pair<int, int> > arrPairs)
{
	std::vector<int> pendElements;
	std::vector<int> mainChain;
	std::vector<std::pair<int, int> >::iterator it = arrPairs.begin();
	while(it != arrPairs.end())
	{
		pendElements.push_back(it->first);
		mainChain.push_back(it->second);
		it++;
	}
	insertPendElements(pendElements, mainChain);
}

void	insertPendElements(std::vector<int> &smallestArr, std::vector<int> &biggestArr)
{
	std::vector<int> jacobthalSeq = JacobsthalSequence(smallestArr);
	std::vector<int>::iterator smallestIt = smallestArr.begin();
	
	while(smallestIt != smallestArr.end())
	{
		biggestArr.insert(biggestArr.begin(), *smallestIt);
		smallestIt++;
	}
}

std::vector<int>	JacobsthalSequence(std::vector<int> smallestArr)
{
	std::vector<int> vec(smallestArr.size());
	vec[0] = 3;
	vec[1] = 5;
	for(int i = 2; i < (int)smallestArr.size(); i++)
		vec[i] = (smallestArr[i - 1]) + (smallestArr[i - 2] * 2);
	return (vec);
}

void	fordJhonson(std::vector<int> &arr)
{                                                      
	std::vector<std::pair<int, int> > 	arrPairs = MakePairs(arr);
	sortPairs(arrPairs); // sort each pair of [arrPairs] by biggest value.
	std::sort(arrPairs.begin(), arrPairs.end(), descendOrder); // then sort the [arrPairs] as a whole by biggest value of each of it's pairs.
	divideSequence(arrPairs); // create main chain and pend elements
}

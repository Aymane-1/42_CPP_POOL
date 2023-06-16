/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:17:36 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/16 23:07:34 by aechafii         ###   ########.fr       */
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

void	sortPairs(std::vector<std::pair<int, int> > &arr)
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

void	insertPendElements(std::vector<int> &pendElements, std::vector<int> &mainChain)
{
	(void)mainChain;
	std::vector<int>	jacobsthalSeq = JacobsthalSequence(pendElements); // jacobsthal sequence
	// std::vector<int>::iterator 	JSindex = jacobsthalSeq.begin();
	// std::vector<int>::iterator 	PDindex = pendElements.begin();
	std::vector<int>::iterator 	itt = jacobsthalSeq.begin();
	// mainChain.insert(mainChain.begin(), pendElements[std::distance(pendElements.begin(), PDindex)]);
	// PDindex++;
	// //------------------------------------------------------------------
	// std::vector<int>::iterator it = pendElements.begin();
	// while(it != pendElements.end())
	// {
	// 	std::cout << *it << " | ";
	// 	it++;
	// }
	// std::cout << std::endl;
	// //------------------------------------------------------------------
	// std::vector<int>::iterator target = mainChain.begin();
	// while (PDindex != pendElements.end())
	// {
	// 	mainChain.insert(target, pendElements[std::distance(pendElements.begin(), PDindex)]);
		
	// } 
	// itt = mainChain.begin();
	while(itt != jacobsthalSeq.end())
	{
		std::cout << *itt << " | ";
		itt++;
	}
}

std::vector<int>	JacobsthalSequence(std::vector<int> pendElements)
{
	std::vector<int> rawJacobsthalSeq(pendElements.size());
	rawJacobsthalSeq[0] = 3;
	rawJacobsthalSeq[1] = 5;
	for(int i = 2; i < (int)rawJacobsthalSeq.size(); i++)
		rawJacobsthalSeq[i] = (rawJacobsthalSeq[i - 1] + (rawJacobsthalSeq[i - 2] * 2));
	std::vector<int> customJacobsthalSeq(pendElements.size());
	std::vector<int>::iterator actual = rawJacobsthalSeq.begin();
	int index = 0;
	int target = 0;
	while (actual != rawJacobsthalSeq.end())
	{
		std::cout << "out JS insertion -----> " << *actual << std::endl;
		customJacobsthalSeq.insert(customJacobsthalSeq.begin() + index, *actual);
		actual++;
		if (index == 0)
			customJacobsthalSeq.insert(customJacobsthalSeq.begin() + 1, 2);
		else
			target = *(actual - 1) - 1;
		index++;
		std::cout << "target --> " << target << std::endl;
		std::cout << "prev --> " << *(actual - 1) << std::endl;
		std::cout << "actual --> " << *actual << std::endl;
		while((target < *(actual - 1) && target > *(actual - 2)))
		{
			customJacobsthalSeq.insert(customJacobsthalSeq.begin() + index, target);
			index++;
			target--;
		}
		std::cout << "end of loop\n";
		// std::cout << "entry target ---> " << target << std::endl;
		// std::cout << "entry *actual ---> " << *actual << std::endl;
		// std::cout << "entry *(actual - 1) ---> " << rawJacobsthalSeq[index] << std::endl;
	}
	return (customJacobsthalSeq);
}

void	fordJhonson(std::vector<int> &arr)
{                                                      
	std::vector<std::pair<int, int> > 	arrPairs = MakePairs(arr); // create pairs.
	sortPairs(arrPairs); // sort each pair of [arrPairs] by biggest value.
	std::sort(arrPairs.begin(), arrPairs.end(), descendOrder); // then sort the [arrPairs] as a whole by biggest value (the 'second' of each pair).
	divideSequence(arrPairs); // create main chain and pend elements.
}

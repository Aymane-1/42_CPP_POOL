/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:17:36 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/21 02:00:22 by aechafii         ###   ########.fr       */
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

void	divideSequence(std::vector<std::pair<int, int> > arrPairs, int straggler)
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
	insertPendElements(pendElements, mainChain, straggler);
}

int		binarySearch(std::vector<int> mainChain, int target, int low, int high)
{
	if (high >= low)
	{
		int mid = low + (high - low) / 2;
		if (mainChain[0] >= target)
			return 0;
		if (target >= *(mainChain.end() - 1))
			return std::distance(mainChain.begin(), mainChain.end());
		if (mainChain[mid] < target && (mainChain[mid + 1] > target))
			return mid + 1;
		if (mainChain[mid] > target)
			return binarySearch(mainChain, target, low, mid - 1);
		else
			return binarySearch(mainChain, target, mid + 1, high);
	}
	else
		return -1;
}

void	addElement(int target, std::vector<int> &mainChain, int &index)
{
	std::vector<int>::iterator MNindex = mainChain.begin();
	int x = binarySearch(mainChain, target, 0, std::distance(mainChain.begin(), mainChain.end()));
	std::advance(MNindex, x);
	mainChain.insert(MNindex, target);
	index++;
}


void	insertPendElements(std::vector<int> pendElements, std::vector<int> &mainChain, int straggler)
{
	(void)straggler;
	std::vector<int>	jacobsthalSeq = JacobsthalSequence(pendElements); // custom jacobsthal sequence
	std::vector<int>::iterator 	MNindex = mainChain.begin(); // iterator for insertion into mainChain
	int index = 0;
	mainChain.insert(mainChain.begin(), *(pendElements.begin())); // insert 1st element into mainChain
	while (index < (int)pendElements.size()) // insert the rest
	{
		if (jacobsthalSeq[index] > (int)pendElements.size())
		{
			int internalIndex = jacobsthalSeq[index];
			while (internalIndex > jacobsthalSeq[index - 1] * 2)
				internalIndex--;
			while (internalIndex < jacobsthalSeq[index] && index < (int)pendElements.size() - 1)
			{
				addElement(pendElements.at(index + 1), mainChain, index);
				internalIndex++;
			}
			break;
		}
		addElement(pendElements.at(index + 1), mainChain, index);
	}
	MNindex = mainChain.begin();
	while (MNindex != mainChain.end())
	{
		std::cout << *MNindex << " | ";
		MNindex++;
	}
}

std::vector<int>	JacobsthalSequence(std::vector<int> pendElements)
{
	std::vector<int> rawJacobsthalSeq(pendElements.size());
	rawJacobsthalSeq[0] = 3;
	rawJacobsthalSeq[1] = 5;
	for(int i = 2; i < (int)rawJacobsthalSeq.size(); i++)
		rawJacobsthalSeq[i] = (rawJacobsthalSeq[i - 1] + (rawJacobsthalSeq[i - 2] * 2));
	std::vector<int> customJacobsthalSeq(0);
	std::vector<int>::iterator actual = rawJacobsthalSeq.begin();
	int index = 0;
	int target = 0;
	while (customJacobsthalSeq.size() < pendElements.size())
	{
		customJacobsthalSeq.insert(customJacobsthalSeq.begin() + index, *actual);
		actual++;
		if (*actual == 3)
			target = 2;
		else
		{
			target = *(actual - 1) - 1;
			index++;
		}
		if (target == 2)
		{
			customJacobsthalSeq.insert(customJacobsthalSeq.begin() + 1, 2);
			index++;
			continue ;
		}
		while((target < *(actual - 1) && target > *(actual - 2)) && (customJacobsthalSeq.size() < pendElements.size()))
		{
			customJacobsthalSeq.insert(customJacobsthalSeq.begin() + index, target);
			index++;
			target--;
		}
	}
	std::vector<int>::iterator it = customJacobsthalSeq.end() - 1;
	while (*it == 0)
		customJacobsthalSeq.erase(it--);
	return (customJacobsthalSeq);
}

void	fordJhonson(std::vector<int> &arr)
{
	int straggler = 0;
	if (arr.size() % 2 != 0)
		straggler = *(arr.end() - 1);                                              
	std::vector<std::pair<int, int> > 	arrPairs = MakePairs(arr); // create pairs.
	sortPairs(arrPairs); // sort each pair of [arrPairs] by biggest value.
	std::sort(arrPairs.begin(), arrPairs.end(), descendOrder); // then sort the [arrPairs] as a whole by biggest value (the 'second' of each pair).
	divideSequence(arrPairs, straggler); // create main chain and pend elements.
}

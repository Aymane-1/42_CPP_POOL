/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:17:36 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/25 16:41:28 by aechafii         ###   ########.fr       */
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

//----------------------------------------***       VECTOR PART       ***-----------------------------------------------

void		parser(char **argv, std::vector<int> &arr)
{
	int 			i = 0;
	std::string		input = "";
	while (argv[++i])
	{
		input = static_cast<std::string>(argv[i]);
		parseInput(input);
	}
	i = 0;
	while (argv[++i])
	{
		input = static_cast<std::string>(argv[i]);
		storeData(input, arr);
	}
}

void	storeData(std::string input, std::vector<int> &arr)
{
	int		inputIndex = 0;
	
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
		arr.push_back(std::stoi(value));
		while (input[inputIndex] == ' ')
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
	while (it != arr.end())
	{
		if (next != arr.end() && it !=  arr.end() - 1)
		{
			arrPairs.push_back(std::make_pair(*it, *next));
			it += 2,  next += 2;
		}
		else
			break;
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

std::vector<int>	divideSequence(std::vector<std::pair<int, int> > arrPairs)
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
	return (insertPendElements(pendElements, mainChain));
}

int		binarySearch(std::vector<int> mainChain, int target, int low, int high)
{
	if (high >= low)
	{
		int mid = low + (high - low) / 2;
		if (target == mainChain[mid])
			return mid;
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
		throw std::runtime_error("Error: binary search failed!");
}

void	addElement_v1(int target, std::vector<int> &mainChain)
{
	std::vector<int>::iterator MNindex = mainChain.begin();
	int x = binarySearch(mainChain, target, 0, std::distance(mainChain.begin(), mainChain.end()));
	std::advance(MNindex, x);
	mainChain.insert(MNindex, target);
}

std::vector<int>	insertPendElements(std::vector<int> pendElements, std::vector<int> &mainChain)
{
	std::vector<int>	jacobsthalSeq = JacobsthalSequence(pendElements); // custom jacobsthal sequence
	mainChain.insert(mainChain.begin(), *(pendElements.begin())); // insert 1st element into mainChain
	int index = 0;
	while(index < (int)pendElements.size())
	{
		if (jacobsthalSeq[index] < (int)pendElements.size()) // insert based on jacobsthal seq index
			addElement_v1(pendElements.at(jacobsthalSeq[index++] - 1), mainChain);
		else // if jacobsthal seq index if out of range, add the rest;
			while (++index < (int)pendElements.size())
				addElement_v1(pendElements.at(index), mainChain);
	}
	return (mainChain);
}

std::vector<int>	JacobsthalSequence(std::vector<int> pendElements)
{
	std::vector<int> rawJacobsthalSeq(pendElements.size());
	rawJacobsthalSeq[0] = 3;
	rawJacobsthalSeq[1] = 5;
	for(int i = 2; i < (int)rawJacobsthalSeq.size(); i++)
		rawJacobsthalSeq[i] = (rawJacobsthalSeq[i - 1] + (rawJacobsthalSeq[i - 2] * 2));
	std::vector<int> customJacobsthalSeq;
	std::vector<int>::iterator actual = rawJacobsthalSeq.begin();
	int index = 0;
	int target = 0;
	while (customJacobsthalSeq.size() < pendElements.size())
	{
		customJacobsthalSeq.insert(customJacobsthalSeq.begin() + index, *actual);
		actual++;
		if (*actual == 3 && actual == rawJacobsthalSeq.begin())
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

double		getTimeLap(struct timeval startTime, struct timeval endTime)
{
	long seconds = endTime.tv_sec - startTime.tv_sec;
	long microseconds = endTime.tv_usec - startTime.tv_usec;
	return (seconds * 1000.0 + microseconds / 1000.0);
}

std::vector<int>	fordJhonson(std::vector<int> &arr)
{
	std::vector<std::pair<int, int> > 	arrPairs = MakePairs(arr); // create pairs.
	sortPairs(arrPairs); // sort each pair of [arrPairs] by biggest value.
	std::sort(arrPairs.begin(), arrPairs.end(), descendOrder); // then sort the [arrPairs] as a whole by biggest value (the 'second' of each pair).
	std::vector<int> mainChain = divideSequence(arrPairs); // create main chain and pend elements.
	if (arr.size() % 2 != 0) // add straggler if there's one
		addElement_v1(*(arr.end() - 1), mainChain);
	return (mainChain);
}

//----------------------------------------***        DEQUE PART      ***-----------------------------------------------

void		_parser(char **argv, std::deque<int> &arr)
{
	int 			i = 0;
	std::string		input = "";
	while (argv[++i])
	{
		input = static_cast<std::string>(argv[i]);
		parseInput(input);
	}
	i = 0;
	while (argv[++i])
	{
		input = static_cast<std::string>(argv[i]);
		_storeData(input, arr);
	}
}

void	_storeData(std::string input, std::deque<int> &arr)
{
	int		inputIndex = 0;
	
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
		arr.push_back(std::stoi(value));
		while (input[inputIndex] == ' ')
			inputIndex++;
	}
}

void	_printData(std::deque<int> arr)
{
	std::deque<int>::iterator it = arr.begin();
	while(it != arr.end())
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

std::deque<std::pair<int, int> > 	_MakePairs(std::deque<int> &arr)
{
	std::deque<std::pair<int, int> > 	arrPairs;
	std::deque<int>::iterator			it = arr.begin();
	std::deque<int>::iterator			next = it + 1;
	while (it != arr.end())
	{
		if (next != arr.end() && it !=  arr.end() - 1)
		{
			arrPairs.push_back(std::make_pair(*it, *next));
			it += 2,  next += 2;
		}
		else
			break;
	}
	return (arrPairs);
}

void	_sortPairs(std::deque<std::pair<int, int> > &arr)
{
	std::deque<std::pair<int, int> >::iterator it = arr.begin();
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

bool	_descendOrder(const std::pair<int, int> &a, const std::pair<int, int> &b)
{
	return (a.second < b.second);
}

std::deque<int>	_divideSequence(std::deque<std::pair<int, int> > arrPairs)
{
	std::deque<int> pendElements;
	std::deque<int> mainChain;
	std::deque<std::pair<int, int> >::iterator it = arrPairs.begin();
	while(it != arrPairs.end())
	{
		pendElements.push_back(it->first);
		mainChain.push_back(it->second);
		it++;
	}
	return (_insertPendElements(pendElements, mainChain));
}

int		_binarySearch(std::deque<int> mainChain, int target, int low, int high)
{
	if (high >= low)
	{
		int mid = low + (high - low) / 2;
		if (target == mainChain[mid])
			return mid;
		if (mainChain[0] >= target)
			return 0;
		if (target >= *(mainChain.end() - 1))
			return std::distance(mainChain.begin(), mainChain.end());
		if (mainChain[mid] < target && (mainChain[mid + 1] > target))
			return mid + 1;
		if (mainChain[mid] > target)
			return _binarySearch(mainChain, target, low, mid - 1);
		else
			return _binarySearch(mainChain, target, mid + 1, high);
	}
	else
		throw std::runtime_error("Error: binary search failed!");
}

void	_addElement_v1(int target, std::deque<int> &mainChain)
{
	std::deque<int>::iterator MNindex = mainChain.begin();
	int x = _binarySearch(mainChain, target, 0, std::distance(mainChain.begin(), mainChain.end()));
	std::advance(MNindex, x);
	mainChain.insert(MNindex, target);
}

std::deque<int>	_insertPendElements(std::deque<int> pendElements, std::deque<int> &mainChain)
{
	std::deque<int>	jacobsthalSeq = _JacobsthalSequence(pendElements); // custom jacobsthal sequence
	mainChain.insert(mainChain.begin(), *(pendElements.begin())); // insert 1st element into mainChain
	int index = 0;
	while(index < (int)pendElements.size())
	{
		if (jacobsthalSeq[index] < (int)pendElements.size()) // insert based on jacobsthal seq index
			_addElement_v1(pendElements.at(jacobsthalSeq[index++] - 1), mainChain);
		else // if jacobsthal seq index if out of range, add the rest;
			while (++index < (int)pendElements.size())
				_addElement_v1(pendElements.at(index), mainChain);
	}
	return (mainChain);
}

std::deque<int>	_JacobsthalSequence(std::deque<int> pendElements)
{
	std::deque<int> rawJacobsthalSeq(pendElements.size());
	rawJacobsthalSeq[0] = 3;
	rawJacobsthalSeq[1] = 5;
	for(int i = 2; i < (int)rawJacobsthalSeq.size(); i++)
		rawJacobsthalSeq[i] = (rawJacobsthalSeq[i - 1] + (rawJacobsthalSeq[i - 2] * 2));
	std::deque<int> customJacobsthalSeq;
	std::deque<int>::iterator actual = rawJacobsthalSeq.begin();
	int index = 0;
	int target = 0;
	while (customJacobsthalSeq.size() < pendElements.size())
	{
		customJacobsthalSeq.insert(customJacobsthalSeq.begin() + index, *actual);
		actual++;
		if (*actual == 3 && actual == rawJacobsthalSeq.begin())
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
	return (customJacobsthalSeq);
}

std::deque<int>	_fordJhonson(std::deque<int> &arr)
{
	std::deque<std::pair<int, int> > 	arrPairs = _MakePairs(arr); // create pairs.
	_sortPairs(arrPairs); // sort each pair of [arrPairs] by biggest value.
	std::sort(arrPairs.begin(), arrPairs.end(), descendOrder); // then sort the [arrPairs] as a whole by biggest value (the 'second' of each pair).
	std::deque<int> mainChain = _divideSequence(arrPairs); // create main chain and pend elements.
	if (arr.size() % 2 != 0) // add straggler if there's one
		_addElement_v1(*(arr.end() - 1), mainChain);
	return (mainChain);
}
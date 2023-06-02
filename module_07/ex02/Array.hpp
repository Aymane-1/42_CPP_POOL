/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 04:12:28 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/02 19:29:06 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array{
	private:
		T				*arr;
		unsigned int	arrSize;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &obj);
		Array			&operator=(const Array<T> &obj);
		T				&operator[](unsigned int num);
		const T			&operator[](unsigned int num) const;
		unsigned int	size(void) const;
		~Array();
};

template <typename T> Array<T>::Array(): arr(NULL), arrSize(0)
{
	std::cout << "Array default constructor called." << std::endl;
}

template <typename T> Array<T>::Array(unsigned int n) 
{
	std::cout << "Array parametrized constructor called." << std::endl;
	arr = new T[n];
	arrSize = n;
	for (unsigned int i = 0; i < n; i++)
		arr[i] = 0;
}

template <typename T> Array<T>::Array(const Array<T> &obj)
{
	if (!obj.arrSize)
	{
		arrSize = 0;
		arr = NULL;
		return ;
	}
	arrSize = obj.arrSize;
	this->arr = new T[obj.arrSize];
	
	unsigned int i = 0;
	while (this->arrSize > i && i < obj.arrSize)
	{
		this->arr[i] = obj.arr[i];
		i++;
	}
}

template <typename T> Array<T>	&Array<T>::operator=(const Array &obj)
{
	unsigned int i = 0;
    
    if (obj.arrSize == 0)
	{
		delete [] arr;
		arrSize = 0;
		arr = NULL;
		return (*this);
	}
	else
	{	
		delete[] this->arr;
		this->arr = new T[obj.arrSize];
		arrSize = obj.arrSize;
		while (i < obj.arrSize)
		{
			this->arr[i] = obj.arr[i];
			i++;
		}
		return (*this);
	}
}

template <typename T> T &Array<T>::operator[](unsigned int num) // for writing
{
	if (num >= arrSize)
		throw std::out_of_range("index is out of bound!");
	return (arr[num]);
}

template <typename T> const T &Array<T>::operator[](unsigned int num) const // for reading (const instances)
{
	if (num >= arrSize)
		throw std::out_of_range("index is out of bound!");
	return (arr[num]);
}

template <typename T> unsigned int	Array<T>::size(void) const
{
	unsigned int	length = 0;
	int				i = 0;
	while (arr[i] && i < arrSize)
		if (arr[i++])
			length++;
	return (length);
}

template <typename T> Array<T>::~Array()
{
	delete [] arr;
	std::cout << "Array destructor called." << std::endl; 
}

#endif
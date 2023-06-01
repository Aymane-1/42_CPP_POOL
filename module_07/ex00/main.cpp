/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 00:54:08 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/01 01:27:46 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"

int main( void )
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}

// int main() // my main().
// {
// 	std::cout << "------------*** swap function template ***------------\n" << std::endl;
	
// 	char charArr[2] = {'z', 'a'};
// 	int intArr[2] = {2, 1};
// 	float fltArr[2] = {2.5f, 1.5f};
// 	double dblArr[2] = {2.5, 1.5};
	
// 	swap<char>(charArr[0], charArr[1]);
// 	std::cout << "[char]: " << charArr[0] << " | " << charArr[1] << std::endl;
// 	swap<int>(intArr[0], intArr[1]);
// 	std::cout << "[int]: " << intArr[0] << " | " << intArr[1] << std::endl;
// 	swap<float>(fltArr[0], fltArr[1]);
// 	std::cout << "[float]: " << fltArr[0] << " | " << fltArr[1] << std::endl;
// 	swap<double>(dblArr[0], dblArr[1]);
// 	std::cout << "[double]: " << dblArr[0] << " | " << dblArr[1] << std::endl;
	
// 	std::cout << "\n------------*** min function template ***------------\n" << std::endl;
	
// 	std::cout << "[char]: " << min<char>('a', 'z') << std::endl;
// 	std::cout << "[int]: " << min<int>(12, 8) << std::endl;
// 	std::cout << "[float]: " << min<float>(12.1f, 3.14f) << std::endl;
// 	std::cout << "[double]: " << min<double>(12.1, 3.14) << std::endl;
	
// 	std::cout << "\n------------*** max function template ***------------\n" << std::endl;
	
// 	std::cout << "[char]: " << max<char>('a', 'z') << std::endl;
// 	std::cout << "[int]: " << max<int>(12, 8) << std::endl;
// 	std::cout << "[float]: " << max<float>(12.1f, 3.14f) << std::endl;
// 	std::cout << "[double]: " << max<double>(12.1, 3.14) << std::endl;

// 	return (0);
// }
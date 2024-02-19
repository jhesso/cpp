/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:34:53 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/19 18:05:21 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "iter.hpp"

template <typename T>
void	printArr(T * arr, size_t length)
{
	for (size_t i = 0; i < length; i++)
		std::cout << "arr[" << i << "]: " << arr[i] << std::endl;
}

template <typename T>
void	increment(T & i)
{
	i += 1;
}

void	halve(int & nb)
{
		nb /= 2;
}

void	isPos(int nb)
{
	if (nb > 0)
		std::cout << nb << ": Positive!" << std::endl;
	else
		std::cout << nb << ": Not positive!" << std::endl;
}

void	toUpper(char & c)
{
	if (isalpha(c))
		c -= 32;
}

void	print(int n)
{
	std::cout << n;
}

int	main(void)
{
	int	intArr[10] = {1, 2, 42, 42, 3, 2, 7, 8, 9, 0};

	printArr(intArr, 10);
	std::cout << std::endl << "iter(intArr, 10, increment)" << std::endl << std::endl;
	iter(intArr, (size_t)10, ::increment<int>);
	printArr(intArr, 10);

	int arr2[5] = {5, 10, 15, 20, 25};
	std::cout << std::endl;
	printArr(arr2, 5);
	iter(arr2, (size_t)5, halve);
	std::cout << std::endl;
	printArr(arr2, 5);
	std::cout << std::endl;

	int arr3[5] = {42, -42, 1, 0, -2};

	printArr(arr3, 5);
	iter(arr3, (size_t)5, isPos);

	char charArr[13] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!', 0};
	printArr(charArr, 13);
	std::cout << std::endl << "iter(charArr, 13, ::increment<char>)" << std::endl;
	iter(charArr, 13, ::increment<char>);
	std::cout << std::endl << "Result: ";
	printArr(charArr, 13);
	std::cout << std::endl;
	std::cout << "iter(charArr, 13, toUpper)" << std::endl;
	iter(charArr, (size_t)13, toUpper);
	std::cout << std::endl << "Result:" << std::endl;
	printArr(charArr, 13);

	// int const iArr[5] = {1, 2, 3, 4, 5};

	// std::cout << std::endl << std::endl;
	// iter(iArr, 5, print);
	// std::cout << std::endl;

	return 0;
}

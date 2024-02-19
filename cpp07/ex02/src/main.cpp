/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:33:42 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/19 18:39:31 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <string>
#include "Array.hpp"

# define	GREEN	"\033[0;32m"
# define	YELLOW	"\033[0;33m"
# define	BLUE	"\033[0;34m"
# define	RED		"\033[0;31m"
# define	RESET	"\033[0m"

int	main(void)
{
	Array<int> arr(500);
	int			cpy[500];

	std::cout << "filling array 'arr' with 500 random values" << std::endl;
	for (int i = 0; i < 500; i++)
	{
		int n = rand();
		arr[i] = n;
		cpy[i] = n;
	}
	for (int i = 0; i < 500; i++)
	{
		if (cpy[i] != arr[i])
		{
			std::cout << "values are different!" << std::endl;
			return 1;
		}
	}
	std::cout << std::endl << YELLOW << "---- TEST ACCESSING GOOD/BAD INDEXES ----"
				<< RESET << std::endl << std::endl;
	try
	{
		std::cout << BLUE << "testing with index: 42" << RESET << std::endl;
		std::cout << "arr[42]: [" << arr[42] << "]" << std::endl;
		std::cout << "TEST: arr[42] = 42" << std::endl;
		arr[42] = 42;
		std::cout << "arr[42]: [" << arr[42] << "]" << std::endl;
		std::cout << GREEN << "SUCCESS!" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << std::endl << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << std::endl << BLUE << "testing with index: -42" << RESET << std::endl;
		std::cout << "arr[-42]: [" << "OUT OF BOUNDS" << "]" << std::endl;
		std::cout << "TEST: arr[-42] = -42" << std::endl;
		arr[-42] = -42;
		std::cout << "arr[-42]: [" << arr[-42] << "]" << std::endl;
		std::cout << GREEN << "SUCCESS!" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << std::endl << BLUE << "testing with index 0" << RESET << std::endl;
		std::cout << "arr[0]: [" << arr[0] << "]" << std::endl;
		std::cout << "TEST: arr[0] = 0" << std::endl;
		arr[0] = 0;
		std::cout << "arr[0]: [" << arr[0] << "]" << std::endl;
		std::cout << GREEN << "SUCCESS!" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << YELLOW << "---- TEST CONSTRUCTORS ----" << RESET << std::endl << std::endl;
	try
	{
		Array<int> a(10);
		Array<int> b(5);
		Array<int> c(a);
		Array<int> d;

		for (int i = 0; i < 10; i++)
			a[i] = i;
		for (int i = 0; i < 5; i++)
			b[i] = i;
		for (unsigned int i = 0; i < c.size(); i++)
			c[i] = i;
		d = b;

		std::cout << BLUE << "TEST: default constructor (Array<int> a(10))" << RESET << std::endl;
		std::cout << "a contents:" << std::endl << a;
		std::cout << BLUE << "TEST: copy constructor (Array c(a))" << RESET << std::endl;
		std::cout << "c contents:" << std::endl << c;
		std::cout << BLUE << "TEST: copy assignment operator (d = b)" << RESET << std::endl;
		std::cout << "b contents:" << std::endl << b;
		std::cout << "d contents:" << std::endl << d;
		std::cout << std::endl << BLUE << "TEST: change values in copies" << RESET << std::endl;
		std::cout << "a[1]: " << a[1] << std::endl;
		std::cout << "c[1]: " << c[1] << std::endl;
		std::cout << "c[1] = rand()" << std::endl;
		c[1] = rand();
		std::cout << "a[1]: " << a[1] << std::endl;
		std::cout << "c[1]: " << c[1] << std::endl << std::endl;
		std::cout << "b[1]: " << b[1] << std::endl;
		std::cout << "d[1]: " << d[1] << std::endl;
		std::cout << "d[1] = rand()" << std::endl;
		d[1] = rand();
		std::cout << "b[1]: " << b[1] << std::endl;
		std::cout << "d[1]: " << d[1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW << "---- TEST CHAR ARRAY ----" << RESET << std::endl << std::endl;
	Array<char>	charArr(22);
	std::string s = "Yay I made a C string!";
	for (unsigned int i = 0; i < charArr.size(); i++)
		charArr[i] = s[i];
	for (unsigned int i = 0; i < charArr.size(); i++)
		std::cout << charArr[i];
	std::cout << std::endl << std::endl;

	std::cout << "Thanks for playing with my array :>" << std::endl;
	return 0;
}

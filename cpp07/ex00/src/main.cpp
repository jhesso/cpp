/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:18:07 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/13 13:24:45 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "whatever.hpp"

void	subjectTest(void)
{
	int	a = 2;
	int	b = 3;

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
}

int	main(void)
{
	std::cout << "---- SUBJECT TEST ----" << std::endl << std::endl;
	subjectTest();

	int	i = 42, j = 21;

	std::cout << std::endl << "---- TEST INTEGERS ----" << std::endl << std::endl;
	std::cout << "i = " << i << ", j = " << j << std::endl;
	std::cout << "min(i, j) = " << min(i, j) << std::endl;
	std::cout << "max(i, j) = " << max(i, j) << std::endl;
	std::cout << "swap(i, j)" << std::endl;
	swap(i, j);
	std::cout << "i = " << i << ", j = " << j << std::endl;

	float	f = 15, f2 = 1;

	std::cout << std::endl << "---- TEST FLOATS ----" << std::endl << std::endl;
	std::cout << "f = " << f << ", f2 = " << f2 << std::endl;
	std::cout << "swap(f, f2)" << std::endl;
	swap(f, f2);
	std::cout << "f = " << f << ", f2 = " << f2 << std::endl;
	std::cout << "min(f, f2) = " << min(f, f2) << std::endl;
	std::cout << "max(f, f2) = " << max(f, f2) << std::endl;

	char	c = 'a', c2 = '4';

	std::cout << std::endl << "---- TEST CHAR ----" << std::endl << std::endl;
	std::cout << "c = \'" << c << "\', c2 = \'" << c2 << "\'" << std::endl;
	std::cout << "min(c, c2) = \'" << min(c, c2) << "\'" << std::endl;
	std::cout << "max(c, c2) = \'" << max(c, c2) << "\'" << std::endl;
	std::cout << "swap(c, c2)" << std::endl;
	swap(c, c2);
	std::cout << "c = \'" << c << "\', c2 = \'" << c2 << "\'" << std::endl;

	return 0;
}

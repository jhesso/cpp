/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:10:03 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/28 13:06:03 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <climits>
#include <string>
#include "Fixed.hpp"

#define RESET "\e[0m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define RED "\e[31m"

enum	e_compare
{
	GREATER,
	LESS,
	GREATER_EQUAL,
	LESS_EQUAL,
	EQUAL,
	NOT_EQUAL,
	MIN,
	MAX
};

enum	e_binary
{
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE
};

enum	e_unary
{
	PRE_INCREMENT,
	PRE_DECREMENT,
	POST_INCREMENT,
	POST_DECREMENT
};

bool	colorTestCompare(Fixed & a, Fixed & b, int comparator)
{
	bool	result;
	bool	expected;

	switch ( comparator )
	{
		case GREATER:
			expected = a.getRawBits() > b.getRawBits();
			result = a > b;
			break;
		case LESS:
			expected = a.getRawBits() < b.getRawBits();
			result = a < b;
			break;
		case GREATER_EQUAL:
			expected = a.getRawBits() >= b.getRawBits();
			result = a >= b;
			break;
		case LESS_EQUAL:
			expected = a.getRawBits() <= b.getRawBits();
			result = a <= b;
			break;
		case EQUAL:
			expected = a.getRawBits() == b.getRawBits();
			result = a == b;
			break;
		case NOT_EQUAL:
			expected = a.getRawBits() != b.getRawBits();
			result = a != b;
			break;
	}
	if ( result == expected )
	{
		std::cout << GREEN << "[OK]\t";
		return (true);
	}
	else
	{
		std::cout << RED << "[KO]\t";
		return (false);
	}
}

bool	colorTestBinary( Fixed & a, Fixed & b, int operation )
{
	Fixed	result;
	float	expected = 0;

	switch (operation)
	{
		case ADD:
			result = a + b;
			expected = a.toFloat() + b.toFloat();
			break;
		case SUBTRACT:
			result = a - b;
			expected = a.toFloat() - b.toFloat();
			break;
		case MULTIPLY:
			result = a * b;
			expected = a.toFloat() * b.toFloat();
			break;
		case DIVIDE:
			result = a / b;
			expected = a.toFloat() / b.toFloat();
			break;
	}
	if ( result == expected )
	{
		std::cout << GREEN << "[OK]\t";
		return (true);
	}
	else
	{
		std::cout << RED << "[KO]\t" << "expected: " << expected
			<< ", got: " << result.getRawBits() << std::endl << "\t";
		return (false);
	}
}

bool	colorTestUnary( Fixed & a, int operation )
{
	Fixed	result;
	int		expected = 0;

	// TODO for repush: Don't use a reference to Fixed, use
	// a regular copy of fixed in this function's parameters.
	// This already increments once before returning to the test
	// which increments again (double incrementation on the test
	// result)
	switch ( operation )
	{
		case PRE_INCREMENT:
			expected = a.getRawBits() + 1;
			result = ++a;
			break ;
		case PRE_DECREMENT:
			expected = a.getRawBits() - 1;
			result = --a;
			break ;
		case POST_INCREMENT:
			expected = a.getRawBits();
			result = a++;
			break ;
		case POST_DECREMENT:
			expected = a.getRawBits();
			result = a--;
			break ;
	}
	if ( result.getRawBits() == expected )
	{
		std::cout << GREEN << "[OK]\t";
		return (true);
	}
	else
	{
		std::cout << RED << "[KO]\t" << "expected: " << expected
			<< ", got: " << result.getRawBits() << std::endl << "\t";
		return (false);
	}
}

bool	colorTestMinMax( Fixed & a, Fixed & b, int operation )
{
	Fixed expected;
	Fixed result;

	switch ( operation )
	{
		case MIN:
			expected = ( a.getRawBits() < b.getRawBits() ) ? a : b;
			result = Fixed::min(a, b);
			break ;
		case MAX:
			expected = ( a.getRawBits() > b.getRawBits() ) ? a : b;
			result = Fixed::max(a, b);
			break ;
	}
	if ( expected == result )
	{
		std::cout << GREEN << "[OK]\t";
		return (true);
	}
	else
	{
		std::cout << RED << "[KO]\t" << "expected: " << expected
			<< ", got: " << result.getRawBits() << std::endl << "\t";
		return (false);
	}
}

bool	testCompare( Fixed & a, Fixed & b )
{
	bool	res = true;
	std::cout	<< std::endl
				<< "a: " << a << std::endl
				<< "b: " << b << std::endl;
	res = colorTestCompare( a, b, GREATER );
	std::cout << "a > b\t: " << std::boolalpha << ( a > b ) << RESET << std::endl;
	if (res)
	{
		res = colorTestCompare( b, a, GREATER );
		std::cout << "b > a\t: " << std::boolalpha << ( b > a ) << RESET << std::endl;
	}
	if (res)
	{
		res = colorTestCompare( a, b, LESS );
		std::cout << "a < b\t: " << std::boolalpha << ( a < b ) << RESET << std::endl;
	}
	if (res)
	{
		res = colorTestCompare( b, a, LESS );
		std::cout << "b < a\t: " << std::boolalpha << ( b < a ) << RESET << std::endl;
	}
	if (res)
	{
		res = colorTestCompare( a, b, GREATER_EQUAL );
		std::cout << "a >= b\t: " << std::boolalpha << ( a >= b ) << RESET << std::endl;
	}
	if (res)
	{
		res = colorTestCompare( b, a, GREATER_EQUAL );
		std::cout << "b >= a\t: " << std::boolalpha << ( b >= a ) << RESET << std::endl;
	}
	if (res)
	{
		res = colorTestCompare( a, b, LESS_EQUAL );
		std::cout << "a <= b\t: " << std::boolalpha << ( a <= b ) << RESET << std::endl;
	}
	if (res)
	{
		res = colorTestCompare( b, a, LESS_EQUAL );
		std::cout << "b <= a\t: " << std::boolalpha << ( b <= a ) << RESET << std::endl;
	}
	if (res)
	{
		res = colorTestCompare( a, b, EQUAL );
		std::cout << "a == b\t: " << std::boolalpha << ( a == b ) << RESET << std::endl;
	}
	if (res)
	{
		res = colorTestCompare( b, a, EQUAL );
		std::cout << "b == a\t: " << std::boolalpha << ( b == a ) << RESET << std::endl;
	}
	if (res)
	{
		res = colorTestCompare( a, b, NOT_EQUAL );
		std::cout << "a != b\t: " << std::boolalpha << ( a != b ) << RESET << std::endl;
	}
	if (res)
	{
		res = colorTestCompare( b, a, NOT_EQUAL );
		std::cout << "b != a\t: " << std::boolalpha << ( b != a ) << RESET << std::endl;
	}
	if (res == true)
		return (true);
	return (false);
}


bool	testBinary( Fixed & a, Fixed & b )
{
	bool	res = true;

	std::cout	<< std::endl
				<< "a: " << a << std::endl
				<< "b: " << b << std::endl;
	res = colorTestBinary( a, b, ADD );
	std::cout << "a + b = " << a << " + " << b << " = " << ( a + b ) << RESET << std::endl;
	if (res)
	{
		res = colorTestBinary( a, b, SUBTRACT );
		std::cout << "a - b = " << a << " - " << b << " = " << ( a - b ) << RESET << std::endl;
	}
	if (res)
	{
		res = colorTestBinary( a, b, MULTIPLY );
		std::cout << "a * b = " << a << " * " << b << " = " << ( a * b ) << RESET << std::endl;
	}
	if (res)
	{
		res = colorTestBinary( a, b, DIVIDE );
		std::cout << "a / b = " << a << " / " << b << " = " << ( a / b ) << RESET << std::endl;
	}
	if (res == true)
		return (true);
	return (false);
}


bool	testUnary( Fixed & a )
{
	bool	res = true;

	std::cout << std::endl << "a: " << a << std::endl;
	res = colorTestUnary( a, PRE_INCREMENT );
	std::cout << "++a = " << ++a << RESET << std::endl;
	if (res)
	{
		res = colorTestUnary( a, PRE_DECREMENT );
		std::cout << "--a = " << --a << RESET << std::endl;
	}
	if (res)
	{
		res = colorTestUnary( a, POST_INCREMENT );
		std::cout << "a++ = " << a++ << " -> " << a << RESET << std::endl;
	}
	if (res)
	{
		res = colorTestUnary( a, POST_DECREMENT );
		std::cout << "a-- = " << a-- << " -> " << a << RESET << std::endl;
	}
	if (res == true)
		return (true);
	return (false);
}

bool	testMinMax( Fixed & a, Fixed & b )
{
	bool	res = true;

	std::cout	<< std::endl
				<< "a: " << a << std::endl
				<< "b: " << b << std::endl;
	res = colorTestMinMax( a, b, MIN );
	std::cout << "min( a, b ) = " << Fixed::min( a, b ) << RESET << std::endl;
	if (res)
	{
		res = colorTestMinMax( b, a, MIN );
		std::cout << "min( b, a ) = " << Fixed::min( b, a ) << RESET << std::endl;
	}
	if (res)
	{
		res = colorTestMinMax( a, b, MAX );
		std::cout << "max( a, b ) = " << Fixed::max( a, b ) << RESET << std::endl;
	}
	if (res)
	{
		res = colorTestMinMax( b, a, MAX );
		std::cout << "max( b, a ) = " << Fixed::max( b, a ) << RESET << std::endl;
	}
	if (res == true)
		return (true);
	return (false);
}

void	subjectTests(void)
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
}

void	printFail(std::string type)
{
	std::cout << RED << "[KO]\t" << type << " failed" << RESET << std::endl;
}

void	testsFailed(bool comparison, bool binary, bool unary, bool minMax)
{
	if (!comparison)
		std::cout << RED << "[KO]\tComparison tests failed" << RESET << std::endl;
	if (!binary)
		std::cout << RED << "[KO]\tBinary tests failed" << RESET << std::endl;
	if (!unary)
		std::cout << RED << "[KO]\tUnary tests failed" << RESET << std::endl;
	if (!minMax)
		std::cout << RED << "[KO]\tMin Max tests failed" << RESET << std::endl;
}

int	main( void )
{
	Fixed	a(42.42f);
	Fixed	b;
	bool	comparison = true;
	bool	binary = true;
	bool	unary = true;
	bool	minMax = true;

	std::cout	<< std::endl << YELLOW << "--- Subject tests ---"
				<< RESET << std::endl;
	subjectTests();
	std::cout	<< std::endl << GREEN << "[OK]\tSubject tests"
				<< RESET << std::endl;

	std::cout	<< std::endl << YELLOW << "--- Comparison operator tests ---"
				<< RESET << std::endl;
	comparison = testCompare(a, b);
	if (comparison == false)
		printFail("Comparison operator test");
	b = a;
	comparison = testCompare(a, b);
	if (comparison == false)
		printFail("Comparison operator test");
	std::cout	<< std::endl << GREEN << "[OK]\tComparison operator tests"
				<< RESET << std::endl;

	std::cout	<< std::endl << YELLOW << "--- Binary operator tests ---"
				<< RESET << std::endl;
	binary = testBinary(a, b);
	if (binary == false)
		printFail("Binary operator test");
	a = a + b + 0.25f;
	b = 1700;
	binary = testBinary( a, b );
	if (binary == false)
		printFail("Binary operator test");
	a = 8;
	b = -35;
	binary = testBinary( a, b );
	if (binary == false)
		printFail("Binary operator test");
	a = INT_MIN;
	b  = INT_MAX;
	binary = testBinary( a, b );
	if (binary == false)
		printFail("Binary operator test");
	std::cout	<< std::endl << GREEN << "[OK]\tBinary operator tests"
				<< RESET << std::endl;

	std::cout	<< std::endl << YELLOW << "--- Unary operator tests ---"
				<< RESET << std::endl;
	unary = testUnary( a );
	if (unary == false)
		printFail("Unary operator test");
	a = 20;
	unary = testUnary( a );
	if (unary == false)
		printFail("Unary operator test");
	std::cout	<< std::endl << GREEN << "[OK]\tUnary operator tests"
				<< RESET << std::endl;

	std::cout	<< std::endl << YELLOW << "--- Min Max function tests ---"
				<< RESET << std::endl;
	b = -42;
	minMax = testMinMax(a, b);
	if (minMax == false)
		printFail("Min Max function test");
	std::cout	<< std::endl << GREEN << "[OK]\tMin Max function tests"
				<< RESET << std::endl;

	if (comparison && binary && unary && minMax)
		std::cout	<< std::endl << GREEN << "[OK]\tAll tests passed successfully"
					<< RESET << std::endl;
	else
		testsFailed(comparison, binary, unary, minMax);

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:37:41 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/20 17:10:38 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include "RPN.hpp"

# define	GREEN	"\033[0;32m"
# define	RESET	"\033[0m"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

RPN::RPN(void) {}

RPN::RPN(RPN const & src)
{
	*this = src;
}

RPN::~RPN(void) {}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

RPN &	RPN::operator=(RPN const & src)
{
	if (this != &src)
		this->_stack = src._stack;
	return (*this);
}

/******************************************************************************/
/*							PRIVATE FUNCTIONS								  */
/******************************************************************************/

void	RPN::doOperator(std::string const & token)
{
	double	result;
	char op = token[0];

	result = _stack.top();
	_stack.pop();
	switch (op)
	{
	case '+':
		result = _stack.top() + result;
		break;
	case '-':
		result = _stack.top() - result;
		break;
	case '*':
		result = _stack.top() * result;
		break;
	case '/':
		if (result == 0)
			throw(DivisionByZero());
		result = _stack.top() / result;
		break;
	default:
		throw(InvalidInput());
	}
	_stack.pop();
	_stack.push(result);
}

void	RPN::insertSpaces(std::string & input)
{
	size_t	pos = 0;
	while ((pos = input.find_first_of("+-*/", pos)) != std::string::npos)
	{
		if (pos > 0 && input[pos - 1] != ' ')
		{
			input.insert(pos, " ");
			pos++;
		}
		if (pos + 1 != input.length() && input[pos + 1] != ' ')
			input.insert(pos + 1, " ");
		pos++;
	}
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	RPN::calculate(std::string input)
{
	insertSpaces(input);
	std::istringstream iss(input);
	std::string token;

	while (iss >> token)
	{
		if (token.length() > 1)
			throw(InvalidInput());
		if (isdigit(token[0]))
			_stack.push(stoi(token));
		else if (token.find_first_of("+-*/") != std::string::npos)
		{
			if (_stack.size() < 2)
				throw(InvalidInput());
			try
			{
				doOperator(token);
			}
			catch(const std::exception& e)
			{
				throw;
			}
		}
		else
			throw(InvalidInput());
	}
	if (_stack.size() != 1)
		throw(InvalidInput());
	std::cout << GREEN << _stack.top() << RESET << std::endl;
}

/******************************************************************************/
/*								  EXCEPTIONS								  */
/******************************************************************************/

char const *	RPN::InvalidInput::what() const throw()
{
	return "Invalid input!";
}

char const *	RPN::DivisionByZero::what() const throw()
{
	return "Division by zero";
}

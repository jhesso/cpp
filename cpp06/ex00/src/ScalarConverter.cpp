/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:59:25 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/08 19:49:54 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

#define MSG false

int const	ScalarConverter::_intMax = std::numeric_limits<int>::max();
int const	ScalarConverter::_intMin = std::numeric_limits<int>::min();
char const	ScalarConverter::_charMax = std::numeric_limits<char>::max();
char const	ScalarConverter::_charMin = std::numeric_limits<char>::min();
float const	ScalarConverter::_floatMax = std::numeric_limits<float>::max();
float const	ScalarConverter::_floatMin = std::numeric_limits<float>::min();

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

ScalarConverter::ScalarConverter(void)
	:	_type(DEFAULT), _char(0), _int(0), _float(0), _double(0), _errorFlags(OK)
{
	if (MSG)
		std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
	:	_type(src._type), _char(src._char), _int(src._int), _float(src._float),
		_double(src._double), _errorFlags(src._errorFlags)
{
	if (MSG)
		std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
	if (MSG)
		std::cout << "ScalarConverter destructor called" << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

ScalarConverter &	ScalarConverter::operator=(ScalarConverter const & src)
{
	if (MSG)
		std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	this->_char = src._char;
	this->_int = src._int;
	this->_float = src._float;
	this->_double = src._double;
	return (*this);
}

/******************************************************************************/
/*							PRIVATE FUNCTIONS								  */
/******************************************************************************/

void	ScalarConverter::_getType(std::string const & input)
{
	if (_getInt(input))
		this->_type = INTEGER;
	else if (_getFloat(input))
		this->_type = FLOAT;
	else if (_getDouble(input))
		this->_type = DOUBLE;
	else if (_getChar(input))
		this->_type = CHARACTER;
	else if (_getNonNumeric(input))
		this->_type = NON_NUM;
}

bool	ScalarConverter::_getInt(std::string const & input)
{
	char	*end;
	long	nbr;

	nbr = std::strtol(input.c_str(), &end, 10);
	if (end == input.c_str() || *end != '\0')
		return false;
	if (nbr > _intMax || nbr < _intMin)
	{
		_errorFlags += INT_OF;
		return false;
	}
	this->_int = static_cast<int>(nbr);
	return true;
}

bool	ScalarConverter::_getChar(std::string const & input)
{
	if (input.length() == 1)
	{
		this->_char = input[0];
		if (!std::isprint(input[0]))
			_errorFlags += CHAR_NONPRINT;
		return true;
	}
	return false;
}

bool	ScalarConverter::_getFloat(std::string const & input)
{
	char	*end;
	float	nbr;

	if (input[0] != '.' && !std::isdigit(input[0]))
		return false;
	nbr = std::strtof(input.c_str(), &end);
	if (end == input.c_str() || *end != 'f')
		return false;
	if (*end == 'f' && (*(end + 1) != '\0'))
		return false;
	this->_float = nbr;
	return true;
}

bool	ScalarConverter::_getDouble(std::string const & input)
{
	char	*end;
	double	nbr;
	size_t	pos;

	pos = input.find('.');
	if (pos == std::string::npos)
		return false;
	nbr = std::strtod(input.c_str(), &end);
	if (end == input.c_str() || *end != '\0')
		return false;
	this->_double = nbr;
	return true;
}

bool	ScalarConverter::_getNonNumeric(std::string const & input)
{
	if (input == "inf" || input == "+inf" || input == "inff" || input == "+inff")
	{
		_errorFlags += INT_OF;
		_errorFlags += CHAR_OF;
		_float = std::numeric_limits<float>::infinity();
		_double = std::numeric_limits<double>::infinity();
		return true;
	}
	if (input == "-inf" || input == "-inff")
	{
		_errorFlags += INT_OF;
		_errorFlags += CHAR_OF;
		_float = -1 * std::numeric_limits<float>::infinity();
		_double = -1 * std::numeric_limits<double>::infinity();
		return true;
	}
	if (input == "nan" || input == "nanf")
	{
		_errorFlags += INT_OF;
		_errorFlags += CHAR_OF;
		_float = std::numeric_limits<float>::quiet_NaN();
		_double = std::numeric_limits<double>::quiet_NaN();
		return true;
	}
	return false;
}

void	ScalarConverter::_castScalarInt(void)
{
	_setConversionErrorFlags();
	this->_char = static_cast<char>(this->_int);
	this->_float = static_cast<float>(this->_int);
	this->_double = static_cast<double>(this->_int);
	if (!std::isprint(this->_char))
		_errorFlags += CHAR_NONPRINT;
}

void	ScalarConverter::_castScalarChar(void)
{
	_setConversionErrorFlags();
	this->_int = static_cast<int>(this->_char);
	this->_float = static_cast<float>(this->_char);
	this->_double = static_cast<int>(this->_char);
}

void	ScalarConverter::_castScalarFloat(void)
{
	_setConversionErrorFlags();
	this->_int = static_cast<int>(this->_float);
	this->_char = static_cast<char>(this->_float);
	this->_double = static_cast<double>(this->_float);
	if (!std::isprint(this->_char))
		_errorFlags += CHAR_NONPRINT;
}

void	ScalarConverter::_castScalarDouble(void)
{
	_setConversionErrorFlags();
	this->_int = static_cast<int>(this->_double);
	this->_char = static_cast<char>(this->_double);
	this->_float = static_cast<float>(this->_double);
	if (!std::isprint(this->_char))
		_errorFlags += CHAR_NONPRINT;
}

void	ScalarConverter::_setConversionErrorFlags(void)
{
	switch (_type)
	{
	case INTEGER:
		if (this->_int > _charMax || this->_int < _charMin)
			this->_errorFlags += CHAR_OF;
		break;
	case FLOAT:
		if (this->_float > _charMax || this->_float < _charMin)
			this->_errorFlags += CHAR_OF;
		if (this->_float > _intMax || this->_float < _intMin)
			this->_errorFlags += INT_OF;
		break;
	case DOUBLE:
		if (this->_double > _charMax || this->_double < _charMin)
			this->_errorFlags += CHAR_OF;
		if (this->_double > _intMax || this->_double < _intMin)
			this->_errorFlags += INT_OF;
		break;
	default:
		break;
	}
}

bool	ScalarConverter::_isCharConversionOk(void) const
{
	if (this->_errorFlags & CHAR_OF || this->_errorFlags & CHAR_NONPRINT)
		return false;
	return true;
}

bool	ScalarConverter::_isIntConversionOk(void) const
{
	if (this->_errorFlags & INT_OF)
		return false;
	return true;
}

std::string	ScalarConverter::_getCharConversionMessage(void) const
{
	if (this->_errorFlags & CHAR_OF)
		return ("impossible");
	if (this->_errorFlags & CHAR_NONPRINT)
		return ("Non displayable");
	return ("unknown error");
}

std::string ScalarConverter::_getIntConversionMessage(void) const
{
	if (this->_errorFlags & INT_OF)
		return ("impossible");
	return ("unkown error");
}

void	ScalarConverter::_print(void)
{
	std::cout << "char ";
	if (this->_isCharConversionOk())
		std::cout << "\'" << this->_char << "\'";
	else
		std::cout << _getCharConversionMessage();
	std::cout << std::endl << "int: ";
	if (this->_isIntConversionOk())
		std::cout << this->_int;
	else
		std::cout << _getIntConversionMessage();
	std::cout << std::endl << "float: ";
	if (_float == static_cast<int>(_float))
		std::cout << std::fixed << std::setprecision(1) << _float << "f";
	else
		std::cout << _float << "f";
	std::cout << std::endl << "double: " << _double << std::endl;
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	ScalarConverter::convert(std::string const & input)
{
	ScalarConverter converter;

	converter._getType(input);
	switch (converter._type)
	{
	case INTEGER:
		converter._castScalarInt();
		break;
	case FLOAT:
		converter._castScalarFloat();
		break;
	case DOUBLE:
		converter._castScalarDouble();
		break;
	case CHARACTER:
		converter._castScalarChar();
		break;
	case NON_NUM:
		break;
	default:
		throw(ScalarConverter::NotLiteralException());
	}
	converter._print();
}

/******************************************************************************/
/*								  EXCEPTIONS								  */
/******************************************************************************/

const char *	ScalarConverter::NotLiteralException::what(void) const throw()
{
	return ("input given not a literal scalar type");
}

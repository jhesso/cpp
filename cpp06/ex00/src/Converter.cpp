/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:59:25 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/08 19:49:54 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Converter.hpp"

#define MSG false

int const	Converter::intMax = std::numeric_limits<int>::max();
int const	Converter::intMin = std::numeric_limits<int>::min();
char const	Converter::charMax = std::numeric_limits<char>::max();
char const	Converter::charMin = std::numeric_limits<char>::min();
float const	Converter::floatMax = std::numeric_limits<float>::max();
float const	Converter::floatMin = std::numeric_limits<float>::min();

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

Converter::Converter(void)
	:	_type(DEFAULT), _char(0), _int(0), _float(0), _double(0), _errorFlags(OK)
{
	if (MSG)
		std::cout << "Converter default constructor called" << std::endl;
}

Converter::Converter(Converter const & src)
	:	_type(src._type), _char(src._char), _int(src._int), _float(src._float),
		_double(src._double), _errorFlags(src._errorFlags)
{
	if (MSG)
		std::cout << "Converter copy constructor called" << std::endl;
}

Converter::Converter(std::string const & input)
	:	_type(DEFAULT), _char(0), _int(0), _float(0), _double(0), _errorFlags(OK)
{
	if (MSG)
		std::cout << "Converter input constructor called" << std::endl;
	this->_convertScalar(input);
}

Converter::~Converter(void)
{
	if (MSG)
		std::cout << "Converter destructor called" << std::endl;
}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

Converter &	Converter::operator=(Converter const & src)
{
	if (MSG)
		std::cout << "Converter copy assignment operator called" << std::endl;
	this->_char = src._char;
	this->_int = src._int;
	this->_float = src._float;
	this->_double = src._double;
	return (*this);
}

std::ostream &	operator<<(std::ostream & os, Converter const & converter)
{
	os << "char: ";
	if (converter.isCharConversionOk())
		os << "\'" << converter.getChar() << "\'";
	else
		os << converter.getCharConversionMessage();
	os << std::endl << "int: ";
	if (converter.isIntConversionOk())
		os << converter.getInt();
	else
		os << converter.getIntConversionMessage();
	os << std::endl << "float: ";
	if (converter.getFloat() == static_cast<int>(converter.getFloat()))
		os << std::fixed << std::setprecision(1) << converter.getFloat() << "f";
	else
		os << converter.getFloat() << "f";
	os << std::endl << "double: " << converter.getDouble();
	return os;
}

/******************************************************************************/
/*								GETTERS										  */
/******************************************************************************/

int	Converter::getInt(void) const
{
	return (this->_int);
}

char	Converter::getChar(void) const
{
	return (this->_char);
}

float	Converter::getFloat(void) const
{
	return (this->_float);
}

double	Converter::getDouble(void) const
{
	return (this->_double);
}

/******************************************************************************/
/*							PRIVATE FUNCTIONS								  */
/******************************************************************************/

void	Converter::_convertScalar(std::string const & input)
{
	_getType(input);
	switch (this->_type)
	{
	case INTEGER:
		_castScalarInt();
		break;
	case FLOAT:
		std::cout << "here" << std::endl;
		_castScalarFloat();
		break;
	case DOUBLE:
		_castScalarDouble();
		break;
	case CHARACTER:
		_castScalarChar();
		break;
	case NON_NUM:
		break;
	default:
		throw(Converter::NotLiteralException());
	}
}

void	Converter::_getType(std::string const & input)
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

bool	Converter::_getInt(std::string const & input)
{
	char	*end;
	long	nbr;

	nbr = std::strtol(input.c_str(), &end, 10);
	if (end == input.c_str() || *end != '\0')
		return false;
	if (nbr > intMax || nbr < intMin)
	{
		_errorFlags += INT_OF;
		return false;
	}
	this->_int = static_cast<int>(nbr);
	return true;
}

bool	Converter::_getChar(std::string const & input)
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

bool	Converter::_getFloat(std::string const & input)
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

bool	Converter::_getDouble(std::string const & input)
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

bool	Converter::_getNonNumeric(std::string const & input)
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

void	Converter::_castScalarInt(void)
{
	_setConversionErrorFlags();
	this->_char = static_cast<char>(this->_int);
	this->_float = static_cast<float>(this->_int);
	this->_double = static_cast<double>(this->_int);
	if (!std::isprint(this->_char))
		_errorFlags += CHAR_NONPRINT;
}

void	Converter::_castScalarChar(void)
{
	_setConversionErrorFlags();
	this->_int = static_cast<int>(this->_char);
	this->_float = static_cast<float>(this->_char);
	this->_double = static_cast<int>(this->_char);
}

void	Converter::_castScalarFloat(void)
{
	_setConversionErrorFlags();
	this->_int = static_cast<int>(this->_float);
	this->_char = static_cast<char>(this->_float);
	this->_double = static_cast<double>(this->_float);
	if (!std::isprint(this->_char))
		_errorFlags += CHAR_NONPRINT;
}

void	Converter::_castScalarDouble(void)
{
	_setConversionErrorFlags();
	this->_int = static_cast<int>(this->_double);
	this->_char = static_cast<char>(this->_double);
	this->_float = static_cast<float>(this->_double);
	if (!std::isprint(this->_char))
		_errorFlags += CHAR_NONPRINT;
}

void	Converter::_setConversionErrorFlags(void)
{
	switch (_type)
	{
	case INTEGER:
		if (this->_int > charMax || this->_int < charMin)
			this->_errorFlags += CHAR_OF;
		break;
	case FLOAT:
		if (this->_float > charMax || this->_float < charMin)
			this->_errorFlags += CHAR_OF;
		if (this->_float > intMax || this->_float < intMin)
			this->_errorFlags += INT_OF;
		break;
	case DOUBLE:
		if (this->_double > charMax || this->_double < charMin)
			this->_errorFlags += CHAR_OF;
		if (this->_double > intMax || this->_double < intMin)
			this->_errorFlags += INT_OF;
		break;
	default:
		break;
	}
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

bool	Converter::isCharConversionOk(void) const
{
	if (this->_errorFlags & CHAR_OF || this->_errorFlags & CHAR_NONPRINT)
		return false;
	return true;
}

bool	Converter::isIntConversionOk(void) const
{
	if (this->_errorFlags & INT_OF)
		return false;
	return true;
}

std::string	Converter::getCharConversionMessage(void) const
{
	if (this->_errorFlags & CHAR_OF)
		return ("impossible");
	if (this->_errorFlags & CHAR_NONPRINT)
		return ("Non displayable");
	return ("unknown error");
}

std::string Converter::getIntConversionMessage(void) const
{
	if (this->_errorFlags & INT_OF)
		return ("impossible");
	return ("unkown error");
}

/******************************************************************************/
/*								  EXCEPTIONS								  */
/******************************************************************************/

const char *	Converter::NotLiteralException::what(void) const throw()
{
	return ("input given not a literal scalar type");
}

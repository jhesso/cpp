/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:50:18 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/15 21:52:32 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "BitcoinExchange.hpp"

# define	GREEN	"\033[0;32m"
# define	YELLOW	"\033[0;33m"
# define	BLUE	"\033[0;34m"
# define	RED		"\033[0;31m"
# define	RESET	"\033[0m"

/******************************************************************************/
/*						CONSTRUCTORS & DESTRUCTORS							  */
/******************************************************************************/

BitcoinExchange::BitcoinExchange(void)
{
	loadData();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange(void) {}

/******************************************************************************/
/*								OPERATORS								  	  */
/******************************************************************************/

BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const & src)
{
	if (this != &src)
		this->_rates = src._rates;
	return (*this);
}

/******************************************************************************/
/*							PRIVATE FUNCTIONS								  */
/******************************************************************************/

void		BitcoinExchange::loadData(void)
{
	try
	{
		std::ifstream	file("data.csv");
		if (!file.is_open())
			throw (BitcoinExchange::InvalidFile());
		std::string line;
		std::getline(file, line);
		if (line.compare("date,exchange_rate") != 0)
			throw (BitcoinExchange::InvalidFile());
		while (std::getline(file, line))
		{
			time_t	date = convertTimeString(line.substr(0, line.find(",")));
			if (date == -1)
				throw (BitcoinExchange::InvalidFile());
			double	value = std::stod(line.substr(line.find(",") + 1));
			if (value == -1)
				throw (BitcoinExchange::InvalidFile());
			_rates.insert(std::pair<time_t, double>(date, value));
		}
		file.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception: " << e.what() << RESET << std::endl;
	}
}

// Convert date string to time_t and validate correctness of the conversion
time_t		BitcoinExchange::convertTimeString(std::string date)
{
	std::tm tm = {};
	std::istringstream ss(date);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	if (ss.fail())
		return -1;
	time_t time = mktime(&tm);
	std::string const tmp_date = formatDateTime(time);
	if (tmp_date.compare(date))
		return -1;
	return time;
}

// Format the date time according to the specified format (YYYY-MM-DD)
std::string	BitcoinExchange::formatDateTime(time_t date)
{
	char buf[11];
	strftime(buf, 11, "%Y-%m-%d", localtime(&date));
	return buf;
}

void		BitcoinExchange::displayValue(time_t date, double value)
{
	double	nearestVal;
	for (std::map<time_t, double>::iterator it = _rates.begin(); it != _rates.end(); it++)
	{
		if (it->first >= date)
		{
			if (it->first != date)
				it--;
			nearestVal = it->second;
			break;
		}
	}
	double result = nearestVal * value;
	if (result < 0)
		std::cerr << RED << "Error: not a positive number." << RESET << std::endl;
	else if (result > 1000)
		std::cerr << RED << "Error: too large a number." << RESET << std::endl;
	else
		std::cout << formatDateTime(date) << " => " << value << " = " << result << std::endl;
}

/******************************************************************************/
/*							PUBLIC FUNCTIONS								  */
/******************************************************************************/

void	BitcoinExchange::calculateValues(std::string filename)
{
	try
	{
		std::ifstream file(filename);
		if (!file.is_open())
			throw (BitcoinExchange::InvalidFile());
		std::string line;
		std::getline(file, line);
		if (line.compare("date | value") != 0)
			throw (BitcoinExchange::InvalidFile());
		while (std::getline(file, line))
		{
			time_t date = convertTimeString(line.substr(0, line.find(" |")));
			double value = std::stod(line.substr(line.find("|") + 1));
			if (date != -1)
				displayValue(date, value);
			else
				std::cerr << RED << "Error: bad input => " << line.substr(0, line.find(" |")) << RESET << std::endl;
		}
		file.close();
	}
	catch(const std::exception& e)
	{
		throw (BitcoinExchange::InvalidFile());
	}
}

/******************************************************************************/
/*								  EXCEPTIONS								  */
/******************************************************************************/

char const *	BitcoinExchange::InvalidFile::what() const throw()
{
	return "cannot open file";
}

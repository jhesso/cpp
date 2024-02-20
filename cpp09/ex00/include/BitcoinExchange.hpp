/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:22:14 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/20 12:52:34 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>
# include <ctime>

class BitcoinExchange
{
	private:
		BitcoinExchange(BitcoinExchange const & src);
		BitcoinExchange &	operator=(BitcoinExchange const & src);

		std::map<time_t, double> _rates;

		void		loadData(void);
		time_t		convertTimeString(std::string date);
		std::string	formatDateTime(time_t date);
		void		displayValue(time_t date, double value);
		double		convertStrToD(std::string val);

	public:
		BitcoinExchange(void);
		~BitcoinExchange(void);

	void	calculateValues(std::string filename);

	class InvalidFile : public std::exception {
		public:
			virtual const char *	what() const throw();
	};
};

#endif

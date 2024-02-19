/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:34:42 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/19 12:55:17 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <string>
# include <limits>
# include <iomanip>

class ScalarConverter
{
	private:
		enum	e_types
		{
			DEFAULT = 0,
			INTEGER,
			FLOAT,
			DOUBLE,
			CHARACTER,
			NON_NUM
		};

		enum	e_flags
		{
			OK = 0x00,
			INT_OF = 0x01,
			CHAR_OF = 0x02,
			CHAR_NONPRINT = 0x04
		};

		int		_type;
		char	_char;
		int		_int;
		float	_float;
		double	_double;
		int		_errorFlags;

		static int const	_intMax;
		static int const	_intMin;
		static char const	_charMax;
		static char const	_charMin;
		static float const	_floatMax;
		static float const	_floatMin;

		void	_getType(std::string const & input);
		bool	_getInt(std::string const & input);
		bool	_getChar(std::string const & input);
		bool	_getFloat(std::string const & input);
		bool	_getDouble(std::string const & input);
		bool	_getNonNumeric(std::string const & input);
		void	_castScalarInt(void);
		void	_castScalarChar(void);
		void	_castScalarFloat(void);
		void	_castScalarDouble(void);
		void	_setConversionErrorFlags(void);

		bool	_isCharConversionOk(void) const;
		bool	_isIntConversionOk(void) const;

		std::string	_getCharConversionMessage(void) const;
		std::string _getIntConversionMessage(void) const;

		void	_print(void);

		ScalarConverter(void);
		ScalarConverter(ScalarConverter const & src);
		~ScalarConverter(void);

		ScalarConverter &	operator=(ScalarConverter const & src);

	public:

		static void	convert(std::string const & input);

		class	NotLiteralException : public std::exception
		{
			public:
				virtual const char *	what(void) const throw();
		};
};

#endif

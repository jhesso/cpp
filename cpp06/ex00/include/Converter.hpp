/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:34:42 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/08 18:57:41 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <string>
# include <limits>
# include <iomanip>

class Converter
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

		void	_convertScalar(std::string const & input);
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

	public:
		Converter(void);
		Converter(Converter const & src);
		Converter(std::string const & input);
		~Converter(void);

		Converter &	operator=(Converter const & src);

		int		getInt(void) const;
		char	getChar(void) const;
		float	getFloat(void) const;
		double	getDouble(void) const;

		bool	isCharConversionOk(void) const;
		bool	isIntConversionOk(void) const;

		std::string	getCharConversionMessage(void) const;
		std::string getIntConversionMessage(void) const;

		static int const	intMax;
		static int const	intMin;
		static char const	charMax;
		static char const	charMin;
		static float const	floatMax;
		static float const	floatMin;

		class	NotLiteralException : public std::exception
		{
			public:
				virtual const char *	what(void) const throw();
		};
};

std::ostream &	operator<<(std::ostream & os, Converter const & converter);

#endif

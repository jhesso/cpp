/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:02:18 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/28 13:05:33 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int			_raw;
		static int const	_fractionalBits = 8;

	public:
		Fixed( void );
		Fixed( Fixed const & src);
		Fixed(int const raw);
		Fixed(float const raw);
		~Fixed( void );

		Fixed &	operator=( Fixed const & src);
		bool	operator>(Fixed const & src) const;
		bool	operator<(Fixed const & src) const;
		bool	operator>=(Fixed const & src) const;
		bool	operator<=(Fixed const & src) const;
		bool	operator==(Fixed const & src) const;
		bool	operator!=(Fixed const & src) const;

		Fixed	operator+(Fixed const & src) const;
		Fixed	operator-(Fixed const & src) const;
		Fixed	operator*(Fixed const & src) const;
		Fixed	operator/(Fixed const & src) const;
		Fixed &	operator++(void);
		Fixed &	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed &			min(Fixed & lhs, Fixed & rhs);
		static Fixed &			max(Fixed & lhs, Fixed & rhs);
		static Fixed const &	min(Fixed const & lhs, Fixed const & rhs);
		static Fixed const &	max(Fixed const & lhs, Fixed const & rhs);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed & number);

#endif

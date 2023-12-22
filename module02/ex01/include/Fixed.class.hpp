/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:02:18 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/22 15:17:54 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

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
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed & number);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:02:18 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/28 13:02:26 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int			_raw;
		static int const	_fractionalBits = 8;

	public:
		Fixed( void );
		Fixed( Fixed const & src);
		~Fixed( void );

		Fixed &	operator=( Fixed const & src);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif

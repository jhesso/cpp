/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:19:36 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/13 12:27:08 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T & a, T & b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T const & min(T const & a, T const & b)
{
	return (a < b ? a : b);
}

template <typename T>
T const & max(T const & a, T const & b)
{
	return (a > b ? a : b);
}

#endif

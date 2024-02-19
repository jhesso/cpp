/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:35:39 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/19 17:42:43 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstdlib>

template <typename T, typename F>
void	iter(T * arr, size_t length, F func)
{
	for (size_t i = 0; i < length; i++)
		func(arr[i]);
}

template <typename T, typename F>
void	iter(const T * arr, size_t length, F const func)
{
	for (size_t i = 0; i < length; i++)
		func(arr[i]);
}

#endif

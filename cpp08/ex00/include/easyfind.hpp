/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:41:19 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/14 23:47:59 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iterator>
# include <stdexcept>
# include <algorithm>

template <typename T>
typename T::const_iterator	easyfind(T const & container, int const elem)
{
	typename T::const_iterator i;
	i = std::find(container.begin(), container.end(), elem);
	if (i == container.end())
		throw ( std::out_of_range("Element not found in container"));
	return i;
}

#endif

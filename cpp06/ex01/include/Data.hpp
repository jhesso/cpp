/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:53:34 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/08 20:23:45 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>
# include <cstdint>

struct	Data
{
	unsigned int	val;
	std::string		string;
};

class	Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const & src);
		~Serializer(void);

		Serializer &	operator=(const Serializer & src);

	public:
		static uintptr_t	serialize(Data * ptr);
		static Data *	deserialize(uintptr_t raw);
};

std::ostream &	operator<<(std::ostream & os, const Data & obj);

#endif

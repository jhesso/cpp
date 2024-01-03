/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:27:51 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/30 15:18:53 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <string>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const & src);
		WrongAnimal(std::string const & type);
		virtual ~WrongAnimal(void);

		WrongAnimal &	operator=(WrongAnimal const & src);

		std::string const &	getType(void) const;
		void		makeSound(void) const;
};

#endif

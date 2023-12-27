/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:18:13 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 18:25:15 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	protected:
		std::string	_type;

	public:
		Animal(void);
		Animal(std::string const & type);
		Animal(Animal const & src);
		virtual ~Animal(void);

		Animal &			operator=(Animal const & src);

		virtual void		makeSound(void) const;
		std::string const &	getType(void) const;
};

#endif

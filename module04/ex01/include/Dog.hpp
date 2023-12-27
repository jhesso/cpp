/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:19:49 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 19:33:09 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain *	_brain;

	public:
		Dog(void);
		Dog(Dog const & src);
		~Dog(void);

		Dog &	operator=(Dog const & src);

		void	makeSound(void) const;
		Brain *	getBrain(void) const;
};

#endif

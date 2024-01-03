/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:30:46 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/27 19:34:06 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"
# include "Brain.hpp"

class WrongCat: public WrongAnimal
{
	private:
		Brain *	_brain;

	public:
		WrongCat(void);
		WrongCat(WrongCat const & src);
		~WrongCat(void);

		WrongCat &		operator=(WrongCat const & src);

		void	makeSound(void) const;
		Brain *	getBrain(void) const;
};

#endif

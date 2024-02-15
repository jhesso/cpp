/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:05:02 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/15 19:36:55 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		MutantStack<T>(void) : std::stack<T>() {};
		MutantStack<T>(MutantStack const & src) : std::stack<T>(src) {};
		~MutantStack<T>(void) {};

		MutantStack &	operator=(MutantStack const & src)
		{
			if (this != &src)
				this->c = src.c;
			return *this;
		}

		MutantStack<T>::iterator	begin(void)
		{
			return this->c.begin();
		}

		MutantStack<T>::iterator	end(void)
		{
			return this->c.end();
		}

		MutantStack<T>::const_iterator	begin(void) const
		{
			return this->c.begin();
		}

		MutantStack<T>::const_iterator	end(void) const
		{
			return this->c.end();
		}
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:34:04 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/19 18:49:12 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T *				_array;
		unsigned int	_size;

	public:
		Array(void) : _array(NULL), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		Array(Array const & src) : _array(new T[src._size]), _size(src._size)
		{
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = src._array[i];
		}
		~Array(void) { delete [] _array; }

		Array &	operator=(Array const & src)
		{
			if (this == &src)
				return *this;
			if (this->_size != src._size)
			{
				delete [] _array;
				this->_size = src._size;
				this->_array = new T[this->_size];
			}
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = src._array[i];
			return *this;
		}

		class OutOfBoundsException : public std::exception {
			public:
				virtual char const *	what(void) const throw() {
					return ("Index out of bounds.");
				}
		};

		T &	operator[](unsigned int index) const
		{
			if (index >= this->_size)
				throw (OutOfBoundsException());
			return this->_array[index];
		}

		unsigned int	size(void) const
		{
			return this->_size;
		}
};

template <typename T>
std::ostream &	operator<<(std::ostream & os, Array<T> & obj)
{
	for (unsigned int i = 0; i < obj.size(); i++)
		os << "[" << obj[i] << "]\n";
	return os;
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:05:22 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/15 18:04:59 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>

class Span
{
	private:
		std::vector<int> _range;
		unsigned int _maxSize;

	public:
		Span(void);
		Span(Span const & src);
		Span(unsigned int N);
		~Span(void);

		Span &	operator=(Span const & src);

		std::vector<int> const &	getRange(void) const;

		void	addNumber(int num);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		template <typename T>
		void	addNumberRange(typename T::iterator & begin, typename T::iterator & end)
		{
			unsigned int	dist = std::distance(begin, end);

			if (dist > (this->_maxSize - this->_range.size()))
				throw (Span::FullRangeException());
			else if (dist != 0)
				this->_range.insert(this->_range.end(), begin, end);
		}

		class FullRangeException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};

		class RangeTooSmallException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};
};

#endif

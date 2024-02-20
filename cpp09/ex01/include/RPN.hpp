/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:37:22 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/20 17:09:51 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>

class RPN
{
	private:
		RPN(RPN const & src);
		RPN &	operator=(RPN const & src);

		std::stack<double>	_stack;

		void	doOperator(std::string const & operand);
		void	insertSpaces(std::string & input);

	public:
		RPN(void);
		~RPN(void);

		void	calculate(std::string input);

		class InvalidInput : public std::exception {
			public:
				virtual const char *	what() const throw();
		};

		class DivisionByZero : public std::exception {
			public:
				virtual const char *	what() const throw();
		};
};

#endif

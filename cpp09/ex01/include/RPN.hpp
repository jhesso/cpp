/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:37:22 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/16 12:37:28 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP


class RPN
{
	private:


	public:
		RPN(void);
		RPN(RPN const & src);
		~RPN(void);

		RPN &	operator=(RPN const & src);
};

#endif

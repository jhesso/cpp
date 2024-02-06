/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:34:49 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/06 15:13:29 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "bureaucrat.hpp"

int	main(void)
{
	Bureaucrat b;

	b.setName("test");
	b.setGrade(50);

	std::cout << "Testing << operator overload" << std::endl;
	std::cout << b;
	b.setName("Jhesso");
	std::cout << b;
	Bureaucrat b2("asdf", 42);
	std::cout << b2;
	return 0;
}

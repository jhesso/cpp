/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:29:29 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/08 20:49:06 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *	generate(void)
{
	int	nb = std::rand() % 3;
	switch (nb)
	{
	case 0:
		std::cout << "Generated A";
		return new A;
	case 1:
		std::cout << "Generated B";
		return new B;
	case 2:
		std::cout << "Generated C";
		return new C;
	}
	return NULL;
}

void	identify(Base * base)
{
	std::cout << "Identified as pointer: ";
	if (dynamic_cast<A *>(base))
		std::cout << "A";
	else if (dynamic_cast<B *>(base))
		std::cout << "B";
	else if (dynamic_cast<C *>(base))
		std::cout << "C";
	else
		std::cout << "Unknown";
}

void	identify(Base & base)
{
	std::cout << "Identified as reference: ";
	try
	{
		(void)dynamic_cast<A &>(base);
		std::cout << "A";
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<B &>(base);
		std::cout << "B";
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<C &>(base);
		std::cout << "C";
	}
	catch(const std::exception& e){}
}

int	main(void)
{
	Base *	base;

	for (int i = 0; i < 10; i++)
	{
		std::cout << "Test: " << i << std::endl;
		base = generate();
		std::cout << std::endl;
		identify(base);
		std::cout << std::endl;
		identify(*base);
		std::cout << std::endl;
		delete base;
		std::cout << std::endl;
	}
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:29:29 by jhesso            #+#    #+#             */
/*   Updated: 2024/02/19 15:38:51 by jhesso           ###   ########.fr       */
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

void	identify(Base * p)
{
	std::cout << "Identified as pointer: ";
	if (dynamic_cast<A *>(p) != nullptr)
		std::cout << "A";
	else if (dynamic_cast<B *>(p) != nullptr)
		std::cout << "B";
	else if (dynamic_cast<C *>(p) != nullptr)
		std::cout << "C";
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base & p)
{
	std::cout << "Identified as reference: ";
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A";
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B";
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<C &>(p);
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
	std::cout << "testing with NULL" << std::endl;
	identify(NULL);
	return 0;
}

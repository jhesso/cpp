/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:18:00 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/30 15:15:54 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal*		meta = new Animal();
	const Animal*		dog = new Dog();
	const Animal*		cat = new Cat();
	const WrongAnimal*	wrongMeta = new WrongAnimal();
	const WrongAnimal*	wrongCat = new WrongCat();

	std::cout << std::endl << "type of dog: " << dog->getType() << " " << std::endl;
	std::cout << "type of cat: " << cat->getType() << " " << std::endl;
	std::cout << "type of meta: " << meta->getType() << " " << std::endl;
	std::cout << std::endl << std::endl << "let's make some sound" << std::endl;
	cat->makeSound();
	dog->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	std::cout << "type of wrongCat: " << wrongCat->getType() << " " << std::endl;
	std::cout << "type of wrongMeta: " << wrongMeta->getType() << " " << std::endl;
	std::cout << std::endl << std::endl << "let's make some sound" << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();

	std::cout << std::endl << std::endl << "let's test the wrong cat as a wrong cat now.." << std::endl;
	const WrongCat*	wrongCat2 = new WrongCat();
	std::cout << "type of wrongCat2: " << wrongCat2->getType() << " " << std::endl;
	std::cout << std::endl << std::endl << "let's make some sound" << std::endl;
	wrongCat2->makeSound();
	std::cout << std::endl;

	delete meta;
	delete dog;
	delete cat;
	delete wrongMeta;
	delete wrongCat;

	return (0);
}

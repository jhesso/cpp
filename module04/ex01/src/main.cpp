/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhesso <jhesso@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:18:00 by jhesso            #+#    #+#             */
/*   Updated: 2023/12/30 19:57:36 by jhesso           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define NB_ANIMALS 4

void	arrayTest(void)
{
	std::cout	<< "--- ANIMAL ARRAY TEST ---" << std::endl << std::endl;

	Animal *	animalArray[NB_ANIMALS + 1];
	animalArray[NB_ANIMALS] = NULL;

	std::cout	<< "Creating an array of animals consisting of:" << std::endl
				<< NB_ANIMALS / 2 << " cats" << std::endl
				<< NB_ANIMALS / 2 << " dogs" << std::endl;
	for (int i = 0; i < NB_ANIMALS / 2; i++)
		animalArray[i] = new Cat();
	std::cout << std::endl;
	for (int i = NB_ANIMALS / 2; i < NB_ANIMALS; i++)
		animalArray[i] = new Dog();
	std::cout << std::endl << "The animals make some sound" << std::endl;
	for (int i = 0; i < NB_ANIMALS; i++)
		animalArray[i]->makeSound();
	std::cout << std::endl << "Destroying the array" << std::endl;
	for (int i = 0; animalArray[i]; i++)
		delete animalArray[i];
	std::cout << std::endl;
}

void	catBrainTest(void)
{
	std::cout << "--- CAT BRAIN TEST ---" << std::endl << std::endl;

	std::cout << "Creating a cat" << std::endl;
	Cat *	cat = new Cat();

	std::cout << "Putting ideas in it's head" << std::endl;
	cat->getBrain()->setIdea(0, "I am the ruler of this kindom");
	cat->getBrain()->setIdea(1, "These so called humans are my loyal servants");
	cat->getBrain()->setIdea(2, "I'm hungry");

	std::cout << "Cat idea 0: " << cat->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat idea 1: " << cat->getBrain()->getIdea(1) << std::endl;
	std::cout << "Cat idea 2: " << cat->getBrain()->getIdea(2) << std::endl;

	std::cout << std::endl << "Creating a copy of our cat" << std::endl;
	Cat *	copyCat = new Cat(*cat);

	std::cout << std::endl << "copyCat should have the same thoughts in it's brain" << std::endl;
	std::cout << "copyCat idea 0: " << copyCat->getBrain()->getIdea(0) << std::endl;
	std::cout << "copyCat idea 1: " << copyCat->getBrain()->getIdea(1) << std::endl;
	std::cout << "copyCat idea 2: " << copyCat->getBrain()->getIdea(2) << std::endl;

	std::cout << std::endl << "lets put some new ideas to our original cats brain" << std::endl;
	cat->getBrain()->setIdea(0, "I want to go outside and hunt");
	cat->getBrain()->setIdea(1, "I am a master hunter");
	cat->getBrain()->setIdea(2, "damn, im still hungry");

	std::cout << "Cat idea 0: " << cat->getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat idea 1: " << cat->getBrain()->getIdea(1) << std::endl;
	std::cout << "Cat idea 2: " << cat->getBrain()->getIdea(2) << std::endl;

	std::cout << std::endl << "copyCat's brain should not have been altered" << std::endl;
	std::cout << "copyCat idea 0: " << copyCat->getBrain()->getIdea(0) << std::endl;
	std::cout << "copyCat idea 1: " << copyCat->getBrain()->getIdea(1) << std::endl;
	std::cout << "copyCat idea 2: " << copyCat->getBrain()->getIdea(2) << std::endl;

	std::cout << std::endl << "lets try if my operator overload works as well" << std::endl;
	*copyCat = *cat;

	std::cout << std::endl << "copyCats ideas should now equal to the other cats" << std::endl;
	std::cout << "copyCat idea 0: " << copyCat->getBrain()->getIdea(0) << std::endl;
	std::cout << "copyCat idea 1: " << copyCat->getBrain()->getIdea(1) << std::endl;
	std::cout << "copyCat idea 2: " << copyCat->getBrain()->getIdea(2) << std::endl;

	std::cout << std::endl << "Destroying cat and copyCat" << std::endl;
	delete cat;
	delete copyCat;
	std::cout << std::endl;
}

void	dogBrainTest(void)
{
	std::cout << "--- DOG BRAIN TEST ---" << std::endl << std::endl;

	std::cout << "Creating a dog" << std::endl;
	Dog *	dog = new Dog();

	std::cout << "Putting ideas in it's head" << std::endl;
	dog->getBrain()->setIdea(0, "I'm extremely happy that my owner loves me so much");
	dog->getBrain()->setIdea(1, "My owner is my best friend");
	dog->getBrain()->setIdea(2, "I really could go for a steak right now");

	std::cout << "Dog idea 0: " << dog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog idea 1: " << dog->getBrain()->getIdea(1) << std::endl;
	std::cout << "Dog idea 2: " << dog->getBrain()->getIdea(2) << std::endl;

	std::cout << std::endl << "Creating a copy of our dog" << std::endl;
	Dog *	copyDog = new Dog(*dog);

	std::cout << std::endl << "copyDog should have the same thoughts in it's brain" << std::endl;
	std::cout << "copyDog idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "copyDog idea 1: " << copyDog->getBrain()->getIdea(1) << std::endl;
	std::cout << "copyDog idea 2: " << copyDog->getBrain()->getIdea(2) << std::endl;

	std::cout << std::endl << "lets put some new ideas to our original dogs brain" << std::endl;
	dog->getBrain()->setIdea(0, "I want to go outside and play");
	dog->getBrain()->setIdea(1, "Fetch is one of my favorite games");
	dog->getBrain()->setIdea(2, "Chicken would be nice too");

	std::cout << "Dog idea 0: " << dog->getBrain()->getIdea(0) << std::endl;
	std::cout << "Dog idea 1: " << dog->getBrain()->getIdea(1) << std::endl;
	std::cout << "Dog idea 2: " << dog->getBrain()->getIdea(2) << std::endl;

	std::cout << std::endl << "copyDog's brain should not have been altered" << std::endl;
	std::cout << "copyDog idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "copyDog idea 1: " << copyDog->getBrain()->getIdea(1) << std::endl;
	std::cout << "copyDog idea 2: " << copyDog->getBrain()->getIdea(2) << std::endl;

	std::cout << std::endl << "lets try if my operator overload works as well" << std::endl;
	*copyDog = *dog;

	std::cout << std::endl << "copyDogs ideas should now equal to the other dogs" << std::endl;
	std::cout << "copyDog idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "copyDog idea 1: " << copyDog->getBrain()->getIdea(1) << std::endl;
	std::cout << "copyDog idea 2: " << copyDog->getBrain()->getIdea(2) << std::endl;

	std::cout << std::endl << "Destroying dog and copyDog" << std::endl;
	delete dog;
	delete copyDog;
	std::cout << std::endl;
}

void	shitsAndGiggles(void)
{
	std::cout << "Creating a new dog and cat" << std::endl;
	Dog *	dog = new Dog();
	Cat *	cat = new Cat();
	std::string	catThought = "Meow!";
	std::string	dogThought = "Woof!";

	std::cout << std::endl << "Filling their heads with ideas" << std::endl;
	for (int i = 0; i < dog->getBrain()->nbIdeas; i++)
		dog->getBrain()->setIdea(i, dogThought);
	for (int i = 0; i < cat->getBrain()->nbIdeas; i++)
		cat->getBrain()->setIdea(i, catThought);
	dog->getBrain()->setIdea(0, "Meow!");
	dog->getBrain()->setIdea(1, "No that sounds wrong...");

	std::cout << std::endl << "Let's see what they think..." << std::endl;
	for (int i = 0; i < dog->getBrain()->nbIdeas; i++)
		std::cout << "Dog idea " << i << ": " << dog->getBrain()->getIdea(i) << std::endl;
	for (int i = 0; i < cat->getBrain()->nbIdeas; i++)
		std::cout << "Cat idea " << i << ": " << cat->getBrain()->getIdea(i) << std::endl;

	std::cout << std::endl << "Alright I think thats enough :)" << std::endl;
	delete dog;
	delete cat;
	std::cout << std::endl;
}

int	main(void)
{
	arrayTest();
	catBrainTest();
	dogBrainTest();
	shitsAndGiggles();

	std::cout << "Testing for deep/shallow copy" << std::endl << std::endl;
	Dog basic;
	{
		Dog tmp = basic; // should create a new brain as this is a deep copy
	}
	std::cout << std::endl << std::endl;

	// uncomment to check for memory leaks
	// system("leaks animal");

	return (0);
}

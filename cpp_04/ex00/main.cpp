#include "Cat.hpp"
#include "Dog.hpp"

int	main(){

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

/* 	delete meta;
	delete j;
	delete i; */

	std::cout << "------------------" << std::endl;

	Cat chat1("Cat");
	chat1.makeSound();

	Dog dog1("Dog");
	dog1.makeSound();

	Cat chat3 = chat1;
	Cat chat2 = chat1;

	Cat chat4("Cat2");
	chat4.makeSound();

	Dog dog2 = dog1;
	dog2.makeSound();

	//chat2.makeSound();	



}
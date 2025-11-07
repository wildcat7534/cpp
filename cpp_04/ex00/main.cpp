#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(){

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

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

	std::cout << "------------WRONG------" << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();

	delete wrongMeta;
	delete wrongCat;
	delete meta;
	delete j;
	delete i;



}
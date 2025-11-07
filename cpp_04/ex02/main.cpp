#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(){

	//const Animal* meta = new Animal(); -> devenu class abstract avec la const initialisée à 0
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	//meta->makeSound();

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
	//delete meta;
	delete j;
	delete i;

	std::cout << "------------BRAIN DEEP COPY TEST------" << std::endl;
/*
Dans votre fonction main, créez et remplissez un tableau d’objets Animal dont
la moitié est composée d’objets Dog et l’autre moitié d’objets Cat.
À la fin de l’exécution du programme, parcourez ce tableau afin de delete chaque Animal. Vous devez delete directement les chiens
et les chats en tant
qu’Animal. Les destructeurs correspondants doivent être appelés dans le bon ordre.
*/

	const int	size = 6;
	Animal*	animals[size];
	for (int i = 0; i < size / 2; i++)
		animals[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		animals[i] = new Cat();
	for (int i = 0; i < size; i++)
		animals[i]->makeSound();
	for (int i = 0; i < size; i++)
		delete animals[i];

	

	return 0;

}
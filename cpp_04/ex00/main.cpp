#include "Cat.hpp"
#include "Dog.hpp"

int	main(){

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
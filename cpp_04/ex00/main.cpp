#include "Cat.hpp"

int	main(){

	Cat chat1("Isabelle");
	chat1.makeSound();

	Cat chat2(chat1);

	Cat chat3 = chat1;
	//Cat chat2 = chat1;

	//chat2.makeSound();	



}
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define B_GN "\033[38;5;46m"
#define B_RD "\033[38;5;203m"
#define B_GR "\033[38;5;249m"
#define B_OR "\033[1;38;5;208m"
#define B_MG "\033[38;5;201m"

#define RESET "\033[0m"

int	main(){
	{

		std::cout << std::endl << B_GN << "-----------TESTS exemple sujet-------" << std::endl << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		std::cout << std::endl << RESET << "------------TESTS perso normals------" << std::endl << std::endl;	

		Cat chat1("Cat");
		chat1.makeSound();
		
		Dog dog1("Dog");
		dog1.makeSound();
		std::cout << std::endl << "---------copy assignation chat2 = chat1 et dog2 = dog1---------" << std::endl << std::endl;

		Cat chat2 = chat1;
		Dog dog2 = dog1;

		std::cout << std::endl << "makesound() after copy assignation" << std::endl << std::endl;
		chat2.makeSound();
		dog2.makeSound();

		std::cout << std::endl << B_RD << "------------TESTS exemple exercice mais : WRONG (heritage mal fait)------" << std::endl << std::endl;
		const WrongAnimal* wrongMeta = new WrongAnimal();
		const WrongAnimal* wrongCat = new WrongCat();
		
		std::cout << wrongCat->getType() << " " << std::endl;
		std::cout << wrongMeta->getType() << " " << std::endl;
		wrongCat->makeSound(); //will output the cat sound!
		wrongMeta->makeSound();
		std::cout << std::endl << RESET << "------------------" << std::endl << std::endl;

		std::cout << std::endl << B_GR << "------------DESTRUCTORS (new)------" << std::endl << std::endl;
		delete wrongMeta;
		delete wrongCat;
		delete meta;
		delete j;
		delete i;

		std::cout << std::endl << "------------END scope--(appel auto des destructeurs)----" << std::endl << std::endl;
	}
	{
		std::cout << RESET << "------------------" << std::endl;

		const int	size = 6;
		Animal*	animals[size];
		std::cout << "---------dogs crea X3--------" << std::endl << std::endl;
		for (int i = 0; i < size / 2; i++)
		{
			std::cout << B_MG <<" [create dog index " << i << "]" << RESET << std::endl;
			animals[i] = new Dog();
		}
		std::cout << RESET << std::endl;

		std::cout << "---------cats crea X3--------" << std::endl << std::endl;
		for (int i = size / 2; i < size; i++)
		{
			std::cout << B_MG <<" [create cat index " << i << "]" << RESET << std::endl;
			animals[i] = new Cat();
		}
		std::cout << RESET << std::endl;

		std::cout << "---------makeSound all animals--------" << std::endl << std::endl;
		for (int i = 0; i < size; i++)
			animals[i]->makeSound();
		
		std::cout << std::endl << "---------delete all animals--------" << std::endl << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cout << B_GR <<"call delete for animal index " << i << std::endl;
			delete animals[i];
		}
		std::cout << RESET << std::endl;	

		std::cout << "---------END----------------------" << std::endl << std::endl;
		
		std::cout << std::endl;
		std::cout << std::endl << B_OR << "----------------------------- Real Deep Copy constructors ----------------------------" << std::endl << std::endl;
		
		std::cout << B_MG << "Creating first Cat and Dog objects" << RESET << std::endl;
		Cat catFirst("Caty");
		Dog dogFirst("Dogy");
		std::cout << B_MG << " >> Creating First Cat and Dog AND thoughts at index 42:" << RESET << std::endl;
		catFirst.setThought(42, "I am a cat and I am thinking about fish.");
		dogFirst.setThought(42, "I am a dog and I am thinking about bones.");
		std::cout <<  "Animal : " << catFirst.getType() << " ";
		catFirst.showThought(42);
		std::cout <<  "Animal : " << dogFirst.getType() << " ";
		dogFirst.showThought(42);
		std::cout << std::endl << B_MG << "Creating second Cat and Dog objects by copy constructors" << RESET << std::endl;
		Cat catSecond;
		Dog	dogSecond;
		{
			std::cout << std::endl << B_OR << "----------------------------- Real Deep Copy  ----------------------------" << std::endl << std::endl;
			catSecond = catFirst;
			dogSecond = dogFirst;
			std::cout <<  "Animal : " << catSecond.getType() << " ";
			catSecond.showThought(42);
			std::cout <<  "Animal : " << dogSecond.getType() << " ";
			dogSecond.showThought(42);
		}
		std::cout << std::endl << B_OR << "----------------------------- After scope {} ----------------------------" << std::endl << std::endl;
		std::cout << B_MG << "Second Cat and Dog thoughts at index 42 (after scope):" << RESET << std::endl;
		std::cout <<  "Animal : " << catSecond.getType() << " ";
		catSecond.showThought(42);
		std::cout <<  "Animal : " << dogSecond.getType() << " ";
		dogSecond.showThought(42);

		std::cout << std::endl << "-------test just Animal showThought (no brain) -------" << std::endl << std::endl;
		Animal animal;
		animal.showThought(10);

		std::cout << std::endl;
		std::cout << std::endl << "---------------------------------- End ----------------------------------" << RESET << std::endl << std::endl;
		
		std::cout << "---------END----------------------" << std::endl << std::endl;
	}
	return 0;
}
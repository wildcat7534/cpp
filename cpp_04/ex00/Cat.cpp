#include "Cat.hpp"

Cat::Cat(){}

Cat::Cat(std::string type): Animal(type){}

Cat& Cat::operator=(const Cat& other) {}

Cat::~Cat(){}

void	Cat::makeSound(){
	std::cout << "Type : "<< _type << "Miaouuuuu" << std::endl;
}


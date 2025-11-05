#include "Cat.hpp"

Cat::Cat(): Animal("Cat"){}

Cat::Cat(std::string type): Animal(type){}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other)
		this->_type = other._type;
	return *this;
}

Cat::~Cat(){}

void	Cat::makeSound(){
	std::cout << "Type : ["<< _type << "] > Miaouuuuu" << std::endl;
}

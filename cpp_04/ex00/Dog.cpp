#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {}

Dog::Dog(std::string type): Animal(type) {}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other)
		this->_type = other._type;
	return *this;
}

Dog::~Dog(){}

void	Dog::makeSound(){
	std::cout << "Type : ["<< _type << "] > Wouuuuuff" << std::endl;
}

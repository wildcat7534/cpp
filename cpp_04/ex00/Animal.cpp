#include "Animal.hpp"

Animal::Animal(){}

Animal::Animal(std::string type): _type(type) {}

Animal::Animal(Animal& other){
	if (this != &other)
		this->_type = other._type;
	//return *this;
}

Animal::~Animal(){}

Animal& Animal::operator=(const Animal& other){
		if (this != &other)
			this->_type = other._type;
		return *this;
}

void Animal::getType(){
	std::cout << "Type : " << this->_type << std::endl;
}

void printThis(){
	std::cout << "This : " << this << std::endl;
}

void Animal::makeSound(){
	std::cout << "Animals make sound" << std::endl;
}
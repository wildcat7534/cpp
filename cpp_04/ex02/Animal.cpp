#include "Animal.hpp"

Animal::Animal(){
	this->_type = "Animal";
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(std::string type): _type(type) {
	std::cout << "Animal Parametrized Constructor called" << std::endl;
}

Animal::Animal(const Animal& other){
	std::cout << "Animal Copy Constructor called" << std::endl;
	if (this != &other)
		this->_type = other._type;
}

Animal::~Animal(){
	std::cout << "Animal Destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& other){
	std::cout << "Animal Assignment Operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

std::string Animal::getType() const {
	return this->_type;
}

void Animal::makeSound() const {
	std::cout << "Animals make sound" << std::endl;
}
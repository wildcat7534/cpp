#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	this->_type = "WrongAnimal";
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): _type(type) {
	std::cout << "WrongAnimal Parametrized Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	if (this != &other)
		this->_type = other._type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
	std::cout << "WrongAnimal Assignment Operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

std::string WrongAnimal::getType() const {
	return this->_type;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimals make sound" << std::endl;
}
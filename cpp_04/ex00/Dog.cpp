#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	std::cout << "Dog Default Constructor called" <<  std::endl;
}

Dog::Dog(std::string type): Animal(type) {
	std::cout << "Dog Parametrized Constructor called" <<  std::endl;
}

Dog::Dog(const Dog& other): Animal(other) {
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog Assignment Operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog Destructor called" << std::endl;
}

void	Dog::makeSound() const{
	std::cout << "Type : ["<< _type << "] > Wouuuuuff" << std::endl;
}

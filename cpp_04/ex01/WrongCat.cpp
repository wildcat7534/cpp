#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat"){
	std::cout << "WrongCat Default Constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type): WrongAnimal(type){
	std::cout << "WrongCat Parametrized Constructor called" << std::endl;
}
WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other) {
	std::cout << "WrongCat Copy Constructor called" << std::endl;
}
WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat Assignment Operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}
WrongCat::~WrongCat(){
	std::cout << "WrongCat Destructor called" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "Type : ["<< _type << "] > Miaouuuuu" << std::endl;
}

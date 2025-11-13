#include "Cat.hpp"

Cat::Cat(): Animal("Cat"){
	std::cout << "Cat Default Constructor called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(std::string type): Animal(type){
	std::cout << "Cat Parametrized Constructor called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat& other): Animal(other) {
	std::cout << "Cat Copy Constructor called" << std::endl;
	_type = other._type + " (copied)";
	_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat Assignment Operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type + " (assigned)";
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat Destructor called" << std::endl;
	delete _brain;
}

void	Cat::makeSound() const {
	std::cout << "Type : ["<< _type << "] > Miaouuuuu" << std::endl;
}

void Cat::setThought(int index, const std::string& idea) {
	if (index < 0 || index >= 100)
	{
		std::cout << "Index out of bounds" << std::endl;
		return;
	}
	_brain->setIdea(index, idea);
}

void	Cat::showThought(int index) const {
	if (index < 0 || index >= 100)
	{
		std::cout << "Index out of bounds" << std::endl;
		return;
	}
	std::cout << "Cat's thought at index " << index << ": " << _brain->getIdea(index) << std::endl;
}
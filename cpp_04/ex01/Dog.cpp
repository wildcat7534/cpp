#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	std::cout << "Dog Default Constructor called" <<  std::endl;
	_brain = new Brain();
}

Dog::Dog(std::string type): Animal(type) {
	std::cout << "Dog Parametrized Constructor called" <<  std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog& other): Animal(other) {
	std::cout << "Dog Copy Constructor called" << std::endl;
	_type = other._type + " (copied)";
	_brain = new Brain(*other._brain);
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog Assignment Operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type + " (assigned)";
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog Destructor called" << std::endl;
	delete _brain;
}

void	Dog::makeSound() const{
	std::cout << "Type : ["<< _type << "] > Wouuuuuff" << std::endl;
}

void Dog::setThought(int index, const std::string& idea) {
	if (index < 0 || index >= 100)
	{
		std::cout << "Index out of bounds" << std::endl;
		return;
	}
	_brain->setIdea(index, idea);
}

void Dog::showThought(int index) const {
	if (index < 0 || index >= 100)
	{
		std::cout << "Index out of bounds" << std::endl;
		return;
	}
	_brain->setIdea(index, "I am a dog and I am thinking about bones.");
	std::cout << "Dog's thought at index " << index << ": " << _brain->getIdea(index) << std::endl;
}
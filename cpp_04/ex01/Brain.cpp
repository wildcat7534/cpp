#include "Brain.hpp"
#include <sstream>
#include <iomanip>

Brain::Brain(){
	for (int i = 0; i < 100; ++i) {
        std::ostringstream oss;
        oss << "Idea N° " << std::setw(2) << std::setfill('0') << i;
        _ideas[i] = oss.str();
    }
	std::cout << "Brain Default Constructor called" << std::endl;
}
Brain::Brain(const Brain& other){
	std::cout << "Brain Copy Constructor called" << std::endl;
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i] + " (copied)";
}
Brain& Brain::operator=(const Brain& other){
	std::cout << "Brain Assignment Operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other._ideas[i] + " (assigned)";
	}
	return *this;
}
Brain::~Brain(){
	std::cout << "Brain Destructor called" << std::endl;
}

std::string Brain::getIdea(int index) const {
	if (index < 0 || index >= 100)
	{
		std::cout << "Index out of bounds" << std::endl;
		return "";
	}
	return this->_ideas[index];
}

void Brain::setIdea(int index, const std::string& idea) {
	if (index < 0 || index >= 100)
	{
		std::cout << "Index out of bounds" << std::endl;
		return;
	}
	this->_ideas[index] = idea;
}
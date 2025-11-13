#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal {
	private:

	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		~Dog();
		void	makeSound() const;
		void	setThought(int index, const std::string& idea);
		void	showThought(int index) const;
};

#endif
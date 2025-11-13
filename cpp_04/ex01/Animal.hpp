#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

class Animal {
	protected:
		std::string _type;
		Brain* _brain;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();
		std::string	getType() const;
		virtual void	makeSound() const;
		void showThought(int index) const;
};

#endif
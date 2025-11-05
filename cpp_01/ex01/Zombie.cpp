#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("Default_Zombie") {
}

Zombie::Zombie(std::string Zname) : name(Zname) {
    announce();
}

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ" << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << ": is dead" << std::endl;
}

void Zombie::setName(const std::string &name) {
    this->name = name;
}

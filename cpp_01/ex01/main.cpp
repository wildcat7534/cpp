#include "Zombie.hpp"
#include <iostream>

int main(){
    Zombie *horde;
    horde = zombieHorde(3, "laHorde");
    if (horde == NULL)
        std::cout << "Pointer is null ! GG" << std::endl;
}
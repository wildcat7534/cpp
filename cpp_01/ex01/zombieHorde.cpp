#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
    Zombie *ptr;
    while (N > 0){
        ptr = new Zombie(name);
        delete ptr;
        N--;
    }
    ptr = NULL;
    return ptr;
}
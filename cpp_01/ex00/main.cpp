#include "tools.hpp"

int main(){
    Zombie *ariane;
    ariane = newZombie("Ariiiiane");
    delete ariane;
    randomChump("Clemennnnnt");

    Zombie Kamila("Kamilaaa");
    Kamila.announce();
    Zombie lapinou("Lapinouuuuu");
    lapinou.announce();
    return 0;
}
#include "tools.hpp"

int main(){

    std::cout << std::endl << "----- Testing newZombie and randomChump -----" << std::endl << std::endl;

    Zombie *Ariane;
    Ariane = newZombie("Ariiiiane");
    delete Ariane;
    randomChump("Clemennnnnt");

    Zombie Kamila("Kamilaaa");
    Kamila.announce();
    Zombie Lapinou("Lapinouuuuu");
    Lapinou.announce();

    std::cout << std::endl << "----- Testing copy constructor and assignment operator -----" << std::endl << std::endl;
    {
        Zombie zombcopy = Kamila;
        zombcopy.announce();
        Zombie zombassign("Temporaire");
        zombassign = Lapinou;
        zombassign.announce();
    }
    Kamila.announce();
    Lapinou.announce();

    std::cout << std::endl << "----- End of tests (garbage collection) -----" << std::endl << std::endl;
    return 0;
}

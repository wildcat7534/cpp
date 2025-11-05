#include "Zombie.hpp"
#include <iostream>

int main(){

    std::cout << std::endl << "----- Testing zombieHorde -----" << std::endl << std::endl;

    Zombie *horde;
    horde = zombieHorde(3, "laHorde");

    if (!horde)
        std::cerr << "Failed to create the horde of zombies." << std::endl;

    std::cout << std::endl << "----- Announcing the horde -----" << std::endl << std::endl;
    for (int i = 0; i < 3; ++i) {
		horde[i].announce();
	}

    std::cout << std::endl << "----- Deleting the horde -----" << std::endl << std::endl;

	delete[] horde;

    std::cout << std::endl << "----- End of tests (garbage collection) -----" << std::endl << std::endl;
    return 0;
}

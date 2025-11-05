
#include "HumanA.hpp"

int main()
{
    std::cout << std::endl << "----- Testing HumanA -----" << std::endl << std::endl;

    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }

    std::cout << std::endl << "----- Testing HumanB -----" << std::endl << std::endl;
    
    {
        Weapon club = Weapon("crude spiked club2");
        HumanB jim("Jim");
		//jim.attack();// pour tester avant affectation d'arme
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

    std::cout << std::endl << "----- End of tests (garbage collection) -----" << std::endl << std::endl;

    return 0;
}
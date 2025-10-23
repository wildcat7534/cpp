#include "HumanB.hpp"

class HumanA{
    private:
        std::string name;
        Weapon weapon;
    public:
        HumanA(std::string name, Weapon weapon) : name(name), weapon(weapon) {
            // name = newName;
            // weapon = newWeapon;
        }
        void attack();
};
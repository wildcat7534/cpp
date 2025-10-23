#include "Weapon.hpp"
#include <iostream>

class HumanB{
    private:
        std::string name;
        Weapon *weapon;
    public:
        HumanB(std::string name){
            this->name = name;
        }
        void setWeapon(Weapon &newWeapon){
            weapon = &newWeapon;
        };
        void attack(){
            std::cout << name << ": attack with weapon " << this->weapon->getType() << std::endl;
        }
};
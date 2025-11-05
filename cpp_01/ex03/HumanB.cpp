#include "HumanB.hpp"

HumanB::HumanB(std::string name) {_name = name;}
void HumanB::setWeapon(Weapon &newWeapon){_weapon = &newWeapon;}
void HumanB::attack(){std::cout << _name << ": attack with weapon " << _weapon->getType() << std::endl;}
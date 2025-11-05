#include "HumanB.hpp"

HumanB::HumanB(std::string name) {this->name = name;}
void HumanB::setWeapon(Weapon &newWeapon){weapon = &newWeapon;}
void HumanB::attack(){std::cout << name << ": attack with weapon " << this->weapon->getType() << std::endl;}
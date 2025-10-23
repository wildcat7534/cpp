#include <iostream>
#include "HumanA.hpp"

void HumanA::attack(){
		std::cout << this->name << ": attack with weapon " << this->weapon.getType() << std::endl;
};
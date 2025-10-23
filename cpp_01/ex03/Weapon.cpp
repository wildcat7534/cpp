#include "Weapon.hpp"

Weapon::Weapon(std::string typeName){
            type = typeName;
}

 std::string& Weapon::getType()  {
    return type;
}

void Weapon::setType(std::string newType){
    type = newType;
}
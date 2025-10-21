#include <iostream>

class Weapon{
    private:
        std::string type;

    public:
        Weapon(std::string typeName){
            type = typeName;
        }
        std::string getType(){
            return type;
        }
        void setType(std::string newType){
                type = newType;
        }
};

class HumanA{
    private:
        std::string name;
        Weapon weapon;
    public:
        HumanA(std::string newName, Weapon newWeapon) : name(newName), weapon(newWeapon) {
            // name = newName;
            // weapon = newWeapon;
        }
        void attack(){
            std::cout << name << ": attack with weapon " << weapon.getType() << std::endl;
        };
};

class HumanB{
    private:
        std::string name;
        Weapon *weapon;
    public:
        HumanB(std::string newName) {
          //weapon = Weapon("no");
            name = newName;
        };
        void setWeapon(Weapon newWeapon){
            weapon = &newWeapon;

        };
        void attack(){
            lastWeapon = weapon;
            std::cout << name << ": attack with weapon " << weapon->getType() << std::endl;
        }
};

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}
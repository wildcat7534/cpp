#include <iostream>
#include <string>

class Zombie{
    private:
        std::string name;

    public:
        Zombie(std::string Zname){
            name = Zname;
            announce();
    };
    void announce(void){
        std::cout << name << ": BraiiiiiiinnnzzzZ" << std::endl;
    }
    ~Zombie(){
        std::cout << name << ": is dead" << std::endl;
    }
};

Zombie* newZombie( std::string name ){
    Zombie* zombie = new Zombie(name);
    return zombie;
};

void randomChump( std::string name ){
    //Zombie zombie = Zombie(name);
    Zombie zombi2(name);
};

int main(){
    Zombie *ariane;
    ariane = newZombie("Ariane");
    delete ariane;
    randomChump("Clement");

    Zombie Kamila("Kamilaaa");
}
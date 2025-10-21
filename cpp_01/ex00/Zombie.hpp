#include <iostream>
#include <string>

class Zombie {
    private:
        std::string name;

    public:
        Zombie(std::string Zname);
        void announce(void);
        ~Zombie();
};

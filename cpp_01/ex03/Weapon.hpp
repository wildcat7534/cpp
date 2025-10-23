#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon{
    private:
        std::string type;

    public:
        Weapon(std::string typeName);
         std::string& getType() ;
        void setType(std::string newType);
};

#endif // WEAPON_HPP

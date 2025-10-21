/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariane <ariane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 23:16:14 by ariane            #+#    #+#             */
/*   Updated: 2025/10/06 00:08:04 by ariane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

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

Zombie* zombieHorde( int N, std::string name ){
    Zombie *ptr;
    while (N > 0){
        ptr = new Zombie(name);
        delete ptr;
        N--;
    }
    ptr = NULL;
    return ptr;
}

int main(){
    Zombie *horde;
    horde = zombieHorde(3, "laHorde");
    if (horde == NULL)
        std::cout << "Test" << std::endl;
}
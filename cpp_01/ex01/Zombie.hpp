#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
private:
	std::string name;

public:
	Zombie(std::string Zname);
	void announce(void);
	~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif // ZOMBIE_HPP
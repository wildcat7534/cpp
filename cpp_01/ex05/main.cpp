#include "Harl.hpp"

int main(int ac, char **av) {
    Harl harl;
	if (ac == 1)
	{
        harl.complain("DEBUG");
        harl.complain("INFO");
        harl.complain("WARNING");
        harl.complain("ERROR");
        harl.complain("BOUH");
	}
    else if (ac == 2)
    {
        harl.complain(av[1]);
    }
    else
    {
        std::cerr << "Usage: " << av[0] << " [level]" << std::endl;
        std::cerr << "Available levels: DEBUG, INFO, WARNING, ERROR" << std::endl;
        return 1;
    }
    return 0;
}

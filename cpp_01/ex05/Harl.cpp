#include "Harl.hpp"

void Harl::complain(const std::string &level) {
	int  i = 0;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void    (Harl::*functions[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	while(i < 4) {
		if (levels[i] == level)
			break;
		i++;
	}
	
	if (i < 4)
		(this->*functions[i])();
	else
		std::cout << "Invalid level" << std::endl;
}
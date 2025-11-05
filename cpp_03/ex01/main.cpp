#include "ScavTrap.hpp"

int main (){
	ScavTrap robot0;
	ScavTrap robot1("M. Clapi");
	ScavTrap robot2("Mme Rainette");

	robot2.takeDamage(5);
	robot2.attack("Robot");

	robot2.guardGate();

	robot1.attack(robot2.getName());
	
	robot2.takeDamage(3);
	robot2.beRepaired(2);
	robot2.attack(robot1.getName());
	
	robot1.takeDamage(0);
	robot1.attack(robot2.getName());

	robot2.beRepaired(4294967295);
	robot2.beRepaired(4294967295);
	robot2.takeDamage(999999999);

	robot2.beRepaired(0);

	ScavTrap robot3(robot2);
	ScavTrap robot4 = robot1;

	robot3.beRepaired(5);
	robot1.attack("");

	return 0;
}
#include <iostream>

class ClapTrap{
	private:
		std::string _name;
		int			_hitPoint = 10;
		int			_energyPoint = 10;
		int			_attackDamage = 5;

	public:
		// parametized string Constructor  
		ClapTrap(std::string name){
			_name = name;
			std::cout << "constructor of :" << this << std::endl;
		}
		~ClapTrap(){
			std::cout << "destructor of :" << this << std::endl;
		}
		void	attack(const std::string &target){
			std::cout << this->_name << " attack " << target << " causing " << this->_attackDamage << " points of damage !" << std::endl;
		}
		void	takeDamage(unsigned int amount){
			std::cout << this->_name << " take " << amount << " damage !" << std::endl;
		}
		void	beRepaired(){
			std::cout << this->_name << " regained " << this->_hitPoint << " hitPoint. " << std::endl;
		}
		std::string getName() const{
			return this->_name;
		}
};

int main (){
	ClapTrap robot1("M. Clapi");
	ClapTrap robot2("Mme Rainette");

	robot1.attack(robot2.getName());
	robot2.takeDamage(5);
	robot2.attack(robot1.getName());
	robot1.takeDamage(5);

	robot2.beRepaired();

}
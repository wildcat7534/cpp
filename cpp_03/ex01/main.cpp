#include <iostream>

class ClapTrap{
	private:
		std::string _name;
		int			_hitPoint = 100;
		int			_energyPoint = 10;
		int			_attackDamage = 5;

	public:
		// parametized string Constructor  
		ClapTrap(std::string name){
			_name = name;
			std::cout << "[ClapTrap] constructor of :" << this << std::endl;
		}
		~ClapTrap(){
			std::cout << "[ClapTrap] destructor of :" << this << std::endl;
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

class ScavTrap:public ClapTrap{
	private:
 		std::string _name;
		int			_hitPoint = 10;
		int			_energyPoint = 50;
		int			_attackDamage = 20;

	public:
		// parametized string Constructor  
		ScavTrap(std::string name):ClapTrap(name) {
			_name = name;
			std::cout << "[ScavTrap] constructor of :" << this << std::endl;
		}
		~ScavTrap(){
			std::cout << "[ScavTrap] destructor of :" << this << std::endl;
		}
		void	attack(const std::string &target){
			_energyPoint--;
			if (_energyPoint <= 0 || _hitPoint <= 0)
				std::cout << "no more energy or hitpoint !";
			else
				std::cout << "[ScavTrap] " << this->_name << " attack " << target << " causing " << this->_attackDamage << " points of damage !" << std::endl;
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
		void	guardGate(){
			std::cout << "[ScavTrap] " << this->_name << " in guardGate " << std::endl;			
		}
};


int main (){
	ScavTrap robot2("Mme Rainette");

	robot2.takeDamage(5);
	robot2.attack("Robot");

	robot2.beRepaired();
	robot2.guardGate();

	

}
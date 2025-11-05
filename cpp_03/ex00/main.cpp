#include <iostream>
#include <climits>

class ClapTrap{
	private:
		std::string _name;
		int			_hitPoint;
		int			_energyPoint;
		int			_attackDamage;
		int const	_maxHitPoint;

	public:
		// default Constructor
		ClapTrap(): _name("default"), _hitPoint(10), _energyPoint(10), _attackDamage(0), _maxHitPoint(_hitPoint){
			std::cout << "default constructor of :" << this << std::endl;
		};
		// parametized string Constructor
		ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0), _maxHitPoint(_hitPoint){
			std::cout << "constructor of :" << this << std::endl;
		}
		// copy constructor
		ClapTrap(const ClapTrap &other): _name(other._name),  _hitPoint(other._hitPoint), _energyPoint(other._energyPoint), _attackDamage(other._attackDamage), _maxHitPoint(other._maxHitPoint){
			std::cout << this << " copy constructor of : " << &other << std::endl;
		}
		// copy assignement operator
		ClapTrap &operator=(const ClapTrap &other){
			std::cout << this << " copy assignement operator of :" << &other << std::endl;
			if (this != &other){
				_name = other._name;
				_hitPoint = other._hitPoint;
				_energyPoint = other._energyPoint;
				_attackDamage = other._attackDamage;
			}
			return *this;
		}
		// destructor
		~ClapTrap(){
			std::cout << "destructor of :" << this << std::endl;
		}
		void	attack(const std::string& target){
			if (_energyPoint <= 0 || _hitPoint <= 0)
				std::cout << this->_name << " no more energy or hitpoint !" << std::endl;
			else if (target == "")
			{
				std::cout << this->_name << " cannot attack void target !" << std::endl;
			}
			else if (this->_attackDamage == 0)
			{
				std::cout << this->_name << " cannot attack with 0 attackDamage !" << std::endl;
			}
			else
			{
				this->_energyPoint--;
				std::cout << this->_name << " attack " << target << " causing " << this->_attackDamage  << std::endl;
			}
		}
		void	takeDamage(unsigned int amount){

			amount < (unsigned int)this->_hitPoint ?  this->_hitPoint -= amount : this->_hitPoint = 0;

			std::cout << this->_name << " take " << amount << " damage ! Current hitPoint: " << this->_hitPoint << std::endl;
		}
		void	beRepaired(unsigned int amount){
			if (_energyPoint == 0 || _hitPoint == 0 || amount == 0)
				std::cout << this->_name << " no more energy or hitpoint or cannot be repaired by 0 hitPoint !" << std::endl;
			else {
				long unsigned int temp;
				temp = (long unsigned int)amount + (long unsigned int)this->_hitPoint;
				this->_energyPoint--;
				if (temp < (unsigned int)this->_maxHitPoint){
					std::cout << this->_name << " Repaired " << amount << " hitPoint." << std::endl;
					this->_hitPoint += amount;
					std::cout << this->_name << " current hitPoint: " << this->_hitPoint << std::endl;
				}
				else{
					this->_hitPoint = this->_maxHitPoint;
					std::cout << this->_name << " regained " << this->_maxHitPoint << " hitPoint. Current hitPoint: " << this->_hitPoint << std::endl;
				}

			}
		}
		std::string getName() const{
			return this->_name;
		}
};

int main (){
	ClapTrap robot1("M. Clapi");
	ClapTrap robot2("Mme Rainette");

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

	ClapTrap robot3(robot2);
	ClapTrap robot4 = robot1;

	robot3.beRepaired(5);
	robot1.attack("");

	return 0;

}
#include <iostream>
#include <climits>

class ClapTrap{
	protected:
		std::string _name;
		int			_hitPoint;
		int			_energyPoint;
		int			_attackDamage;
		int const	_maxHitPoint;

	public:
		// default Constructor
		ClapTrap(): _name("default"), _hitPoint(10), _energyPoint(10), _attackDamage(0), _maxHitPoint(_hitPoint){
			std::cout << "[ClapTrap] default constructor of :" << this << std::endl;
		};
		// parametized string Constructor
		ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0), _maxHitPoint(_hitPoint){
			std::cout << "[ClapTrap] constructor of :" << this << std::endl;
		}
		// constructor for derived class
		ClapTrap(std::string name, int hit, int energy, int attack, int maxHit) : _name(name), _hitPoint(hit), _energyPoint(energy), _attackDamage(attack), _maxHitPoint(maxHit){
			std::cout << "[ClapTrap] param constructor of :" << this << std::endl;
		}
		// copy constructor
		ClapTrap(const ClapTrap &other): _name(other._name),  _hitPoint(other._hitPoint), _energyPoint(other._energyPoint), _attackDamage(other._attackDamage), _maxHitPoint(other._maxHitPoint){
			std::cout << "[ClapTrap] : " << this << " copy constructor of : " << &other << std::endl;
		}
		// copy assignement operator
		ClapTrap &operator=(const ClapTrap &other){
			std::cout << "[ClapTrap] : " << this << " copy assignement operator of :" << &other << std::endl;
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
			std::cout << "[ClapTrap] destructor of :" << this << std::endl;
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

class ScavTrap : public ClapTrap {

	public:
		// default Constructor
		ScavTrap(): ClapTrap() {
			std::cout << "[ScavTrap] default constructor of :" << this << std::endl;
		};
		// parametized string Constructor and default values
		ScavTrap(std::string name):ClapTrap(name, 100, 50, 20, 100) {
			std::cout << "[ScavTrap] param constructor of :" << this << std::endl;
		}
		// parametized string Constructor and default values for derived class
		ScavTrap(std::string name, int hit, int energy, int attack):ClapTrap(name, hit, energy, attack, hit) {
			std::cout << "[ScavTrap] param constructor of :" << this << std::endl;
		}
		// destructor
		~ScavTrap(){
			std::cout << "...[ScavTrap] destructor of :" << this << std::endl;
		}
		void	attack(const std::string& target){
			if (_energyPoint <= 0 || _hitPoint <= 0)
				std::cout << this->_name << "[ScavTrap] no more energy or hitpoint !" << std::endl;
			else if (target == "")
			{
				std::cout << this->_name << "[ScavTrap] cannot attack void target !" << std::endl;
			}
			else if (this->_attackDamage == 0)
			{
				std::cout << this->_name << "[ScavTrap] cannot attack with 0 attackDamage !" << std::endl;
			}
			else
			{
				this->_energyPoint--;
				std::cout << this->_name << "[ScavTrap] attack " << target << " causing " << this->_attackDamage  << std::endl;
			}
		}
		// new function
		void	guardGate(){
			std::cout << "[ScavTrap] " << this->_name << " in guardGate " << std::endl;			
		}
};

class FragTrap : public ClapTrap{

	public:
		// default Constructor
		FragTrap(): ClapTrap() {
			std::cout << "[FragTrap] default constructor of :" << this << std::endl;
		};
		// parametized string Constructor
		FragTrap(std::string name):ClapTrap(name, 100, 50, 20, 100) {
			std::cout << "[FragTrap] param constructor of :" << this << std::endl;
		}
		// destructor
		~FragTrap(){
			std::cout << "...[FragTrap] destructor of :" << this << std::endl;
		}
		void	attack(const std::string& target){
			if (_energyPoint <= 0 || _hitPoint <= 0)
				std::cout << this->_name << "[FragTrap] no more energy or hitpoint !" << std::endl;
			else if (target == "")
			{
				std::cout << this->_name << "[FragTrap] cannot attack void target !" << std::endl;
			}
			else if (this->_attackDamage == 0)
			{
				std::cout << this->_name << "[FragTrap] cannot attack with 0 attackDamage !" << std::endl;
			}
			else
			{
				this->_energyPoint--;
				std::cout << this->_name << "[FragTrap] attack " << target << " causing " << this->_attackDamage  << std::endl;
			}
		}
		void	highFivesGuys(){
			std::cout << "[FragTrap] " << this->_name << " request a high five !" << std::endl;			
		}
};

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string _name;

	public:
		// default Constructor
		DiamondTrap(): ScavTrap() {
			std::cout << "[DiamondTrap] default constructor of :" << this << std::endl;
		};
		// parametized string Constructor
		DiamondTrap(std::string name):ScavTrap(name) {
			this->_name = ScavTrap::_name + "_clap_name";
			std::cout << "[DiamondTrap] param constructor of :" << this << std::endl;
		}
		// parametized string Constructor and default values
		DiamondTrap(std::string name):FragTrap(name), ScavTrap(name) {
			this->_hitPoint = this->FragTrap::_hitPoint;
			this->_energyPoint = this->ScavTrap::_energyPoint;
			this->_attackDamage = this->FragTrap::_attackDamage;
			std::cout << "[DiamondTrap] param constructor of :" << this << std::endl;
		}
		// destructor
		~DiamondTrap(){
			std::cout << "...[DiamondTrap] destructor of :" << this << std::endl;
		}
		void	attack(const std::string& target){
			if (ScavTrap::_energyPoint <= 0 || ScavTrap::_hitPoint <= 0)
				std::cout << this->_name << "[DiamondTrap] no more energy or hitpoint !" << std::endl;
			else if (target == "")
			{
				std::cout << this->_name << "[DiamondTrap] cannot attack void target !" << std::endl;
			}
			else if (this->ScavTrap::_attackDamage == 0)
			{
				std::cout << this->_name << "[DiamondTrap] cannot attack with 0 attackDamage !" << std::endl;
			}
			else
			{
				this->_energyPoint--;
				std::cout << this->_name << "[DiamondTrap] attack " << target << " causing " << this->_attackDamage  << std::endl;
			}
		}
		// new function
		void	whoAmI(){
			std::cout << "[DiamondTrap] My name is " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;			
		}
};

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

	std::cout << "---------------------FRAGTRAP TESTS---------------------" << std::endl;

	FragTrap robot10;
	FragTrap robot11("M. Clapi");
	FragTrap robot12("Mme Rainette");

	robot12.takeDamage(5);
	robot12.attack("Robot");

	//robot10.guardGate();

	robot11.attack(robot12.getName());

	robot10.takeDamage(3);
	robot10.beRepaired(2);
	robot10.attack(robot11.getName());

	robot11.takeDamage(0);
	robot11.attack(robot12.getName());

	robot12.beRepaired(4294967295);
	robot12.beRepaired(4294967295);
	robot12.takeDamage(999999999);

	robot12.beRepaired(0);

	FragTrap robot13(robot12);
	FragTrap robot14 = robot11;

	robot13.beRepaired(5);
	robot11.attack("");
	robot12.highFivesGuys();

}
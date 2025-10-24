#include <iostream>

class Fixed {
	private:
		int	_nb;
		int _bit = 8;
	public:
		//default
		Fixed() : _nb(0){
			std::cout << "Default constructor called " << this << std::endl;
		}
		// test param 2 int
		/* 		Fixed(int nb, int bit) : _nb(nb), _bit(bit){
			std::cout << "2 param constructor : " << this << std::endl << std::endl ;
			} */
		//copy
		Fixed(const Fixed& other) {
			std::cout << "Copy constructor called " << this << std::endl ;
			*this = other;
		}
		//assignement Operator
		Fixed &operator=(const Fixed &other){
			std::cout << "Copy assignement operator called " << this << std::endl ;
			//std::cout << this << " -> this // " << &other << " -> other " << std::endl << std::endl;
			if (this != &other){
				_bit = other.getRawBits();
			}
			return *this;
		}
		
		~Fixed(){
			std::cout << this << " is destroyed" << std::endl;
		}
		int getRawBits() const {
			std::cout << "getRawBits member function called " << this << std::endl;
			//std::cout << "_nb && _bit : " << this->_nb << " // " << this->_bit << std::endl << std::endl;
			return 0;
		}
};

int main(){

	Fixed a;
	//std::cout << "a : " << &a << std::endl << std::endl;


	Fixed b(a);
	//std::cout << "b : " << &b << std::endl << std::endl;

	//Fixed a;
	//Fixed b( a );
	Fixed c;
	c = b;


	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	

}
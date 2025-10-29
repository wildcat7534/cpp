#include "Fixed.hpp"

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
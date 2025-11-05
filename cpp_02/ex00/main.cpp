#include "Fixed.hpp"

int main(){

	std::cout << std::endl << "----- Testing Fixed class -----" << std::endl << std::endl;

	Fixed a;
	//std::cout << "a : " << &a << std::endl << std::endl;

	std::cout << std::endl << "----- Testing copy constructor -----" << std::endl << std::endl;

	Fixed b(a);
	//std::cout << "b : " << &b << std::endl << std::endl;

	//Fixed a;
	//Fixed b( a );

	std::cout << std::endl << "----- Testing assignment operator -----" << std::endl << std::endl;
	Fixed c;
	c = b;

	std::cout << std::endl << "----- Getting raw bits -----" << std::endl << std::endl;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << std::endl << "----- End of tests (garbage collection) -----" << std::endl << std::endl;
	return 0;
}
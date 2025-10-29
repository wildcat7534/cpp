#include "Fixed.hpp"

int main(){
	Fixed 	a;
	Fixed const	b(Fixed(5.05f) * Fixed(2)); 
	
	std::cout << "a : " <<  a << std::endl << std::endl;
	std::cout << "a : " <<  ++a << std::endl;
	std::cout << "a : " <<  a << std::endl;
	std::cout << "a : " <<  a++ << std::endl;
	std::cout << "Final a : " <<  a << std::endl;
	
	std::cout << "b : " <<  b << std::endl;
	
	std::cout << Fixed::max(a, b) << std::endl;
	
	std::cout << "a : " <<  a << std::endl;
	std::cout << "a : " <<  --a << std::endl;
	std::cout << "a : " <<  a << std::endl;
	std::cout << "a : " <<  a-- << std::endl;
	std::cout << "Final a : " <<  a << std::endl << std::endl;
	
	Fixed const	c(Fixed(5.05f) + Fixed(2)); 
	Fixed const	d(Fixed(5.05f) - Fixed(2)); 
	Fixed const	e(Fixed(5.05f) / Fixed(2));
	
	//Fixed const	f(Fixed(5.05f) > Fixed(2)); 
	
	std::cout << "c (Fixed(5.05f) + Fixed(2): " <<  c << std::endl;
	std::cout << "d (Fixed(5.05f) - Fixed(2): " <<  d << std::endl;
	std::cout << "e (Fixed(5.05f) / Fixed(2): " <<  e << std::endl << std::endl;
	
	Fixed const	g(100);
	Fixed const	h(0);
	
	if (a > b)
		std::cout << "a > b" << std::endl; 
	else
		std::cout << "a < b" << std::endl; 
	if (g > b)
		std::cout << "g > b" << std::endl; 
	else
		std::cout << "g < b" << std::endl; 
	if (a >= b)
		std::cout << "a >= b" << std::endl; 
	else
		std::cout << "a <= b" << std::endl; 
	if (g <= b)
		std::cout << "g <= b" << std::endl; 
	else
		std::cout << "g >= b" << std::endl; 
	if (a == b)
		std::cout << "a == b" << std::endl; 
	else
		std::cout << "a != b" << std::endl; 
	if (g != b)
		std::cout << "g != b" << std::endl; 
	else
		std::cout << "g == b" << std::endl; 
	if (h == a)
		std::cout << "h == a" << std::endl; 
	else
		std::cout << "h != a" << std::endl;
}
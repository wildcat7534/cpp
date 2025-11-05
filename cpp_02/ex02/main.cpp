#include "Fixed.hpp"

int main(){

	{

		std::cout << std::endl << "\033[1m\033[38;5;226m" << "----- Standard tests -----" << "\033[0m" << std::endl << std::endl;
		Fixed aaa;
		Fixed const bbb(Fixed(5.05f) * Fixed(2));


		std::cout << aaa << std::endl;
		std::cout << ++aaa << std::endl;
		std::cout << aaa << std::endl;
		std::cout << aaa++ << std::endl;
		std::cout << aaa << std::endl;
		std::cout << bbb << std::endl;

		std::cout << Fixed::max(aaa, bbb) << std::endl;

		Fixed ccc = 0;

		std::cout << std::endl << "\033[1m\033[38;5;226m" << "----- Other tests -----" << "\033[0m" << std::endl << std::endl;


		std::cout << "\033[1m" << "aaa  : " << aaa << "\033[0m" << std::endl;
		std::cout << "\033[1m" << "bbb  : " << bbb << "\033[0m" << std::endl;
		std::cout << "\033[1m" << "ccc  : " << ccc << "\033[0m" << std::endl;
		try {
			std::cout << bbb / ccc << std::endl;
		} catch (const std::exception& e) {
			std::cerr  << "bbb / ccc                        : " << "Error: Division by zero" << std::endl;
		}
		std::cout << "Fixed(3.0f) / Fixed(2.0f)    : " << Fixed(3.0f) / Fixed(2.0f) << std::endl
		<< "Fixed(3)    / Fixed(2)       : " << Fixed(3) / Fixed(2) << std::endl
		<< "Fixed(3.0f) * Fixed(2.0f)    : " << Fixed(3.0f) * Fixed(2.0f) << std::endl
		<< "Fixed(3)    * Fixed(2)       : " << Fixed(3) * Fixed(2) << std::endl
		<< "Fixed::max(aaa, bbb)         : " << Fixed::max(aaa, bbb) << std::endl
		<< "Fixed::min(aaa, bbb)        : " << Fixed::min(aaa, bbb) << std::endl
		<< "aaa > bbb                    : " << (aaa > bbb) << std::endl
		<< "aaa < bbb                    : " << (aaa < bbb) << std::endl
		<< "aaa >= bbb                   : " << (aaa >= bbb) << std::endl
		<< "aaa <= bbb                   : " << (aaa <= bbb) << std::endl
		<< "aaa == bbb                   : " << (aaa == bbb) << std::endl
		<< "aaa != bbb                   : " << (aaa != bbb) << std::endl
		<< "aaa + bbb                    : " << (aaa + bbb) << std::endl
		<< "aaa - bbb                    : " << (aaa - bbb) << std::endl
		<< "bbb + aaa                    : " << (bbb + aaa) << std::endl
		<< "bbb - aaa                    : " << (bbb - aaa) << std::endl;

		std::cout << std::endl << "\033[1m\033[38;5;226m" << "----- Ending block -----" << "\033[0m" << std::endl << std::endl;
	}
	{
		std::cout << std::endl << "----- Testing next -----" << std::endl << std::endl;

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
}

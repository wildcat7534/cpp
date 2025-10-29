#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}

/* 	float fl = 42.42;
	//int nb = 23;

	Fixed test_a(fl);

	//std::cout << "Resulat flt : " << test_a.getFloat() << std::endl;
	std::cout << "Resulat int : " << test_a.getInt() << std::endl;

	//Fixed test_b(test_a.getInt());
	Fixed test_b(10860);

	std::cout << "Resulat flt : " << test_b.getFloat() << std::endl; */

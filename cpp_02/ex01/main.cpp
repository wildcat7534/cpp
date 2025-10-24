#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _nb;
	float _flt;
	int _bit = 8;

public:
	// default
	Fixed() : _nb(0)
	{
		std::cout << "Default constructor called " << std::endl;
	}
	//  entier constant
	Fixed(int nb)
	{
		std::cout << "Int constructor called " << std::endl;
		_nb = nb * 256;
	}
	//  flottant
	Fixed(const float flt)
	{
		std::cout << "Float constructor called " << std::endl;
		_nb = static_cast<int>(roundf(flt * (1 << 8)));
	}
	// copy objet
	Fixed(const Fixed &other)
	{
		std::cout << "Copy constructor called " << std::endl;
		*this = other;
	}
	// copy assignement Operator
	Fixed &operator=(const Fixed &other)
	{
		std::cout << "Copy assignement operator called " << std::endl;
		if (this != &other)
		_nb = other._nb;
		return *this;
	}
	~Fixed()
	{
		std::cout << "Destructor called" << std::endl;
	}
	int getRawBits() const
	{
		std::cout << "getRawBits member function called " << std::endl;
		return 0;
	}
	int toInt() const {
		return _nb >> _bit;
	}
	float toFloat() const {
		return static_cast<float>(_nb) / (1 << _bit);
	}
};

std::ostream &operator<<(std::ostream &os, const Fixed &f){
	os << f.toFloat();
	return os;
}

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

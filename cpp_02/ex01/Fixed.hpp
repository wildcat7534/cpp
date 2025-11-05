#include <iostream>

class Fixed {
	private:
		int	_nb;
		float _flt;
		int _bit;
	public:
		//default
		Fixed();
		// integer constant
		Fixed(int nb);
		// float constant
		Fixed(const float flt);
		//copy object
		Fixed(const Fixed& other);
		//copy assignement Operator
		Fixed& operator=(const Fixed &other);
		~Fixed();
		int getRawBits() const;
		int toInt() const;
		float toFloat() const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);

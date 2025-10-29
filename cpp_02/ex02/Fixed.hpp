#include <iostream>

class Fixed {
	private:
		int	_fix;
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
		Fixed &operator=(const Fixed &other);
		// arithmetic (membres)
		Fixed operator*(const Fixed& other) const;
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		// comparisons
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		// increment / decrement
		Fixed& operator++();   // pré-incrément
		Fixed operator++(int); // post-incrément
		Fixed& operator--();   // pré-décrément
		Fixed operator--(int); // post-décrément
		~Fixed();
		int getRawBits() const;
		int toInt() const;
		float toFloat() const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &f);

#include <iostream>

class Fixed {
	private:
		int	_nb;
		int _bit;
	public:
		//default
		Fixed();
		//copy
		Fixed(const Fixed& other);
		//assignement Operator
		Fixed &operator=(const Fixed &other);
		~Fixed();
		int getRawBits() const;
};
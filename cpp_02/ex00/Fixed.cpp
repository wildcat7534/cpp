#include "Fixed.hpp"

Fixed::Fixed() : _nb(0), _bit(8) {
	std::cout << "Default constructor called " << this << std::endl;
}
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called " << this << std::endl ;
	*this = other;
}
Fixed& Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignement operator called " << this << std::endl ;
	if (this != &other){
		_nb = other.getRawBits();
		return *this;
	}
	else
		return *this;
}
Fixed::~Fixed(){
	std::cout << this << " is destroyed" << std::endl;
}
int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called " << this << std::endl;
	return _nb;
}
#include "Fixed.hpp"
#include <cmath>
// default
Fixed::Fixed() : _nb(0), _bit(8) {
	std::cout << "Default constructor called " << this << std::endl;
}
// parametized integer constant
Fixed::Fixed(int nb) : _bit(8) {
	std::cout << "Int constructor called " << this << std::endl;
	_nb = nb * 256;
}
// parametized float constant
Fixed::Fixed(const float flt) : _bit(8) {
	std::cout << "Float constructor called " << this << std::endl;
	_nb = static_cast<int>(roundf(flt * (1 << 8)));
}
// copy object
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called " << this << std::endl ;
	*this = other;
}
// copy assignement operator
Fixed& Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignement operator called " << this << std::endl ;
	if (this != &other){
		_nb = other.getRawBits();
		return *this;
	}
	return *this;
}
// copy objet * objet
Fixed Fixed::operator*(const Fixed &other) const{
	return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator+(const Fixed &other) const{
	return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed &other) const{
	return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator/(const Fixed &other) const{
	return Fixed(this->toFloat() / other.toFloat());
}
int Fixed::operator>(const Fixed &other) const{
	if ((this->toFloat() > other.toFloat()))
		return 1;
	else
		return 0;
}
int Fixed::operator<(const Fixed &other) const{
	if ((this->toFloat() < other.toFloat()))
		return 1;
	else
		return 0;
}
int Fixed::operator>=(const Fixed &other) const{
	if ((this->toFloat() >= other.toFloat()))
		return 1;
	else
		return 0;
}
int Fixed::operator<=(const Fixed &other) const{
	if ((this->toFloat() <= other.toFloat()))
		return 1;
	else
		return 0;
}
int Fixed::operator==(const Fixed &other) const{
	if ((this->toFloat() == other.toFloat()))
		return 1;
	else
		return 0;
}
int Fixed::operator!=(const Fixed &other) const{
	if ((this->toFloat() != other.toFloat()))
		return 1;
	else
		return 0;
}
Fixed& Fixed::operator++() {
	this->_fix++;
	return (*this);
}
Fixed& Fixed::operator--() {
	this->_fix--;
	return (*this);
}
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	this->_fix++;
	return (tmp);
}
Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	this->_fix--;
	return (tmp);
}
Fixed::~Fixed(){
	std::cout << this << " is destroyed" << std::endl;
}
int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called " << this << std::endl;
	return _nb;
}
int Fixed::toInt() const {
	return _nb >> _bit;
}
float Fixed::toFloat() const {
	return static_cast<float>(_nb) / (1 << _bit);
}
static float Fixed::max( Fixed a , Fixed b) {
	if (a._fix > b._fix){
		return a.toFloat();
	}
	else
		return b.toFloat();
}
static float min( Fixed a , Fixed b) {
	if (a._fix < b._fix){
		return a.toFloat();
	}
	else
		return b.toFloat();
}

std::ostream &operator<<(std::ostream &os, const Fixed &f){
	os << f.toFloat();
	return os;
}
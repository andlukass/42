#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed & Fixed::operator=(Fixed const &other)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &other)
		this->_fixedPointValue = other.getRawBits();
	return *this;
}

Fixed::Fixed(const int i)
{
	this->_fixedPointValue = (i << _fractionalBits);
}

Fixed::Fixed(const float f)
{
	float factor = 1 << _fractionalBits;
	this->_fixedPointValue = (f * factor);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

int Fixed::toInt() const {
	return (_fixedPointValue >> _fractionalBits);
}

float Fixed::toFloat() const {
	float factor = 1 << _fractionalBits;
	return ((float)_fixedPointValue / factor);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs) {
	o << rhs.toFloat();
	return (o);
}
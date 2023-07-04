#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	//Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	//std::cout << b << std::endl;
	//std::cout << Fixed::max(a, b) << std::endl;

	return 0;
}




//Fixed const c(5.5f);
//std::cout << c.getRawBits() << std::endl;
//std::cout << sizeof(int) << std::endl;

//0000 0000 0000 0000 0000 0001 0000 0000
// *
//0000 0000 0000 0000 0000 0000 0000 0101   /4
//0000 0000 0000 0000 0000 0101 0000 0000   /4 Fixed

//0000 0000 0000 0000 0000 0100 1000 0000   /4.5 Fixed
//0000 0000 0000 0000 0000 0100 1010 0110   /4.649 Fixed



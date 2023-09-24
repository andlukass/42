#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b(65156);
	Fixed const c(5.5789f);
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




//Fixed const c(5.5f);
//std::cout << c.getRawBits() << std::endl;
//std::cout << sizeof(int) << std::endl;

//0000 0000 0000 0000 0000 0001 0000 0000
// *
//0000 0000 0000 0000 0000 0000 0000 0101   /4
//0000 0000 0000 0000 0000 0101 0000 0000   /4 Fixed

//0000 0000 0000 0000 0000 0100 1000 0000   /4.5 Fixed
//0000 0000 0000 0000 0000 0100 1010 0110   /4.649 Fixed



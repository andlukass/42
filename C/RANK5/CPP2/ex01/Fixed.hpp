#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;

	public:
		Fixed();
		~Fixed(void);
		Fixed(Fixed const & src);
		Fixed & operator=(Fixed const & other);

		Fixed(const int i);
		Fixed(const float f);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

};

	std::ostream &operator<<(std::ostream &o, Fixed const &other);

#endif
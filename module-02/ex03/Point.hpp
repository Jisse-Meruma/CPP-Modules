#include "Fixed.hpp"

class Point
{
	public:
	Point(void);
	Point(const float x, const float y);
	Point( const Point &C );

	Point	&operator=(const Point &C);

	~Point(void);

	const Fixed &getFixedx(void);
	const Fixed &getFixedy(void);

	private:
		const Fixed	_x;
		const Fixed	_y;
};
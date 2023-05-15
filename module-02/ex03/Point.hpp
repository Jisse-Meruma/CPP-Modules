#include "Fixed.hpp"

class Point
{
	public:
	Point(void);
	Point(const float x, const float y);
	Point( const Point &C );

	Point	&operator=(const Point &C);

	~Point(void);

	const Fixed &getFixedx(void) const;
	const Fixed &getFixedy(void) const;

	private:
		const Fixed	_x;
		const Fixed	_y;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);
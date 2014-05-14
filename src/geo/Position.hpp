#ifndef __GEO__POSITION__HPP__
#define __GEO__POSITION__HPP__

namespace geo {

class Position
{
public:
	typedef double Latitude;
	typedef double Longitude;

	explicit Position(Latitude = 0.0, Longitude = 0.0);

	Latitude lat() const;
	Longitude lon() const;

	Position normalize() const;

private:
	Latitude latitude;
	Longitude longitude;
};

}

#endif

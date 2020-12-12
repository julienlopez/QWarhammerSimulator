#include "point.hpp"

namespace QWarhammerSimulator::LibGeometry
{

Point& Point::operator+=(const Point& p)
{
    x += p.x;
    y += p.y;
    return *this;
}

Point operator*(Point p, const double factor)
{
    return {factor * p.x, factor * p.y};
}

Point operator*(const double factor, Point p)
{
    return p * factor;
}

} // namespace QWarhammerSimulator::LibGeometry

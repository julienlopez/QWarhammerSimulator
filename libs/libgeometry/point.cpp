#include "point.hpp"

#include <iostream>

namespace QWarhammerSimulator::LibGeometry
{

Point& Point::operator+=(const Point& p)
{
    x += p.x;
    y += p.y;
    return *this;
}

Point& Point::operator-=(const Point& p)
{
    x -= p.x;
    y -= p.y;
    return *this;
}

Point& Point::operator*=(const double factor)
{
    x *= factor;
    y *= factor;
    return *this;
}

Point& Point::operator/=(const double factor)
{
    x /= factor;
    y /= factor;
    return *this;
}

bool operator==(const Point& p1, const Point& p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

Point operator+(Point p1, const Point& p2)
{
    return p1 += p2;
}

Point operator-(Point p1, const Point& p2)
{
    return p1 -= p2;
}

Point operator*(Point p, const double factor)
{
    return p *= factor;
}

Point operator*(const double factor, Point p)
{
    return p * factor;
}

Point operator/(Point p, const double factor)
{
    return p /= factor;
}

std::ostream& operator<<(std::ostream& o, const Point& p)
{
    return o << "{" << p.x << "," << p.y << "}";
}

} // namespace QWarhammerSimulator::LibGeometry

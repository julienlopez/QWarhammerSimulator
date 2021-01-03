#pragma once

#include <iosfwd>

namespace QWarhammerSimulator::LibGeometry
{

struct Point
{
    double x;
    double y;

    Point& operator+=(const Point& p);

    Point& operator-=(const Point& p);

    Point& operator*=(const double factor);

    Point& operator/=(const double factor);
};

bool operator==(const Point& p1, const Point& p2);

Point operator+(Point p1, const Point& p2);

Point operator-(Point p1, const Point& p2);

Point operator*(Point p, const double factor);

Point operator*(const double factor, Point p);

Point operator/(Point p, const double factor);

std::ostream& operator<<(std::ostream& o, const Point& p);

} // namespace QWarhammerSimulator::LibGeometry

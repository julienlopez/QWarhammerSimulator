#pragma once

namespace QWarhammerSimulator::LibGeometry
{

struct Point
{
    double x;
    double y;

    Point& operator+=(const Point& p);
};

Point operator*(Point p, const double factor);

Point operator*(const double factor, Point p);

} // namespace QWarhammerSimulator::LibGeometry

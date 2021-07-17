#pragma once

#include "point.hpp"

namespace QWarhammerSimulator::LibGeometry
{

struct Rectangle
{
public:
    Rectangle(Point center, double orientation, Point size);

    const Point& center() const;

    Point topLeft() const;

    Point topRight() const;

    Point bottomLeft() const;

    Point bottomRight() const;

    Point forwardUnitVector() const;

    void moveForward(double distance);

    double height() const;

    double width() const;

    double orientation() const; // in radians

    bool contains(const Point& p) const;

private:
    Point m_center;
    double m_orientation; // in radians
    Point m_size;
};

} // namespace QWarhammerSimulator::LibGeometry

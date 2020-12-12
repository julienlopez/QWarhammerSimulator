#pragma once

#include "point.hpp"

namespace QWarhammerSimulator::LibGeometry
{

struct Rectangle
{
public:
    const Point& center() const;

    Point forwardUnitVector() const;

    void moveForward(double distance);

private:
    Point m_center;
    double m_orientation; // in radians
};

} // namespace QWarhammerSimulator::LibGeometry

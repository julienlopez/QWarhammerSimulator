#include "rectangle.hpp"

#include <cmath>

namespace QWarhammerSimulator::LibGeometry
{

const Point& Rectangle::center() const
{
    return m_center;
}

Point Rectangle::forwardUnitVector() const
{
    return {cos(m_orientation), sin(m_orientation)};
}

void Rectangle::moveForward(double distance)
{
    m_center += distance * forwardUnitVector();
}

} // namespace QWarhammerSimulator::LibGeometry

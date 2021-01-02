#include "rectangle.hpp"

#include <cmath>
#include <utility>

namespace QWarhammerSimulator::LibGeometry
{

Rectangle::Rectangle(Point center, double orientation, Point size)
    : m_center(std::move(center))
    , m_orientation(orientation)
    , m_size(std::move(size))
{
}

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

double Rectangle::height() const
{
    return m_size.y;
}

double Rectangle::width() const
{
    return m_size.x;
}

} // namespace QWarhammerSimulator::LibGeometry

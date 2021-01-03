#include "rectangle.hpp"

#include <cmath>
#include <utility>

namespace QWarhammerSimulator::LibGeometry
{

namespace
{

    /**
     * @brief returns the normal vector (ie, rotated 90° ccw)
     */
    Point normalVector(const Point& p)
    {
        return {-p.y, p.x};
    }

} // namespace

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

Point Rectangle::topLeft() const
{
    const auto fwd_vec = forwardUnitVector();
    return m_center + fwd_vec * (m_size.y / 2) + (normalVector(fwd_vec)) * (m_size.x / 2);
}

Point Rectangle::topRight() const
{
    const auto fwd_vec = forwardUnitVector();
    return m_center + fwd_vec * (m_size.y / 2) - (normalVector(fwd_vec)) * (m_size.x / 2);
}

Point Rectangle::forwardUnitVector() const
{
    return {std::cos(m_orientation), std::sin(m_orientation)};
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

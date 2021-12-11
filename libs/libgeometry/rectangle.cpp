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

Point Rectangle::bottomLeft() const
{
    const auto fwd_vec = forwardUnitVector();
    return m_center - fwd_vec * (m_size.y / 2) + (normalVector(fwd_vec)) * (m_size.x / 2);
}

Point Rectangle::bottomRight() const
{
    const auto fwd_vec = forwardUnitVector();
    return m_center - fwd_vec * (m_size.y / 2) - (normalVector(fwd_vec)) * (m_size.x / 2);
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

double Rectangle::orientation() const
{
    return m_orientation;
}

bool Rectangle::contains(const Point& p) const
{
    // (0<AP.AB<AB.AB)|(0<AP.AD<AD.AD)
    const auto a = topLeft();
    const auto b = topRight();
    const auto d = bottomLeft();
    const auto ap_ab = dot(p - a, b - a);
    const auto ap_ad = dot(p - a, d - a);
    return ap_ab >= 0 && ap_ad >= 0 && ap_ab <= dot(b - a, b - a) && ap_ad <= dot(d - a, d - a);
}

} // namespace QWarhammerSimulator::LibGeometry

#include "custom_matchers.hpp"

#include <sstream>

namespace QWarhammerSimulator::Testing
{

PointMatcher::EqualsMatcher::EqualsMatcher(const Point& ref, const double epsilon)
    : m_ref{ref}
    , m_epsilon(epsilon)
{
}

bool PointMatcher::EqualsMatcher::match(const Point& other) const
{
    return approx(m_ref.x, other.x) && approx(m_ref.y, other.y);
}

std::string PointMatcher::EqualsMatcher::describe() const
{
    std::ostringstream oss;
    oss << "Equals: " << m_ref;
    return oss.str();
}

bool PointMatcher::EqualsMatcher::approx(const double d1, const double d2) const
{
    return std::abs(d1 - d2) < m_epsilon;
}

PointMatcher::EqualsMatcher PointMatcher::Equals(const PointMatcher::Point& ref, const double epsilon)
{
    return {ref, epsilon};
}

} // namespace QWarhammerSimulator::Testing

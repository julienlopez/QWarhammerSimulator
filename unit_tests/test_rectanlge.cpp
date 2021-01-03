#include <catch2/catch.hpp>

#include "rectangle.hpp"

#include <sstream>

using QWarhammerSimulator::LibGeometry::Point;
using QWarhammerSimulator::LibGeometry::Rectangle;

namespace PointMatcher
{

struct EqualsMatcher : Catch::Matchers::Impl::MatcherBase<Point>
{
    EqualsMatcher(const Point& ref, const double epsilon)
        : m_ref{ref}
        , m_epsilon(epsilon)
    {
    }

    bool match(const Point& other) const
    {
        return approx(m_ref.x, other.x) && approx(m_ref.y, other.y);
    }

    std::string describe() const override
    {
        std::ostringstream oss;
        oss << "Equals: " << m_ref;
        return oss.str();
    }

private:
    const Point& m_ref;
    const double m_epsilon;

    bool approx(const double d1, const double d2) const
    {
        return std::abs(d1 - d2) < m_epsilon;
    }
};

EqualsMatcher Equals(const Point& ref, const double epsilon = 1E-3)
{
    return {ref, epsilon};
}
}

TEST_CASE("Basic Rectangle Usage", "[LibGeometry]")
{

    SECTION("a zero orientation rectangle (facing right)")
    {
        Rectangle r{{0, 0}, 0, {5, 2}};
        CHECK_THAT(r.center(), PointMatcher::Equals({0, 0}));
        CHECK_THAT(r.forwardUnitVector(), PointMatcher::Equals({1, 0}));
        CHECK_THAT(r.topLeft(), PointMatcher::Equals({1, 2.5}));
        CHECK_THAT(r.topRight(), PointMatcher::Equals({1, -2.5}));
    }

    SECTION("a 90° orientation rectangle (facing up)")
    {
        const double pi = std::acos(-1);
        Rectangle r{{0, 0}, pi/2, {5, 2}};
        CHECK_THAT(r.center(), PointMatcher::Equals({0, 0}));
        CHECK_THAT(r.forwardUnitVector(), PointMatcher::Equals({0, 1}));
        CHECK_THAT(r.topLeft(), PointMatcher::Equals({-2.5, 1}));
        CHECK_THAT(r.topRight(), PointMatcher::Equals({2.5, 1}));
    }
}

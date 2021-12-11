#include <catch2/catch.hpp>

#include "rectangle.hpp"

#include "custom_matchers.hpp"

using QWarhammerSimulator::LibGeometry::Point;
using QWarhammerSimulator::LibGeometry::Rectangle;

using QWarhammerSimulator::Testing::PointMatcher::Equals;

TEST_CASE("Basic Rectangle Usage", "[LibGeometry]")
{

    SECTION("a zero orientation rectangle (facing right)")
    {
        Rectangle r{{0, 0}, 0, {5, 2}};
        CHECK_THAT(r.center(), Equals({0, 0}));
        CHECK_THAT(r.forwardUnitVector(), Equals({1, 0}));
        CHECK_THAT(r.topLeft(), Equals({1, 2.5}));
        CHECK_THAT(r.topRight(), Equals({1, -2.5}));
    }

    SECTION("a 90° orientation rectangle (facing up)")
    {
        const double pi = std::acos(-1);
        Rectangle r{{0, 0}, pi / 2, {5, 2}};
        CHECK_THAT(r.center(), Equals({0, 0}));
        CHECK_THAT(r.forwardUnitVector(), Equals({0, 1}));
        CHECK_THAT(r.topLeft(), Equals({-2.5, 1}));
        CHECK_THAT(r.topRight(), Equals({2.5, 1}));
    }

    SECTION("Rectangle::contains of a zero orientation rectangle (facing right)")
    {
        Rectangle r{{0, 0}, 0, {5, 2}};

        // corners
        CHECK(r.contains({0., 0.}));
        CHECK(r.contains({1., 2.5}));
        CHECK(r.contains({1., -2.5}));
        CHECK(r.contains({-1., -2.5}));
        CHECK(r.contains({-1., 2.5}));

        CHECK(r.contains({0.5, -1.}));
        CHECK(r.contains({0.5, 1.}));
        CHECK(r.contains({-0.5, -1.}));
        CHECK(r.contains({-0.5, 1.}));
    }
}

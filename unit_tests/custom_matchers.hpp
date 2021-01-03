#pragma once

#include "point.hpp"

#include <catch2/catch.hpp>

namespace QWarhammerSimulator::Testing
{

namespace PointMatcher
{
    using QWarhammerSimulator::LibGeometry::Point;

    struct EqualsMatcher : Catch::Matchers::Impl::MatcherBase<Point>
    {
        EqualsMatcher(const Point& ref, const double epsilon);

        bool match(const Point& other) const;

        std::string describe() const override;

    private:
        const Point& m_ref;
        const double m_epsilon;

        bool approx(const double d1, const double d2) const;
    };

    EqualsMatcher Equals(const Point& ref, const double epsilon = 1E-3);

} // namespace PointMatcher

} // namespace QWarhammerSimulator::Testing

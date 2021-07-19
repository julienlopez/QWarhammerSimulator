#include <catch2/catch.hpp>

#include "unit.hpp"

#include "custom_matchers.hpp"

using QWarhammerSimulator::LibWarhammerEngine::Characteristics;
using QWarhammerSimulator::LibWarhammerEngine::Model;
using QWarhammerSimulator::LibWarhammerEngine::Unit;

using QWarhammerSimulator::LibGeometry::Point;
using QWarhammerSimulator::LibGeometry::Rectangle;

Model empire_halberdier{"empire halberdier", Point{1, 1}, Characteristics{4, 3, 3, 3, 3, 1, 3, 1, 7}};

namespace
{
std::vector<Point> listVertices(const Rectangle& rect)
{
    return {rect.topLeft(), rect.topRight(), rect.bottomRight(), rect.bottomLeft()};
}

} // namespace

TEST_CASE("Basic Unit Management", "[LibWarhammerEngine]")
{

    SECTION("Basic unit creation and size")
    {
        const Unit halberdier_unit_20{empire_halberdier, 20, 5, {10., 5.}};
        CHECK(halberdier_unit_20.rectangle().width() == 5);
        CHECK(halberdier_unit_20.rectangle().height() == 4);

        const Unit halberdier_unit_16{empire_halberdier, 16, 5, {10., 5.}};
        CHECK(halberdier_unit_16.rectangle().width() == 5);
        CHECK(halberdier_unit_16.rectangle().height() == 4);

        const Unit halberdier_unit_15{empire_halberdier, 15, 5, {10., 5.}};
        CHECK(halberdier_unit_15.rectangle().width() == 5);
        CHECK(halberdier_unit_15.rectangle().height() == 3);
    }
}

SCENARIO("Removing a model updates the rectangle appropriately")
{

    GIVEN("a 16 models unit on 5 columns")
    {
        Unit halberdier_unit{empire_halberdier, 16, 5, {10., 5.}};
        CHECK(halberdier_unit.numberOfModels() == 16);
        CHECK(halberdier_unit.rectangle().width() == 5);
        CHECK(halberdier_unit.rectangle().height() == 4);

        const auto orignal_front_left = halberdier_unit.rectangle().topLeft();
        const auto orignal_front_right = halberdier_unit.rectangle().topRight();

        WHEN("removing a model")
        {
            halberdier_unit.removeModels(1);

            THEN("The rectangle should be updated properly")
            {
                CHECK(halberdier_unit.numberOfModels() == 15);
                CHECK(halberdier_unit.rectangle().width() == 5);
                CHECK(halberdier_unit.rectangle().height() == 3);

                using QWarhammerSimulator::Testing::PointMatcher::Equals;
                CHECK_THAT(halberdier_unit.rectangle().topLeft(), Equals(orignal_front_left));
                CHECK_THAT(halberdier_unit.rectangle().topRight(), Equals(orignal_front_right));
            }
        }
    }
}

TEST_CASE("Unit Model rectangle", "[LibWarhammerEngine]")
{

    SECTION("Basic unit creation and size")
    {
        const Unit unit{empire_halberdier, 20, 5, {10., 5.}};
        CHECK_THAT(listVertices(unit.rectangle()),
                   Catch::Matchers::UnorderedEquals<Point>({{8., 7.5}, {8., 2.5}, {12., 7.5}, {12., 2.5}}));

        CHECK_THAT(listVertices(unit.modelRectangle(0)),
                   Catch::Matchers::UnorderedEquals<Point>({{11., 7.5}, {11., 6.5}, {12., 7.5}, {12., 6.5}}));
        CHECK_THAT(listVertices(unit.modelRectangle(1)),
                   Catch::Matchers::UnorderedEquals<Point>({{11., 6.5}, {11., 5.5}, {12., 6.5}, {12., 5.5}}));
        CHECK_THAT(listVertices(unit.modelRectangle(2)),
                   Catch::Matchers::UnorderedEquals<Point>({{11., 5.5}, {11., 4.5}, {12., 5.5}, {12., 4.5}}));
        CHECK_THAT(listVertices(unit.modelRectangle(4)),
                   Catch::Matchers::UnorderedEquals<Point>({{11., 3.5}, {11., 2.5}, {12., 3.5}, {12., 2.5}}));

        CHECK_THAT(listVertices(unit.modelRectangle(5)),
                   Catch::Matchers::UnorderedEquals<Point>({{10., 7.5}, {10., 6.5}, {11., 7.5}, {11., 6.5}}));
        CHECK_THAT(listVertices(unit.modelRectangle(9)),
                   Catch::Matchers::UnorderedEquals<Point>({{10., 3.5}, {10., 2.5}, {11., 3.5}, {11., 2.5}}));

        CHECK_THAT(listVertices(unit.modelRectangle(15)),
                   Catch::Matchers::UnorderedEquals<Point>({{8., 7.5}, {8., 6.5}, {9., 7.5}, {9., 6.5}}));
        CHECK_THAT(listVertices(unit.modelRectangle(19)),
                   Catch::Matchers::UnorderedEquals<Point>({{8., 3.5}, {8., 2.5}, {9., 3.5}, {9., 2.5}}));
    }
}

#include <catch2/catch.hpp>

#include "unit.hpp"

#include "custom_matchers.hpp"

using QWarhammerSimulator::LibWarhammerEngine::Characteristics;
using QWarhammerSimulator::LibWarhammerEngine::Model;
using QWarhammerSimulator::LibWarhammerEngine::Unit;

using QWarhammerSimulator::LibGeometry::Point;

Model empire_halberdier{"empire halberdier", Point{1, 1}, Characteristics{4, 3, 3, 3, 3, 1, 3, 1, 7}};

TEST_CASE("Basic Unit Management", "[LibWarhammerEngine]")
{

    SECTION("Basic unit creation and size")
    {
        const Unit halberdier_unit_20{empire_halberdier, 20, 5};
        CHECK(halberdier_unit_20.rectangle().width() == 5);
        CHECK(halberdier_unit_20.rectangle().height() == 4);

        const Unit halberdier_unit_16{empire_halberdier, 16, 5};
        CHECK(halberdier_unit_16.rectangle().width() == 5);
        CHECK(halberdier_unit_16.rectangle().height() == 4);

        const Unit halberdier_unit_15{empire_halberdier, 15, 5};
        CHECK(halberdier_unit_15.rectangle().width() == 5);
        CHECK(halberdier_unit_15.rectangle().height() == 3);
    }
}

SCENARIO("Removing a model updates the rectangle appropriately")
{

    GIVEN("a 16 models unit on 5 columns")
    {
        Unit halberdier_unit{empire_halberdier, 16, 5};
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

#include <catch2/catch.hpp>

#include "unit.hpp"

using QWarhammerSimulator::LibWarhammerEngine::Characteristics;
using QWarhammerSimulator::LibWarhammerEngine::Model;
using QWarhammerSimulator::LibWarhammerEngine::Unit;

using QWarhammerSimulator::LibGeometry::Point;

TEST_CASE("Basic Unit Management", "[LibWarhammerEngine]")
{

	SECTION("")
    {
        Model empire_halberdier{"empire halberdier", Point{1, 1}, Characteristics{4, 3, 3, 3, 3, 1, 3, 1, 7}};
        Unit halberdier_unit_20{empire_halberdier, 20, 5};
        CHECK(halberdier_unit_20.rectangle().width() == 5);
        CHECK(halberdier_unit_20.rectangle().height() == 4);

        Unit halberdier_unit_16{empire_halberdier, 16, 5};
        CHECK(halberdier_unit_16.rectangle().width() == 5);
        CHECK(halberdier_unit_16.rectangle().height() == 4);

        Unit halberdier_unit_15{empire_halberdier, 15, 5};
        CHECK(halberdier_unit_15.rectangle().width() == 5);
        CHECK(halberdier_unit_15.rectangle().height() == 3);
    }

}

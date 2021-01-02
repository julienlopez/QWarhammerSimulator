#include <catch2/catch.hpp>

#include "unit.hpp"

using QWarhammerSimulator::LibWarhammerEngine::Characteristics;
using QWarhammerSimulator::LibWarhammerEngine::Model;
using QWarhammerSimulator::LibWarhammerEngine::Unit;

using QWarhammerSimulator::LibGeometry::Point;

TEST_CASE("Basic Unit Management")
{

	SECTION("")
    {
        Model empire_halberdier{"empire halberdier", Point{1, 1}, Characteristics{4, 3, 3, 3, 3, 1, 3, 1, 7}};
        Unit halberdier_unit{empire_halberdier, 20, 5};
        CHECK(halberdier_unit.rectangle().width() == 5);
        CHECK(halberdier_unit.rectangle().height() == 4);
    }

}

#pragma once

#include "characteristics.hpp"

#include "point.hpp"

#include <string>

namespace QWarhammerSimulator::LibWarhammerEngine
{

struct Model
{
    std::string name;
    LibGeometry::Point base_size;
    Characteristics characteristics;
};

} // namespace QWarhammerSimulator::LibWarhammerEngine

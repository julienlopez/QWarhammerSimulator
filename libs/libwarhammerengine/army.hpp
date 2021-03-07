#pragma once

#include "unit.hpp"

#include <vector>

namespace QWarhammerSimulator::LibWarhammerEngine
{

class Army
{
public:
// private:
    std::string name;
    std::vector<Unit> m_units;
};

} // namespace QWarhammerSimulator::LibWarhammerEngine

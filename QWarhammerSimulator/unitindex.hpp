#pragma once

#include <utility>

namespace QWarhammerSimulator::Gui
{

struct UnitIndex
{
    UnitIndex(const std::size_t player_index_, const std::size_t unit_index_)
        : player_index{player_index_}
        , unit_index{unit_index_}
    {
    }

    std::size_t player_index;
    std::size_t unit_index;
};

} // namespace QWarhammerSimulator::Gui

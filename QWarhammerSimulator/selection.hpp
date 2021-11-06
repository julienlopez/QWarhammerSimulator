#pragma once

#include <vector>

namespace QWarhammerSimulator::Gui
{

struct Selection
{
    Selection(std::size_t unit_index_, std::vector<std::size_t> models_ = {})
        : unit_index{unit_index_}
        , models{std::move(models_)}
    {
    }

    std::size_t unit_index;
    std::vector<std::size_t> models;
};

} // namespace QWarhammerSimulator::Gui

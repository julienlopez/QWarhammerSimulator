#pragma once

#include "unitindex.hpp"

#include <vector>

#include <QColor>

namespace QWarhammerSimulator::Gui
{

struct Selection
{
    Selection(const UnitIndex& unit_index_, std::vector<std::size_t> models_ = {})
        : unit_index{unit_index_}
        , models{std::move(models_)}
    {
    }

    UnitIndex unit_index;
    std::vector<std::size_t> models;
};

struct SelectionWithColor
{
    Selection selection;
    QColor color;
    double width = 1.0;
};

} // namespace QWarhammerSimulator::Gui
